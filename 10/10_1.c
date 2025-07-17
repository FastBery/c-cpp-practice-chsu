#include <stdio.h>
#include <string.h>

#define L 256

char *numbers(char *str){
    int length = strlen(str);
    // printf("%d\n", length);

    static char new_str[L];
    int n = 0;
    for(int i = 0; i < length; i++){
        if(str[i] >= 48 && str[i] <= 57){
            new_str[n++] = str[i];
        }
    }
    return new_str;
}

void *input_str(char *f){
    char *ptr = f, ch;
    int i = 0;
    while( (ch = getchar()) != '\n' && ch != EOF && i < L - 1)
        ptr[i++] = ch;
    ptr[i] = '\0';
}

int main(){
    char str[L];
    int i = 0;
    char *ptr = str, ch;

    // while( (ch = getchar()) != '\n' && ch != EOF && i < L - 1)
    //     ptr[i++] = ch;
    // ptr[i] = '\0';

    input_str(str);
    printf("%d\n", strlen(numbers(str)));
    printf("%s\n", numbers(str));
    return 0;
}