#include <stdio.h>
#include <math.h>

#define MAX_BUFFER 100

double mean(int *m, int n){
    int s = 0;
    for(int i = 0; i < n; i++){
        s += m[i];
    }
    return (double)s / (double)n;
}

int nearest(int *m, int n, double s){
    int min = abs(s - (double)m[0]);
    int c = 0;
    for(int i = 0; i < n; i++){
        if(abs(s - (double)m[i]) < min){
            min = abs(s - (double)m[i]);
            c = m[i];
        }
    }
    return c;
}

int main(){
    int array[MAX_BUFFER];
    int N;
    printf("Введите количество элементов в массиве (макс. 100):\n");
    scanf("%d", &N);
    printf("Введите элементы через пробел\n");
    for(int i = 0; i < N; i++){
        scanf("%d", (array + i));
    }
    double m = mean(array, N);
    printf("Среднее арифметическое: %.2lf\n", m);
    printf("Ближайший элемент к ср.ар. : %d\n", nearest(array, N, m));
    return 0;

}