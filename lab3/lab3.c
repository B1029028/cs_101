#include <stdio.h>

int my_strlen(char* s) {
    int len = 0;
    while (*s++) len++;
    return len;
}
int rec_strlen(char* s) {
    if (!*s) return 0;
    return 1 +rec_strlen(s+1);
}
char* my_sort(char* s) {
    for (char* t = s; *t; t++) {
        for (char* p = t+1; *p; p++) {
            if (*t > *p) {
                char tmp = *t;
                *t = *p;
                *p = tmp;
            }
        }
    }
    return s;
}
int main(){
    char s[] = "IU is a girl!";
    printf("len = %d\n", my_strlen(s));
    printf("len = %d\n", rec_strlen(s));
    printf("sort = %s\n", my_sort(s));
    return 0;
}