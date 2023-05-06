/*
STRCPY

strcpy, strncpy - copy a string

Syntax:
#include <string.h>
char* strcpy(char *dest, const char *src);
*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

void copy()
{
    char str[] = "My string\n";
    // Destination must be large enough to store the copied string
    char dest[128];

    // Copy string and verify they are equal
    strcpy(dest, str);
    assert(strcmp(dest, str) == 0);
}

void overwrite()
{
    char str[] = "Overwrite test\n";
    char dest[25] = "Hello!";

    // strcpy overwrites dest (NOT append). Use strcat to append.
    strcpy(dest, str);

    // There should be no trace of "Hello!" left
    assert(strcmp(dest, str) == 0);
}

int main()
{
    copy();
    overwrite();

    printf(__FILE__ " tests passed!\n");
    return 0;
}
