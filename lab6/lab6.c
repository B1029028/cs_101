#include <stdio.h>

int _sum(int x, int y) {
    int z;
    z = x + y;
    return z;
}
int _sub(int x, int y) {
    int z;
    z = x - y;
    return z;
}
int _mult(int x, int y) {
    int z;
    z = x * y;
    return z;
}
int _div(int x, int y) {
    int z;
    z = x / y;
    return z;
}
int _power(int x, int y) {
    int z = x;
    if (y == 0) {
        z = 1;
    }
    for (int i = 1; i < y; i++) {
        z = z * x;
    }
    return z;
}
int main() {
    int x, y, choice;
    int (*ope[5])(int, int);
    ope[0] = _sum;
    ope[1] = _sub;
    ope[2] = _mult;
    ope[3] = _div;
    ope[4] = _power;

    printf("Enter two integers: ");
    scanf("%d%d", &x, &y);

    printf("Enter 0 to +, 1 to -, 2 to *, 3 to /, or 4 to ^: ");
    scanf("%d", &choice);

    printf("%d", ope[choice](x, y));
    return 0;
}