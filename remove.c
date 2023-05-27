/*
REMOVE

remove - remove a file or directory

#include <stdio.h>
int remove(const char *pathname);
*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>

static bool isFile(const char *pathname)
{
    return access(pathname, F_OK) == 0;
}

void testRemoveFile()
{
    char filename[] = "remove_example.txt";
    // Verify file does not exist
    assert(!isFile(filename));

    // remove on non-existent file returns -1
    int ret = remove(filename);
    assert(ret == -1);

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
    testRemoveFile();

    printf(__FILE__ " tests passed!\n");
    return 0;
}
