#include <stdio.h>

int main() {
    float media;
    int presenca;
    printf("Digite sua media final: \n");
    scanf("%f", &media);
    printf("Digite sua frequencia: \n");
    scanf("%d", &presenca);
    if (presenca < 75) {
        printf("Reprovado\n");
    } else if (presenca >= 75 && media >= 6) {
        printf("Aprovado\n");
    } else if (presenca >= 75 && media < 6){
        printf("De Exame\n");
    } else {
        printf("Reprovado\n");
    }
    return 0;
}