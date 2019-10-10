#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <string.h>
#include <unistd.h>
int main(){
    int * arr[10];
    struct rusage r_usage;

    for (int i = 0; i < 10; i++){
        arr[i] = malloc(10000000);
        memset(arr[i], 0, 10000000);
        getrusage(RUSAGE_SELF,&r_usage);
        printf("Memory used: %ld \n", r_usage.ru_maxrss);
        sleep(1);
    }
}