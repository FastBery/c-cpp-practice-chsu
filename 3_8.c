#include <stdio.h>
#include <stdbool.h>

void frmt(){
    printf("\nВыберите число дяля проверки таблицы умножения N*[2..9]:\n\
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10\n\
        0 - для выхода из программы\n");
}

int main(){
    while(true){
        frmt();

        int N;
        scanf("%d", &N);
        if(N == 0)
            break;
        
        int mistakes = 0;
        for(int i = 2, n = 1; i < 10; i++){
            scanf("%d", &n);
            if(n != N * i){
                mistakes++;
            }
        }

        if(mistakes == 0)
            printf("отлично\n");
        else if(mistakes == 1)
            printf("хорошо\n");
        else if(mistakes == 2)
            printf("удовлетворительно\n");
        else if(mistakes >= 3)
            printf("неудовлетворительно\n");

    }
    return 0;
}