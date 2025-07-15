#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TOTAL 20

void output(int *values){
    for(int i = 0; i < TOTAL; i++){
        printf("%d ", values[i]);
    }
    printf("\n");
}

double mean(int *m){
    int s = 0;
    for(int i = 0; i < TOTAL; i++){
        s += m[i];
    }
    return (double)s / (double)TOTAL;
}

void new_array(int *values, char *c){
    double m = mean(values);
    int j = 0;

    if(c == ">"){
        for(int i = 0; i < TOTAL; i++){
            if(values[i] > m){
                values[j] = values[i];
                j++;
            }
        }    
    }
    else if(c == "<"){
        for(int i = 0; i < TOTAL; i++){
            if(values[i] < m){
                values[j] = values[i];
                j++;
            }
        }
    }

    for(int i = j; i < TOTAL; i++){
        values[i] = 0;
    }
}

int main(){
    srand(time(0));
    int values[TOTAL];

    for(int i = 0; i < TOTAL; i++){
        values[i] = rand();
    }

    output(values);
    printf("mean - %.2lf\n", mean(values));
    new_array(values, ">");
    output(values);

    return 0;
}