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
    assert(fileno(fp) > 0);
    char buf[255] = {};
    fread(buf, 255, 1, fp);

    // Verify file data is same
    assert(strcmp(buf, data) == 0);

    // Delete file when done
    remove(filename);

    fclose(fp);
}

int main()
{
    fopenBasic();

    printf("Tests passed!\n");
    return 0;
}
