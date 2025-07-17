#include <stdio.h>
#include <string.h>

#define TOTAL 1024

void delete(char *str){
    int length = strlen(str);
    char *p;
    while(strpbrk(str, ",.-;\'\":")){
        for(int i = strpbrk(str, ",.-;'\":") - str; i < length; i++){
            str[i] = str[i + 1];
        }    
    }
}

void *input_str(char *f){
    char *ptr = f, ch;
    int i = 0;
    while( (ch = getchar()) != '\n' && ch != EOF && i < TOTAL - 1)
        ptr[i++] = ch;
    ptr[i] = '\0';
}

int main(){
    FILE *f1;
    FILE *f2;
    char buffer[TOTAL];

    char file_name_input[TOTAL];
    printf("%s\n", "Введите имя файла для чтения:");
    input_str(file_name_input);

    char file_name_output[TOTAL];
    printf("%s\n", "Введите имя файла для вывода:");
    input_str(file_name_output);

    f1 = fopen(file_name_input, "r");
    f2 = fopen(file_name_output, "w");

    while(fgets(buffer, TOTAL, f1)){
        delete(buffer);
        fprintf(f2, buffer);
        
    }    
    fclose(f1);
    fclose(f2);
    // printf("%s", buffer);
    return 0;
} 