/*
FOPEN

fopen - stream open functions

Syntax:
#include <stdio.h>
FILE *fopen(const char *restrict pathname, const char *restrict mode);
*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

void fopenBasic()
{
    // Create a file for writing
    char filename[] = "mydata.txt";
    FILE *fp = fopen(filename, "w");

    // Write data
    char data[] = "Test data...";
    fputs(data, fp);
    fclose(fp);

    // Read data back
    fp = fopen(filename, "r");
    char buf[255] = {};
    int ret = strcmp(buf, data);
    assert(ret != 0);
    fread(buf, 255, 1, fp);

    // Verify file data is same
    ret = strcmp(buf, data);
    assert(ret == 0);

    // Delete file when done
    remove(filename);
}

int main()
{
    fopenBasic();

    printf("Tests passed!\n");
    return 0;
}
