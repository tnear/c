/*
GETPAGESIZE

getpagesize - get memory page size

#include <unistd.h>
int getpagesize(void);
*/

#include <assert.h>
#include <stdio.h>
#include <unistd.h>

static void testGetPageSize()
{
    const int pageSize = getpagesize();
    assert(pageSize == 4096);
}

int main()
{
    testGetPageSize();

    printf(__FILE__ " tests passed!\n");
    return 0;
}
