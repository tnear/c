/*
UNION

A union stores all fields starting at the same memory address.
The memory is the size of the largest field.
*/

#include <assert.h>
#include <stdio.h>

union myUnion
{
    int a;
    char b;
} myUnion;

void unionBasic()
{
    union myUnion u, u2;
    u.a = 1;
    // u.b = 'a'; <-- not okay because have already used 'a'

    u2.b = 'a';
    // u2.a = 1; <-- not okay. Must only modify one field of union

    assert(u.a == 1);
    assert(u2.b == 'a');

    // Union size equals largest of {int, char} which is int (4 bytes)
    assert(sizeof(int) == 4);
    assert(sizeof(u) == 4);
}

int main()
{
    unionBasic();
    printf("Tests passed!\n");
    return 0;
}
