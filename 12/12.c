#include <stdio.h>
#include <string.h>

#define N 20
// char *months[12] = {
//     "января", "февраля", "марта", "апреля", "мая", "июня",
//     "июля", "августа", "сентября", "октября", "ноября", "декабря"
// };


char *months[12] = {
    "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"
};


typedef struct{
    int day;
    char month[N];
    int month_id;
    int year;
} date;

date input(){
    date res;

    char buffer[1024];
    char ch;
    int i = 0;
    while( (ch = getchar()) != '\n' && ch != EOF && i < N - 1)
        buffer[i++] = ch;
    buffer[i] = '\0';

    if(strpbrk(buffer, " ") != NULL){
        sscanf(buffer, "%d %s %d", &res.day, res.month, &res.year);
    }
    else{
        int m = 1;
        sscanf(buffer, "%d.%d.%d", &res.day, &res.month_id, &res.year);
        strcpy(res.month, months[res.month_id - 1]);
    }
    return res;
}

void output(date d){
    printf("%d %s %d\n", d.day, d.month, d.year);
}

void sort(date m[], int n){
    for(int i = 0; i < n; i++){
        output(m[i]);
    }
    printf("sort\n");
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (m[j].year < m[min].year)
                min = j;
        }
        if (min != i) {
            date temp = m[min];
            m[min] = m[i];
            m[i] = temp;
        }
    }

    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (m[j].month_id < m[min].month_id)
                min = j;
        }
        if (min != i) {
            date temp = m[min];
            m[min] = m[i];
            m[i] = temp;
        }
    }

    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (m[j].day < m[min].day)
                min = j;
        }
        if (min != i) {
            date temp = m[min];
            m[min] = m[i];
            m[i] = temp;
        }
    }
    for(int i = 0; i < n; i++){
        output(m[i]);
    }
}


int main(){
    date d;
    date m[2];
    d = input();
    m[0] = input();
    m[1] = input();
    output(d);
    sort(m, sizeof(m)/ sizeof(date));
    return 0;

}