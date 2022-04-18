#include <stdio.h>

int main () {
    int n[11]={6,4,7,2,0,9,8,1,5,3};
    int* p = NULL;
    int find_num = 9;
    printf("NO.1 -------------------\n");
    for (int a=0; a < 11; a++) {
        if (n[a] == find_num) {
            p = &n[a];
            printf("&n[%d]->%p, n[%d]=%d; p->%p, *p=%d\n", a, &n[a], a, n[a], p, *p);
        }
    }
    printf("NO.2 -------------------\n");
    int* ap[10];
    for (int a = 0;; a++) {
        for (int b = 0; b < 10; b++){
            if(n[b] == a) {
                ap[a] = &n[b];
                printf("&n[%d]->%p, n[%d]=%d; ap[%d]->%p, *ap=%d\n", b, &n[b], b, n[b], a, ap[a], *ap[a]);
            }
        }
        if (n[a] == n[9]){
            break;
        }
    }
}