/*
ACCESS

access - check user's permissions for a file

#include <unistd.h>
int access(const char *pathname, int mode);
*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>

static bool isFile(const char *pathname)
{
    return access(pathname, F_OK) == 0;
}   

void fileExists()
{
    char filename[] = "access_data.txt";
    // Verify file does not exist
    assert(!isFile(filename));

    // Create a file for writing
    FILE *fp = fopen(filename, "w");
    fclose(fp);

    // Verify file exists
    assert(isFile(filename));

    // Verify file doesn't exist
    remove(filename);
    assert(!isFile(filename));
}

int main()
{
    fileExists();

    printf(__FILE__ " tests passed!\n");
    return 0;
}
