#include <stdio.h>
#include <math.h>

#define MAX_BUFFER 100

struct point{
    double x;
    double y;
    double mass;
    int n;
};

void output(double *x, double *y, double *m, int N){
    for(int i = 0; i < N; i++){
        printf("(%.2lf, %.2lf, %.2lf)\n", *(x + i), *(y + i), *(m + i));
    }
}

void input(double *x, double *y, double *m, int N){
    printf("Введите точки пример: \
(1, 2, 3) - где 1, 2 (координаты), 3 (масса)\n");
    for(int i = 0; i < N; i++){
        scanf(" ( %lf , %lf , %lf )", (x + i), (y + i), (m + i));
    }
}

double x_center(double *x, double *m, int N){
    double s = 0;
    double sm = 0;
    for(int i = 0; i < N; i++){
        s += x[i] * m[i];
        sm += m[i];
    }
    return s / sm;
}

double y_center(double *y, double *m, int N){
    double s = 0;
    double sm = 0;
    for(int i = 0; i < N; i++){
        s += y[i] * m[i];
        sm += m[i];
    }
    return s / sm;
}

struct point center(double *x, double *y, double *m, int N){
    struct point p = {x_center(x, m, N),
       y_center(y, m, N),
       0};
    return p;
}

void print_center(double *x, double *y, double *m, int N){
    printf("Центр тяжести - (%.2lf, %.2lf)\n", x_center(x, m, N), y_center(y, m, N));
}

struct point nearest(double *x, double *y, double *m, int N, struct point c){
    double min = sqrt(((c.x - x[0])*(c.x - x[0])) + ((c.y - y[0]) * (c.y - y[0])));
    printf("min - %.2lf\n", min);
    struct point p;
    for(int i = 0; i < N; i++){
        if(sqrt(((c.x - x[i])*(c.x - x[i])) + ((c.y - y[i]) * (c.y - y[i]))) < min){
            min = sqrt(((c.x - x[i])*(c.x - x[i])) + ((c.y - y[i]) * (c.y - y[i])));
            printf("min - %.2lf\n", min);
            p.x = x[i];
            p.y = y[i];
            p.mass = m[i];
            p.n = i;
        }
    }
    return p;
}

void delete(double *x, double *y, double *m, int *N, int n){
    for(int i = n; i < *N - 1; i++){
        x[i] = x[i + 1];
        y[i] = x[i + 1];
        m[i] = x[i + 1];
    }
    (*N)--;
}

//3
//(1, 1, 3) (2, 2, 6) (3, 3, 1)

int main(){
    double x[MAX_BUFFER];
    double y[MAX_BUFFER];
    double m[MAX_BUFFER]; 

    int N;

    printf("Введите количество элементов в массиве (макс. 100):\n");
    scanf("%d", &N);

    input(x, y, m, N);
    output(x, y, m, N);

    print_center(x, y, m, N);
    struct point c = center(x, y, m, N);
    struct point p = nearest(x, y, m, N, c);
    printf("Ближайшая точка - (%.2lf, %.2lf)\n", p.x, p.y);
    delete(x, y, m, &N, p.n);
    output(x, y, m, N);

    return 0;

}