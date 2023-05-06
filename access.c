/*
ACCESS

access - check user's permissions for a file

#include <unistd.h>

int access(const char *pathname, int mode);
*/

#include <assert.h>
#include <stdio.h>
#include <unistd.h>

void fileExists()
{
    char filename[] = "access_data.txt";
    // Verify file does not exist
    assert(access(filename, F_OK) != 0);

    // Create a file for writing
    FILE *fp = fopen(filename, "w");
    fclose(fp);

    // Verify file exists
    assert(access(filename, F_OK) == 0);

    // Verify file doesn't exist
    remove(filename);
    assert(access(filename, F_OK) != 0);
}

int main()
{
    fileExists();

    printf("Tests passed!\n");
    return 0;
}
