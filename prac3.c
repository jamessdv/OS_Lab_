#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <string.h>

int main() 
{
    int fd;
    char *map;
    const char *message = "Hello Linux Memory Management\n";
    size_t length = strlen(message);

    // Open or create a file
    fd = open("testfile.txt", O_RDWR | O_CREAT, 0666);

    // Set file size
    ftruncate(fd, length);

    // Map file into memory
    map = (char *)mmap(NULL, length, PROT_READ | PROT_WRITE,
                       MAP_SHARED, fd, 0);

    // Write to mapped memory
    memcpy(map, message, length);

    printf("Data written using mmap\n");

    // Unmap memory
    munmap(map, length);

    printf("Memory unmapped successfully\n");

    // Close file
    close(fd);

    return 0;
}