#include <stdio.h>

void popular(int v[], int n) {
    int x;
    for (int i = 0; i < n; i++) {
        printf("adicione o vetor n%d\n", i+1);
        scanf("%d", &x);
        v[i] = x;
    }
}

int escalar(int v[], int v2[], int n) {
    int soma = 0;
    for (int i = 0; i < n; i++){
        soma += v[i] * v2[i];
    }
    return soma;
}

int main() {
    int v[5];
    int v2[5];
    int n = 5;
    popular(v, n);
    popular(v2, n);
    int soma = escalar(v, v2, n);
    printf("%d \n", soma);
    return 0;
}