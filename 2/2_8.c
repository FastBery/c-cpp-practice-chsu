#include <stdio.h>

int main(){
    double x, y;
    scanf("(%lf, %lf)", &x, &y);
    if(x > 0)
        if(y > 0)
            printf("I");
        else
            printf("IV");
    else
        if(y > 0)
            printf("II");
        else
            printf("III");
    return 0;
}