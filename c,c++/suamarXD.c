#include <stdio.h>

void sumarAyB(int a, int b, int c) {
    c = a + b;
}

void sumarAyBprima(int a, int b, int *c) {
    *c = a + b;
}

int main() {

    int a, b, c;
    scanf("%d %d", &a, &b);

    sumarAyB(a, b, c);
    printf("a: %d, b: %d, c: %d\n", a, b, c);

    sumarAyBprima(a, b, &c);
    printf("a: %d, b: %d, c: %d\n", a, b, c);

    return 0;
}