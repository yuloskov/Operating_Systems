#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

int main(){
    int fp_w = open("ex1.txt", O_WRONLY);
    int fp_r = open("/dev/random", O_RDONLY);
    char arr[20];
    read(fp_r, arr, sizeof(arr));
    write(fp_w, arr, sizeof(arr));
    close(fp_w);
    close(fp_r);
    return 0;
}