#include <stdio.h>

void multiplicar(int m[][3], int linhas, int mult) {
    int qtd = 0;
    for(int i = 0; i < linhas; i++) {
        for(int j = 0; j < 3; j++) {
            m[i][j] *= mult;
        }
    }
}

void leiaMatriz(int m[][3], int linhas) {
    for(int i = 0; i < linhas; i++) {
        for(int j = 0; j < 3; j++) {
            printf("Digite o valor de m[%d][%d]: \n", i, j);
            scanf("%d", &m[i][j]);
        }
    }
}

void imprimirMatriz(int m[][3], int linhas) {
    for(int i = 0; i < linhas; i++) {
        for(int j = 0; j < 3; j++) {
            printf("valor de m[%d][%d]: %d\n", i, j, m[i][j]);
        }
    }
}

int main() {
    int m[3][3];
    leiaMatriz(m, 3);
    int mult;
    printf("Por quanto voce deseja multiplicar? \n");
    scanf("%d", &mult);
    multiplicar(m, 3, mult);
    imprimirMatriz(m, 3);
    return 0;
} 