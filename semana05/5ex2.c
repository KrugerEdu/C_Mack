#include <stdio.h>

int pares(int m[][3], int linhas) {
    int qtd = 0;
    for(int i = 0; i < linhas; i++) {
        for(int j = 0; j < 3; j++) {
            if(m[i][j] % 2 == 0) {
                qtd++;
            }
        }
    }
    return qtd;
}

void leiaMatriz(int m[][3], int linhas) {
    for(int i = 0; i < linhas; i++) {
        for(int j = 0; j < 3; j++) {
            printf("Digite o valor de m[%d][%d]: \n", i, j);
            scanf("%d", &m[i][j]);
        }
    }
}

int main() {
    int m[3][3];
    leiaMatriz(m, 3);
    int n = pares(m, 3);
    printf("qtd: %d\n", n);
    return 0;
} 