#include <stdio.h>
#include <string.h>

#define TOTAL 10

void output(int *values){
    for(int i = 0; i < TOTAL; i++){
        printf("%d ", values[i]);
    }
    printf("\n");
}

void output_table(char m[TOTAL][TOTAL]){
    for(int i = 0; i < TOTAL; i++){
        for(int j = 0; j < TOTAL; j++){
            printf("%c ", m[i][j]);
        }
        printf("\n");
    }
}

void input_str(char *f){
    char *ptr = f, ch;
    int i = 0;
    while( (ch = getchar()) != '\n' && ch != EOF && i < TOTAL - 1)
        ptr[i++] = ch;
    ptr[i] = '\0';
}

void input_to_string(char *m, char *string){
    int i = -1;
    int n = 0;
    while(string[n] != '\0' && i < TOTAL + 1){
        if((string[n] == '\t' || string[n] == ' ' || string[n] == '\n' || string[n] == EOF) && string[n - 1] != ' '){
            if(i != -1){ 
                m[i] = string[n - 1];
                n++;
                i++;
            }
            else{
                i++;
                n++;
            }
        }
        else{
            n++;
        }
    }
    if(string[n - 1] != '\n'){
        m[i] = string[n - 1];
    }
}

void make_table(char m[TOTAL][TOTAL], char *file_name){
    FILE *file;
    file = fopen(file_name, "r");
    char buffer[1024];
    int i = -1;
    while(fgets(buffer, 1024, file)){
        if(i != -1){
            input_to_string(&m[i][0], buffer);
        }
        i++;
    }  
    fclose(file);
}

void total_points(char m[TOTAL][TOTAL], int *res){
    for(int i = 0; i < TOTAL; i++){
        for(int j = 0; j < TOTAL; j++){
            if(m[i][j] != '-'){
                res[i] += (int)m[i][j] - 48;
            }
        }
    }
}

int max(int *x){
    int max = 0;
    int max_id = 0;
    for(int i = 0; i < TOTAL; i++){
        if(x[i] > max){
            max = x[i];
            max_id = i;
        }
    }
    return max_id + 1;
}

int min(int *x){
    int min = 10;
    int min_id = 0;
    for(int i = 0; i < TOTAL; i++){
        if(x[i] < min){
            min = x[i];
            min_id = i;
        }
    }
    return min_id + 1;
}

int main(){
    char table[TOTAL][TOTAL];
    int bandit[TOTAL] = {};
    int *ptr_bandit = bandit;
    char file_name[] = "table.txt";

    make_table(table, file_name);
    output_table(table);
    
    printf("\n");

    total_points(table, ptr_bandit);
    output(bandit);

    printf("%d - max\n", max(bandit));
    printf("%d - min\n", min(bandit));
    
    return 0;
}