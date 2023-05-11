#include <stdio.h>

void troca(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int a = 1;
    int b = 2;

    printf("Valor das variaveis: a = %d, b = %d\n", a, b);
    troca(&a, &b);
    printf("Valor das variaveis: a = %d, b = %d\n", a, b);

    return 0;
}
