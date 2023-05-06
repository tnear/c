/*
BIT FIELD

Define the number of bits for each field of a struct.
*/

#include <assert.h>
#include <stdio.h>

struct BitField
{
    unsigned int field1 : 1;
    unsigned int field2 : 1;
    unsigned int field3 : 1;
    unsigned int field4 : 1;
    unsigned int field5 : 1;
} __attribute__((packed));

void bitfield()
{
    // 5 fields * 1 bit per field = 5 bits
    // Total size is 8 bits (1 byte) due to 1 byte being minimum
    assert(sizeof(struct BitField) == 1);

    // Create instance and set fields
    struct BitField b = {};
    b.field1 = 0;
    b.field2 = 1;
    b.field3 = 0;
    b.field4 = 1;
    b.field5 = 1;

    assert(b.field1 == 0);
    assert(b.field2 == 1);
    assert(b.field3 == 0);
    assert(b.field4 == 1);
    assert(b.field5 == 1);
}

int main()
{
    bitfield();

    printf(__FILE__ " tests passed!\n");
    return 0;
}
