/*
MMAP

mmap, munmap - map or unmap files or devices into memory

void *mmap(void *addr, size_t length, int prot, int flags,
                  int fd, off_t offset);

int munmap(void *addr, size_t length);

*/

#include <assert.h>
#include <stdio.h>
#include <sys/mman.h>

void anonymous()
{
    const int N = 5;
    void *addr = NULL; // NULL address means place memory anywhere (page-aligned)
    size_t bytesOfData = N * sizeof(int);
    int protection = PROT_READ | PROT_WRITE; // Will be reading and writing data

    // flags are ANON b/c this is not file-backed and PRIVATE b/c it is local to this process
    int flags = MAP_ANONYMOUS | MAP_PRIVATE;
    int fd = -1; // file descriptor unused for anonymous data
    int offset = 0; // offset should be zero for anonymous data

    int *ptr = mmap(addr, bytesOfData, protection, flags, fd, offset);
    assert(ptr != MAP_FAILED);

    // Fill in array
    for (int i = 0; i < N; ++i)
        ptr[i] = i + 1;

    // Verify values
    for (int i = 0; i < N; ++i)
        assert(ptr[i] == i + 1);

    // munmap deletes mappings for specified address range
    int err = munmap(ptr, bytesOfData);
    assert(err == 0);
}

void file()
{
    // https://linuxhint.com/using_mmap_function_linux/
}

int main()
{
    anonymous();
    file();

    return 0;
}
