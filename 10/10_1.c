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

int main(){
    char str[L];
    scanf("%s", &str);
    printf("%d\n", strlen(numbers(str)));
    printf("%s\n", numbers(str));
    return 0;
}