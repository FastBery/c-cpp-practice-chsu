#include <stdio.h>

double y(double x){
    return x * (x - 0.5) * (x - 1.) * (x - 1.5) * (x - 2.) * (x - 2.5) * (x - 3.) * (x - 3.5) * (x - 4.) * (x - 4.5) * (x - 5.); 
}

int main(){ 
    double x = 0.1;
    for(; x <= 0.9; x += 0.1){
        printf("x = %.1lf; y(x) = %.3lf\n", x, y(x));
    }
    return 0;
}