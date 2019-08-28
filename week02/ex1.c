#include <float.h>
#include <limits.h>
#include <stdio.h>

int main(){
    int a;
    float b;
    double c;
    a = INT_MAX;
    b = FLT_MAX;
    c = DBL_MAX;
    printf("%d %lui\n", a, sizeof(a));
    printf("%f %lui\n", b, sizeof(b));
    printf("%f %lui\n", c, sizeof(c));
}