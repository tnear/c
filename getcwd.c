/*
GETCWD

getcwd - get current working directory

#include <unistd.h>
char *getcwd(char *buf, size_t size);
*/

#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

void pwd()
{
    char pwd[PATH_MAX];
    getcwd(pwd, sizeof(pwd));

    assert(strcmp(pwd, "/home/kali/c") == 0);
}

int main()
{
    pwd();

    printf(__FILE__ " tests passed!\n");
    return 0;
}
