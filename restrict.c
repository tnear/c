/*
RESTRICT

restrict keyword: hint to compiler that nothing else can access
the object being pointed to. Permits compiler to optimize more
aggressively.
*/

#include <assert.h>
#include <stdio.h>

// Add val to both a and b
void addWithRestrict(int * restrict a, int * restrict b, int *val)
{
    *a += *val;
    *b += *val;
}

void add()
{
    int a = 2;
    int b = 3;
    int val = 5;

    // Add 5 to a=2 and b=3
    addWithRestrict(&a, &b, &val);

    // Verify new value
    assert(a == 7);
    assert(b == 8);
}

int main()
{
    add();

    printf("Tests passed!\n");
    return 0;
}
