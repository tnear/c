/*
ALLOCA

alloca - allocate (stack) memory that is automatically freed

Syntax:
#include <alloca.h>
void *alloca(size_t size);
*/

#include <alloca.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void allocaBasic()
{
    // Allocate three ints worth of memory on heap using alloca.
    // This memory is automatically freed.
    int *a = alloca(3 * sizeof(int));
    a[0] = 1;
    a[1] = 2;
    a[2] = 3;
    assert(a[0] == 1);
    assert(a[1] == 2);
    assert(a[2] == 3);

    // Create static stack memory
    int s = 0;
    // Create dynamic memory
    int *m = malloc(2 * sizeof(int));

    // alloca memory (stack) has higher addresses than heap
    assert(a > m);

    // alloca and local variable memory addresses should be close
    assert((a - &s) < 100);

    printf("alloc: %p\n", a);
    printf("stack: %p\n", &s);
    printf(" heap: %p\n", m);

    // Must free malloc memory but NOT alloca memory:
    free(m);
}

int main()
{
    allocaBasic();

    printf(__FILE__ " tests passed!\n");
    return 0;
}
