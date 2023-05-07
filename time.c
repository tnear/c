/*
TIME

time - get time in seconds

time()  returns the time as the number of seconds since the Epoch, 1970-01-01

#include <time.h>
time_t time(time_t *tloc);
*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void getTime()
{
    // 1683474909 = May 7th, 2023
    time_t currentTime = time(NULL);
    assert(currentTime > 1683474909 && currentTime < 2000000000);
}

int main()
{
    getTime();

    printf(__FILE__ " tests passed!\n");
    return 0;
}
