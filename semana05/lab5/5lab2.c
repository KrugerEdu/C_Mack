#include <stdio.h>

void transporta(int lin, int col, int A[lin][col], int At[col][lin]) {
    for (int i = 0; i < lin; i++) {
        for (int j = 0; i < col; i++) {
            At[j][i] = A[i][j];
        }
    }
}

void imprimirMatriz(int linhas, int col, int At[col][linhas]) {
    for(int i = 0; i < linhas; i++) {
        for(int j = 0; j < col; j++) {
            printf("valor de m[%d][%d]: %d\n", i, j, At[j][i]);
        }
    }
}

int main() {
    int lin = 3;
    int col = 2;
    int A[3][2] = {
        {0, 6}, 
        {-1, 2}, 
        {5, 0}
    };
    int At[col][lin];
    transporta(lin, col, A, At);
    imprimirMatriz (lin, col, At);
    return 0;
}