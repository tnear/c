/*
STRSTR

strstr, strcasestr - locate a substring

Returns pointer to the first occurrence in haystack.

#include <string.h>
char *strstr(const char *haystack, const char *needle);
*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

void substr()
{
    const char haystack[] = "My long string example";

    // Invalid substring (NULL return)
    const char notFound[] = "not found";
    char *ret = strstr(haystack, notFound);
    assert(!ret);

    // Valid substring (returns pointer to 1st occurrence)
    const char needle[] = "string";
    ret = strstr(haystack, needle);
    assert(ret);

    // Verify ret points to letter 's' in haystack
    // ('s' = 8th char of haystack):
    assert(ret == haystack + 8);
}

int main()
{
    substr();

    printf(__FILE__ " tests passed!\n");
    return 0;
}
