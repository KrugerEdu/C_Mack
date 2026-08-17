#include <stdio.h>

int main() {
    int numero;
    int soma = 0;
    printf("Bem vindo a soma de numeros\ndigite o primeiro: \n");
    scanf("%d", &numero);
    
    while (numero > 0) {
        soma += numero;
        printf("Digite outro numero: \n");
        scanf("%d", &numero);
    }
    printf("\nSoma Final: %d\n", soma);
    return 0;
}