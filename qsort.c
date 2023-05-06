/*
QSORT

qsort, qsort_r - sort an array

void qsort(void *base, size_t numel, size_t sizeOfElemInBytes,
                  int (*compar)(const void *, const void *));

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int CompareIntFcn(const void *left, const void *right)
{
    return *(int *)left - *(int *)right;
}

void compareInt()
{
    const int numElements = 5;
    int values[] = {5, 1, 3, 2, 4};

    qsort(values, numElements, sizeof(int), CompareIntFcn);

    assert(sizeof values / sizeof values[0] == numElements);
    assert(values[0] == 1);
    assert(values[1] == 2);
    assert(values[2] == 3);
    assert(values[3] == 4);
    assert(values[4] == 5);
}

int main()
{
    compareInt();
    printf(__FILE__ " tests passed!\n");
    return 0;
}
