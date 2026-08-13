#include <stdio.h>

int main() {
    float temp;
    printf("Digite uma temperatura em celsius para converter: ");
    scanf("%f", &temp);
//C nao muda tipos como o python, ent eh necessario escrever 9 como float (9.0)
    float fahren = temp * (9.0/5.0) + 32;
    printf("fahren: %.2f\n", fahren);
    return 0;
}