#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
int main(){
    int * arr[10];
    for (int i = 0; i < 10; i++){
        arr[i] = malloc(10000000);
        memset(arr[i], 0, 10000000);
        sleep(1);
    }
}