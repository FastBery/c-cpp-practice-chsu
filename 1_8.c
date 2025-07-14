#include <stdio.h>

int main(){
    int a, b;
    scanf("%d %d", &a, &b);
    //целочисленное деление
    printf("a / b = %d\n", a / b);
    printf("b / a = %d\n\n", b / a);
    //остатки
    printf("a %% b = %d\n", a % b);
    printf("b %% a = %d\n\n", b % a);
    //вещественные значения
    printf("a / b = %.3lf\n", (double)a / (double)b);
    printf("b / a = %.3lf\n\n", (double)b / (double)a);

    return 0;
}