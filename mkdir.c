/*
MKDIR

mkdir - create a directory

#include <sys/stat.h>
int mkdir(const char *pathname, mode_t mode);

#include <unistd.h>
int rmdir(const char *pathname);
*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

void makeDirectory()
{
    // create new directory
    char dir[] = "mnt";
    unsigned mode = 0700;
    int ret = mkdir(dir, mode);
    assert(ret == 0);

    // cleanup using rmdir
    ret = rmdir(dir);
    assert(ret == 0);
}

int main()
{
    makeDirectory();

    printf(__FILE__ " tests passed!\n");
    return 0;
}
