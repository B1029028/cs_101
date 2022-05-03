#include <stdio.h>
typedef struct my_mm {
    int* calloced_p[10];
} my_mm_t;

int g_mm[10];
my_mm_t mms;
void print_calloc_array(int flag) {
    for (int i = 0; i<10; i++) {
        (mms.calloced_p[i]) ? printf("1"):printf("0");
    }
    if(!flag) {
        printf(" <- Out of space");
    }
    printf("\n");
}
int* my_calloc(int n, int size) {
    int av_size = 0;
    int index;
    for (index = 0; index < 10; index++) {
        if (!mms.calloced_p[index]) {
            av_size++;
        }
        else {
            av_size = 0;
        }

        if(av_size == size) {
            index -= size-1;
            break;
        }
    }
    if (av_size < size) {
        print_calloc_array(0);
        return NULL;
    }
    for (int i = 0; i < size; i++) {
        mms.calloced_p[index+i] = &g_mm[index];
    }
    print_calloc_array(1);
    return &g_mm[index];
}
void my_free(int* p) {
    for (int i = 0; i < 10; i++) {
        if (mms.calloced_p[i] == p) {
            mms.calloced_p[i] = NULL;
        }
    }
    print_calloc_array(1);
}



int main() {
    int* np1 = my_calloc(1,1);
    int* np2 = my_calloc(1,2);
    int* np3 = my_calloc(1,3);
    int* np4 = my_calloc(1,4);
    my_free(np1);
    my_free(np4);
    int* np5 = my_calloc(1,5);
    int* np6 = my_calloc(1,3);
    return 0;
}