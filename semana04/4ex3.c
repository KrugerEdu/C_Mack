#include <stdio.h>

int somaPares(int v[], int n) {
    int soma = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] % 2 == 0){
            soma += v[i];
        }
    }
    return soma;
}

int main() {
    int v[5] = {1, 2, 3, 4, 5};
    int n = 5;
    int r = somaPares(v, n);
    printf("A soma eh %d ", r);
    return 0;
}