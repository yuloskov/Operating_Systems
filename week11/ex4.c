#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>

int main () {
    int fptr1 = open("ex1.txt", O_RDWR);
    int fptr2 = open("ex1.memcpy.txt", O_RDWR);
    struct stat *buf = malloc(sizeof(struct stat));
    fstat(fptr1, buf);
    int len = buf->st_size;
    char *str = mmap(NULL, len, PROT_WRITE | PROT_READ, MAP_SHARED, fptr1, 0);
    char *str2 = mmap(NULL, len, PROT_WRITE | PROT_READ, MAP_SHARED, fptr2, 0);
    ftruncate(fptr2, len);
    memcpy(str2, str, len);
    close(fptr1);
    close(fptr2);
    free(buf);
    return 0;
}   