#include <stdio.h>

int par(int v[], int n) {
    int qtd = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] % 2 == 0)
            qtd++;
    }
    return qtd;
}

int main() {
    int v[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    int n = 8;

    int qtd = par(v, n);
    printf("%d \n", qtd);
    return 0;
}