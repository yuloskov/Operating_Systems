#include <stdio.h>
#include <unistd.h>

int main(){
    int n = getpid();
    printf("Hello from a parent PID - %d\n", n);
    n = fork();
    if (n != 0) 
        printf("Hello from a child PID - %d\n", n);
    return 0;
}