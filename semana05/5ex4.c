#include <stdio.h>

void adicionarMatrizes(int m1[][4], int linhas, int m2[][4], int c[][4]) {
    for(int i = 0; i < linhas; i++) {
        for(int j = 0; j < 4; j++) {
            c[i][j] = m1[i][j] + m2[i][j];
        }
    }
}

void leiaMatriz(int m[][4], int linhas) {
    for(int i = 0; i < linhas; i++) {
        for(int j = 0; j < 4; j++) {
            printf("Digite o valor de m[%d][%d]: \n", i, j);
            scanf("%d", &m[i][j]);
        }
    }
}

void imprimirMatriz(int c[][4], int linhas) {
    for(int i = 0; i < linhas; i++) {
        for(int j = 0; j < 4; j++) {
            printf("valor de c[%d][%d]: %d\n", i, j, c[i][j]);
        }
    }
}

int main() {
    int m1[2][4];
    int m2[2][4];
    int c[2][4];
    leiaMatriz(m1, 2);
    leiaMatriz(m2, 2);
    adicionarMatrizes(m1, 2, m2, c);
    imprimirMatriz(c, 2);
    return 0;
} 