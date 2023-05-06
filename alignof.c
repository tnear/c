/*
ALIGNOF

alignof operator: Queries the alignment requirement of its operand type.

Syntax:
#include <stdalign.h>
result = alignof(<type>)
*/

#include <assert.h>
#include <stdalign.h>
#include <stdio.h>

struct BitField
{
    unsigned int field1 : 1;
    unsigned int field2 : 1;
} __attribute__((packed));

void alignofBasic()
{
    assert(alignof(char) == 1);
    assert(alignof(int) == 4);
    assert(alignof(float*) == 8);
    assert(alignof(struct BitField) == 1);
}

int main()
{
    alignofBasic();

    printf(__FILE__ " tests passed!\n");
    return 0;
}
