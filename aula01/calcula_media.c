#include <stdio.h>

int main() {
    float n1;
    float n2;

    printf("N1: ");
    // %f - Float | %d - Int | %c - Char
    // &n1 = endereco da memoria
    scanf("%f", &n1);
    printf("N2: ");
    scanf("%f", &n2);

    float media = (n1 + n2) / 2;
    // %.2f - formata com 2 casas decimais
    printf("Media: %.2f\n", media);

    return 0;

}