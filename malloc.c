/*
MALLOC

malloc - memory allocation - allocate and free dynamic memory

Syntax:
#include <stdlib.h>
void* malloc(size_t size);
void free(void *ptr);
*/

#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

void mallocBasic()
{
    // Allocate 5 integers on heap
    const int numInt = 5;
    int *pInt = malloc(numInt * sizeof(int));

    pInt[4] = 4;
    assert(pInt[4] == 4);

    printf("Heap memory address: %p\n", pInt);
    printf("Stack memory address: %p\n", &numInt);

    // Stack has higher memory addresses
    assert(&numInt > pInt);

    // Free memory when done
    free(pInt);
}

void mallocFail()
{
    // malloc can fail when requesting more memory than is available
    // (2 ^ 64) - 1 = 9223372036854775807
    char *pChar = malloc(9223372036854775807);

    assert(!pChar);

    // free is safe on NULL pointers
    free(pChar);
}

int main()
{
    mallocBasic();
    mallocFail();
    printf(__FILE__ " tests passed!\n");
    return 0;
}
