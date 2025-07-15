#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HOURS 24
int max_id = 0;
int min_id = 0;

float max(float *x){
    float max = 0;
    for(int i = 0; i < HOURS; i++){
        if(x[i] > max)
            max = x[i];
            max_id = i;
    }
    return max;
}

float min(float *x){
    float min = 99;
    for(int i = 0; i < HOURS; i++){
        if(x[i] < min)
            min = x[i];
            min_id = i;
    }
    return min;
}

int main(){
    srand(time(0));
    float volts[HOURS];

    for(int i = 0; i < HOURS; i++){
        volts[i] = rand() % 100;
    }
    printf("Максимальное напряжение: %f, id: %d\n", max(volts), max_id);
    printf("Минимальное напряжение: %f, id: %d\n", min(volts), min_id);
    return 0;
}