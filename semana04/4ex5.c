#include <stdio.h>
//Dado um vetor v de numeros inteiros e um inteiro n que
//indica o tamanho do vetor, imprima todos os numeros
//menores do que a media.

int media(int v[], int n){
    int media = 0;
    for (int i = 0; i < n; i++){
        media += v[i];
    }
    media /= n;
    return media;
}

void mostra_menor(int v[], int n, int m){
    printf("Menores do que %d: \n", m);
    for (int i = 0; i < n; i++){
        if (v[i] < m) {
            printf("%d ", v[i]);
        }
    }
}

int main() {
    int v[5] = {1, 2, 3, 4, 5};
    int n = 5;
    int m = media(v, n);
    mostra_menor(v, n, m);
    return 0;
}