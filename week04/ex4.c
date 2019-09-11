#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
    char string[100];
    while (strcmp("exit", string) != 0)
    {
        fgets(string, 100, stdin);
        system(string); //system supports background execution by default
    }
}