#include <stdio.h>
#include <math.h>

#define N 10

// double length()
void output(int m[][2]){
    for(int i = 0; i < N; i++){
        printf("(%d, %d) ", m[i][0], m[i][1]);
    }
    printf("\n");
}

double length(int *a1, int *a2){
    return sqrt( pow(a1[0] - a2[0], 2) + pow(a1[1] - a2[1], 2));
}

void table(int m[][2]){
    printf("------ ");
    output(m);
    for(int i = 0; i < N; i++){
        printf("(%d, %d) ", m[i][0], m[i][1]);
        for(int j = 0; j < N; j++){
            printf("%6.2f ", length(m[i], m[j]));
        }
        printf("\n");
    }
}

double max_distance(int m[][2]){
    double max = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(max < length(m[i], m[j])){
                max = length(m[i], m[j]);
            }
        }
    }
    return max;
}

//1 5 2 5 8 3 8 5 1 5 2 3 6 9 3 2 9 9 1 4
int main(){
    int points[N][2];
    for(int i = 0; i < N; i++){
        scanf("%d %d", &points[i][0], &points[i][1]);
    }
    output(points);
    printf("\n");
    printf("\n");
    table(points);

    printf("\n");
    printf("\n");
    printf("%lf", max_distance(points));
    return 0;
}