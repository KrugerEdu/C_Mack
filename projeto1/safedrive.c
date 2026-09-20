#include <stdio.h>
#define MAX_AMOSTRAS 100
int main() {
    float velocidade[MAX_AMOSTRAS][2];
    float sensores_frontais[MAX_AMOSTRAS][3];
    float sensores_laterais[MAX_AMOSTRAS][2];
    int processamento[MAX_AMOSTRAS][2];
    int status[MAX_AMOSTRAS][3];

    int atrito;
    int sensibilidade;
    //Configuracao
    printf("Informacoes Iniciais\nMe diga o atrito da via: \n");
    scanf("%d", &atrito);
    printf("Agora me indique a Sensibilidade do ADAS\n(1-Esportivo, 2-Normal, 3-Seguro)\n");
    scanf("%d", &sensibilidade);

    //Menu
    int opcao = 0;
    do {
        printf("--SafeDrive--\n1)Carregar dados iniciais\n2)Inserir nova amostra\n3)Relatorio de risco\n4)Sair\n");
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                printf("Opcao 1\n");
                break;
            case 2:
                printf("Opcao 2\n");
                break;
            case 3:
                break;
            case 4:
                printf("Adios!");
                break;
            default:
                printf("Opcao invalida\n");
}
    } while(opcao != 4);
}