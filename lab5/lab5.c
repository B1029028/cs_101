#include <stdio.h>
#include <stdlib.h>

int* get_int_array(int n) {
    int* num = (int*)calloc(n, sizeof(int));
    return num;
}
void set_value(int* p, int v) {
    *p = v;
}
void print_array(int* p, int n) {
    printf("[");
    for (int i = 0; i < n; i++){
        if (i == n-1) {
            printf("%d", *p);
        }else {
            printf("%d ", *p);
        }
        *p++;
    }
    printf("]\n");
}
typedef struct array_list {
    int n;
    int* (*func1)(int);
    void (*func2)(int*, int);
    void (*func3)(int*, int);
} array_list_t;
int main() {
    int n = 10;
    int* ip = get_int_array(n);

    for (int i = 0; i < n; i++) {
        set_value(ip+i, i+1);
    }
    printf("No.1---------------\n");
    print_array(ip, n);
    free(ip);
    printf("No.2---------------\n");
    array_list_t a;
    a.n = 20;
    a.func1 = get_int_array;
    int* arrayip = a.func1(a.n);
    a.func2 = set_value;
    for (int i = 0; i < a.n; i++) {
        a.func2(arrayip+i, i+1);
    }
    a.func3 = print_array;
    a.func3(arrayip, a.n);
    printf("No.3---------------\n");
    
    return 0;
}