#include <stdio.h>

void bubble_sort(int a[], int n){
    for (int i = 0; i < n; i++){
        for (int j = i+1; j < n; j++){
            if (a[i] > a[j]){
                int t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
    }
}

int main(){
    int a[10] = {5,4,3,6,7,3,1,3,5,0};
    bubble_sort(a, 10);
    for (int i = 0; i < 10; i++){
        printf("%d ", a[i]);
    }
    return 0;
}