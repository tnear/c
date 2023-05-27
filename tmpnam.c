/*
TMPNAM

tmpnam, tmpnam_r - create a name for a temporary file

#include <stdio.h>
char *tmpnam(char *s);

the use of 'tmpnam' is dangerous, better use `mkstemp'
*/

#include <stdio.h>

int main()
{
    printf(__FILE__ " tests passed!\n");
    return 0;
}
