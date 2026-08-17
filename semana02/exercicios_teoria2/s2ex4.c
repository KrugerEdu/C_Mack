#include <stdio.h>

int main() {
    int secret = 67;
    int num = 0;
    int tent;
    printf("Bem-Vindo ao Adivinhacao\nDigite um numero: (1-100)");
    while (num != secret) {
        scanf("%d", &num);
        tent++;
        if (num > secret) {
            printf("Escolha um menor! Tent: %d", tent);
        } else {
            printf("Digite um maior! Tent: %d", tent);
        }
    }
    printf("Parabens, numero secreto: %d\n tentativas: %d", secret, tent);
    return 0;
}