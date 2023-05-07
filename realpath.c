/*
REALPATH

realpath - return the canonicalized absolute pathname

#include <limits.h>
#include <stdlib.h>
char *realpath(const char *path, char *resolved_path);
*/

#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void absolutePath()
{
    // create new file
    char filename[] = "mydata.txt";
    FILE *fp = fopen(filename, "w");
    fclose(fp);

    // get absolute path of newly created file
    char *absPath = realpath(filename, NULL);
    assert(strcmp(absPath, "/home/kali/c/mydata.txt") == 0);

    // cleanup
    free(absPath);
    remove(filename);
}

int main()
{
    absolutePath();

    printf(__FILE__ " tests passed!\n");
    return 0;
}
