#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int verificaMaior(int linhas, int colunas, int m[linhas][colunas]) {
    int maior = 0;
    for(int i = 0; i < linhas; i++) {
        for(int j = 0; j < colunas; j++) {
            if(m[i][j] > maior) {
                maior = m[i][j];
            }
        }
    }
    return maior;
}

void populaMatriz(int linhas, int colunas, int m[linhas][colunas]) {
    srand(time(NULL));

    for(int i = 0; i < linhas; i++) {
        for(int j = 0; j < colunas; j++) {
            m[i][j] = (rand() % 100) + 1;
        }
    }
}

int main() {
    int linhas;
    int colunas;
    printf("Quantas linhas?\n");
    scanf("%d", &linhas);
    printf("Quantas colunas?\n");
    scanf("%d", &colunas);
    int m[linhas][colunas];
    populaMatriz(linhas, colunas, m);
    int maior = verificaMaior(linhas, colunas, m);
    printf("Maior numero: %d", maior);
    return 0;
}