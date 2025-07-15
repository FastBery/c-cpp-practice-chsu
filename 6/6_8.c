#include <stdio.h>

double Min(double a, double b, double c){
    if (a >= b) {
        if (c > b) return b;
        else return c;
    }
    else {
        if (c > a) return a;
        else return c;
    }
}

int main(){
    double a, b, c;
    scanf("%lf %lf %lf", &a, &b, &c);
    double x = Min(a, b, c);
    printf("%lf", x);
    return 0;
}