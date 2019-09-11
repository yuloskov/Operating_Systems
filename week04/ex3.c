#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
    char string[100];

    while (strcmp("exit", string) != 0)
    {
        scanf("%s", string);
        system(string);
    }
}