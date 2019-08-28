#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    int n = atoi(argv[1]);
    int r = n;
    int l = (2*n-2)/2;
    for (int i = 0; i < n; i++){
        for (int j = 0; j <= 2*n-1; j++){
            if (j <= r && j > l){
                putchar('*');
            } else {
                putchar(' ');
            }
        }
        l--;
        r++;
        putchar('\n');
    }
}