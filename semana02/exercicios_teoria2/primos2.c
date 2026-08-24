#include <stdio.h>

int main() {
    int n, numero, i;
    int primo;
    int quantidade = 0;

    printf("Digite n: ");
    scanf("%d", &n);

    numero = 2;

    while (quantidade < n) {
        primo = 1;

        for (i = 2; i < numero; i++) {
            if (numero % i == 0) {
                primo = 0;
            }
        }

        if (primo == 1) {
            printf("%d ", numero);
            quantidade++;
        }

        numero++;
    }

    return 0;
}