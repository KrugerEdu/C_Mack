#include <stdio.h>

int maior_numero(int m[][4], int linhas) {
    int maior = 0;
    for(int i = 0; i < linhas; i++) {
        for(int j = 0; j < 4; j++) {
            if(m[i][j] > maior) {
                maior = m[i][j];
            }
        }
    }
    return maior;
}

void leiaMatriz(int m[][4], int linhas) {
    for(int i = 0; i < linhas; i++) {
        for(int j = 0; j < 4; j++) {
            printf("Digite o valor de m[%d][%d]: \n", i, j);
            scanf("%d", &m[i][j]);
        }
    }
}

int main() {
    int m[4][4];
    leiaMatriz(m, 4);
    int n = maior_numero(m, 4);
    printf("Maior numero: %d\n", n);
    return 0;
} 