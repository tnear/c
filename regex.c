/*
REGEX

regcomp, regexec, regerror, regfree - POSIX regex functions

Syntax:
#include <regex.h>

int regcomp(regex_t *restrict regex, const char *restrict regex,
            int cflags);
int regexec(const regex_t *restrict regex, const char *restrict string,
            size_t nmatch, regmatch_t pmatch[restrict], int eflags);

size_t regerror(int errcode, const regex_t *restrict regex,
            char *restrict errbuf, size_t errbuf_size);
void regfree(regex_t *regex);
*/

#include <assert.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *substring(char *string, int position, int length);

void basic()
{
    // Compile regex pattern
    regex_t regex;
    int flags = REG_EXTENDED; // Extended needed for '+' in [0-9]+
    int ret = regcomp(&regex, "pat[0-9]+tern", flags);
    assert(ret == REG_NOERROR); // assert regcomp compilation successful

    // Matching string (one digit)
    ret = regexec(&regex, "my pat6tern", 0, NULL, 0);
    assert(ret == REG_NOERROR);

    // Matching string (multiple digits)
    ret = regexec(&regex, "my pat123456tern", 0, NULL, 0);
    assert(ret == REG_NOERROR);

    // Failing string (no digit)
    ret = regexec(&regex, "my pattern", 0, NULL, 0);
    assert(ret == REG_NOMATCH);

    // Free regex's memory when done
    regfree(&regex);
}

// https://stackoverflow.com/questions/2577193/how-do-you-capture-a-group-with-regex
void capture()
{
    char source[] = "___ abc123def ghi456";
    char regexString[] = "[a-z]*([0-9]+)([a-z]*)";
    size_t maxGroups = 3;

    regex_t regex;
    regmatch_t groupArray[maxGroups];

    int ret = regcomp(&regex, regexString, REG_EXTENDED);
    assert(ret == REG_NOERROR);

    ret = regexec(&regex, source, maxGroups, groupArray, 0);
    assert(ret == REG_NOERROR);

    // The first string ("abc123def") is the whole match.
    // The second and third strings are the capture groups.
    char *expStr[] = {"abc123def", "123", "def"};

    for (size_t i = 0; i < maxGroups; ++i)
    {
        char sourceCopy[strlen(source) + 1];
        strcpy(sourceCopy, source);
        sourceCopy[groupArray[i].rm_eo] = 0; // Add null byte

        // Get matching substring from source string
        int len = groupArray[i].rm_eo - groupArray[i].rm_so;
        char *sub = substring(source, groupArray[i].rm_so + 1, len);

        // Verify data matches
        assert(strcmp(sub, expStr[i]) == 0);
        free(sub);

        // Diagnostics
        printf("Group %lu: [%2u-%2u]: %s\n",
                i, groupArray[i].rm_so, groupArray[i].rm_eo,
                sourceCopy + groupArray[i].rm_so);
    }

    regfree(&regex);
}

// Utility function to return a substring.
// Return value must be freed.
char *substring(char *string, int position, int length)
{
    // Length+1 to make room for null byte
    char *p = malloc(length+1);

    // Copy one character at a time up to length
    int c = 0;
    for (c = 0; c < length; c++)
    {
        *(p+c) = *(string+position-1);
        string++;
    }

    *(p+c) = 0; // Null byte at end

    return p;
}

void backreference()
{
    regex_t regex;
    // Pattern to check duplicated words using backreference (\1)
    // (\w+) \1
    char pattern[] = "(\\w+) \\1";
    int ret = regcomp(&regex, pattern, REG_EXTENDED);
    assert(ret == REG_NOERROR);

    // Duplicate word hello
    ret = regexec(&regex, "hello hello", 0, NULL, 0);
    assert(ret == REG_NOERROR);

    // Another duplicate ("a")
    ret = regexec(&regex, "test a a test", 0, NULL, 0);
    assert(ret == REG_NOERROR);

    // No consecutive duplicates
    ret = regexec(&regex, "hello world hello", 0, NULL, 0);
    assert(ret == REG_NOMATCH);
}

// https://www.ibm.com/docs/en/zos/2.3.0?topic=functions-regerror-return-error-message
void regerrorTest()
{
    regex_t regex;
    // Create an invalid pattern (missing bracket)
    char pattern[] = "a[missing.bracket";

    int ret = regcomp(&regex, pattern, REG_EXTENDED);
    assert(ret == REG_EBRACK);

    // regerror returns error message (in buffer variable) for regex
    char buffer[100];
    regerror(ret, &regex, buffer, 100);

    // Verify return error text
    assert(strcmp(buffer, "Unmatched [, [^, [:, [., or [=") == 0);
}

int main()
{
    basic();
    capture();
    backreference();
    regerrorTest();

    printf(__FILE__ " tests passed!\n");
    return 0;
}
