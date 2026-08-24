#include <stdio.h>

int potencia(int n, int p) {
    int i;
    int resultado;
    if (p == 0) {
        resultado = 1;
    } else {
        resultado = n;
        for (i = 1; i <= p; i++) {
            resultado *= n;
       }
    }
    return resultado;
}

int main() {
    int n, p;
    printf("Base: ");
    scanf("%d", &n);
    printf("Exponente: ");
    scanf("%d", &p);
    printf("Resultado: %d\n", potencia(n, p));
    return 0;
}