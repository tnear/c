/*
CALLOC

calloc - allocate memory and initialize to zero

Syntax:
#include <stdlib.h>
void* calloc(size_t nmemb, size_t size);
*/

#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

void callocBasic()
{
    // Allocate 3 integers on heap and initialize to zero
    const int numInt = 3;
    int *pInt = calloc(numInt, sizeof(int));

    assert(pInt[0] == 0);
    assert(pInt[1] == 0);
    assert(pInt[2] == 0);

    // Free memory when done
    free(pInt);
}

int main()
{
    callocBasic();
    printf("Tests passed!\n");
    return 0;
}
