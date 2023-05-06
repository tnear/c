/*
CURL

curl - transfer a URL

Build:
gcc curl.c -lcurl -o curl.o

Include:
#include <curl/curl.h>
*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <curl/curl.h>

char FILENAME[] = "file.html";

void downloadURL(char *url)
{
    // open file for writing
    FILE *file = fopen(FILENAME, "w");
    assert(file);

    // initialize curl
    CURL *curl = curl_easy_init();
    assert(curl);

    // set URL to download
    curl_easy_setopt(curl, CURLOPT_URL, url);

    // set file handle for output
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, file);

    // perform the download
    CURLcode res = curl_easy_perform(curl);

    // check for errors
    if (res != CURLE_OK)
    {
        printf("curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
    }

    // cleanup curl
    curl_easy_cleanup(curl);

    // close file handle
    fclose(file);
}

int main()
{
    downloadURL("http://example.com");

    FILE *fp = fopen(FILENAME, "r");
    char buf[255] = {};
    fread(buf, 255, 1, fp);

    // Verify substring
    assert(strstr(buf, "doctype") != 0);

    // Delete file
    remove(FILENAME);

    printf(__FILE__ " tests passed!\n");
    return 0;
}
