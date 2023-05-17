/*
STRCHR

strchr, strrchr, strchrnul - locate character in string

strchr() returns a pointer to the first occurrence of the character c in the string s.

#include <string.h>
char* strchr(const char *s, int c);
*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void getChar()
{
    // strchr(): return first occurrence of '.'
    char str[] = "Test string. Test two. Test again";
    char *location = strchr(str, '.');
    assert(location == str + 11);
}

void getCharReverse()
{
    // strrchr(): return LAST occurrence of '.'
    char str[] = "Test string. Test two. Test again";
    char *location = strrchr(str, '.');
    assert(location == str + 21);
}

void notFound()
{
    char str[] = "abc";
    char *location = strchr(str, 'd');
    assert(!location);
}

int main()
{
    getChar();
    getCharReverse();
    notFound();

    printf(__FILE__ " tests passed!\n");
    return 0;
}
