/*
GLOB

glob, globfree - find pathnames matching a pattern, free memory from glob()

glob finds basic patterns in filenames. 'glob' is short for global.

Syntax:
int glob(const char *restrict pattern, int flags,
                int (*errfunc)(const char *epath, int eerrno),
                glob_t *restrict pglob);
void globfree(glob_t *pglob);
*/

#include <assert.h>
#include <glob.h>
#include <string.h>
#include <stdio.h>

// Example for '*'
void star()
{
    // Return value structure
    glob_t pglob;

    // Find all .c files in pwd. Results are returned in 'pglob'
    int result = glob("*.c", GLOB_ERR, NULL, &pglob);
    assert(result == 0);
    
    // gl_pathv contains list of matched pathnames
    char **found = pglob.gl_pathv;
    assert(found);

    // Iterate through all results
    printf(".c files found: ");
    while (*found)
    {
        printf("%s ", *found);
        ++found;
    }

    printf("\n");

    // Free dynamic memory when done
    globfree(&pglob);
}

// Example for '?'
void question()
{
    glob_t pglob;

    // Find all 4-letter file names plus c extension
    int result = glob("????.c", GLOB_ERR, NULL, &pglob);
    assert(result == 0);
    
    char **found = pglob.gl_pathv;
    assert(found);

    // Iterate through all results
    printf("Length 4 files found: ");
    while (*found)
    {
        // in form of "????.c", so 6 characters
        assert(strlen(*found) == 6);
        printf("%s ", *found);
        ++found;
    }

    printf("\n");
}

// Example for [...]
void bracket()
{
        glob_t pglob;

    // Find all .c file starting with a, b, or c
    int result = glob("[a-c]*.c", GLOB_ERR, NULL, &pglob);
    assert(result == 0);
    
    char **found = pglob.gl_pathv;
    assert(found);

    printf("Files beginning with a, b, or c: ");
    while (*found)
    {
        assert(*found[0] >= 'a' && *found[0] <= 'c');
        printf("%s ", *found);
        ++found;
    }

    printf("\n");
}

int main()
{
    star();
    question();
    bracket();

    printf("Tests passed!\n");
    return 0;
}
