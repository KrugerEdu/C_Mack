#include <stdio.h>

int main() {
    int n1;
    int n2;
    int n3;
    int menor;
    printf("Digite o primeiro numero: \n");
    scanf("%d", &n1);
    printf("Digite o segundo numero: \n");
    scanf("%d", &n2);
    printf("Digite o terceiro numero: \n");
    scanf("%d", &n3);
    menor = n1;
    if (menor > n2) {
        menor = n2;
    }
    if (menor > n3) {
        menor = n3;
    }
    printf("o Menor numero eh: %d\n", menor);
    return 0;
}