/*
OPEN

open, openat, creat - open and possibly create a file

Syntax:
#include <fcntl.h>
int open(const char *pathname, int flags);
*/

#include <assert.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

void openExample()
{
    char *filename = "my_open.txt";
    char *content = "Open data!";

    // Create file and open for reading (truncate if it exists)
    int flags = O_CREAT | O_RDWR | O_TRUNC;
    int fd = open(filename, flags);

    // Write content to file
    int bytesWritten = write(fd, content, strlen(content));
    assert(bytesWritten == strlen(content));

    // Seek to front of file to prepare for reading
    lseek(fd, 0, SEEK_SET);

    // Read new file's data and verify contents
    char buffer[100];
    int bytesRead = read(fd, buffer, sizeof(buffer));

    assert(bytesRead == strlen(content));
    assert(strncmp(buffer, content, bytesRead) == 0);

    // Close file when done
    close(fd);

    // Remove file from filesystem
    remove(filename);
}

int main()
{
    openExample();

    printf(__FILE__ " tests passed!\n");
    return 0;
}
