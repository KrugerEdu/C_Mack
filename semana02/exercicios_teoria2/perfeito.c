#include <stdio.h>

int main() {
    int n, i, soma;

    printf("Digite um numero: ");
    scanf("%d", &n);

    soma = 0;

    for (i = 1; i < n; i++) {
        if (n % i == 0) {
            soma = soma + i;
        }
    }

    if (soma == n) {
        printf("%d eh um numero perfeito.\n", n);
    } else {
        printf("%d nao eh um numero perfeito.\n", n);
    }

    return 0;
}