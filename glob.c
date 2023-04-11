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
#include <stdio.h>

void globBasic()
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

int main()
{
    globBasic();
    printf("Tests passed!\n");
    return 0;
}
