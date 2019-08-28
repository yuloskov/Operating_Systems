#include <stdio.h>

int main(){
    char string[100];
    scanf("%s", string);
    int i = 0;
    while (string[i] != '\0')
    {
        i++;
    }

    while (i >= 0)
    {
        printf("%c", string[i]);
        i--;
    }
}