#include <fcntl.h>
#include <sys/mman.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

size_t sfile(char const filename[]);

int main(){
     int fptr = open("./ex1.txt", O_RDWR);
    char *string = "This is a nice day";
    char *str = mmap(NULL, strlen(string), PROT_WRITE | PROT_READ, MAP_SHARED, fptr, 0);
    memcpy(str, string, strlen(string));
    ftruncate(fptr,strlen(string));
    close(fptr);
    return 0;
}
