#include <stdio.h>

int moved;

void rec_dec(char* s) {
    if (!*s) {
        return;
    }
    printf("%c,", *s);
    rec_dec(s+1);
}
void hanoi(int n, int i, char A, char B, char C) {
    if(n == 1) {
        FILE* fp = fopen("hanoi.txt","a+");
        fprintf(fp,"Move disk%d from %c to %c\n", i, A, C);
        fclose(fp);
        moved++;
    }
    else {
        hanoi(n-1, i-1, A, C, B);
        hanoi(1, i, A, B, C);
        hanoi(n-1, i-1, B, A, C);
    }
    
}
void hanoi_tower(int n) {
    int i;
    i=n;
    FILE* rfp = fopen("hanoi.txt","w+");
    fprintf(rfp,"hanoi tower\n");
    fclose(rfp);
    hanoi(n, i, 'A', 'B', 'C');
    FILE* wfp = fopen("hanoi.txt","a+");
    fprintf(wfp,"\nTotal moved %d steps\n\n",moved);
    fclose(wfp);
    return;
}
int multiplication(int i, int j) {
    if (i == 10) {
        return 0;
    }
    else if (j == 9) {
        printf("%d*%d=%d \n", i, j, i*j);
        multiplication(i+1, 1);
    }
    else {
        printf("%d*%d=%d ", i, j, i*j);
        multiplication(i, j+1);
    }
}
int main() {
    
    char s[] = "1234567890";
    rec_dec(s);
    printf("\nfunc#1-----------------------\n");
    hanoi_tower(16);
    printf("func#2-----------------------\n");
    multiplication(1,1);
    printf("func#3-----------------------\n");
    return 0;
}