#include <stdio.h>
//Escreva uma funcao que receba um vetor e, sem utilizar
//qualquer vetor auxiliar, coloque os numeros pares no inıcio do
//vetor e os numeros ımpares no final do vetor.

void trocarParIm(int v[], int n){
    int x;
    for (int i = 0; i < n; i++)
        if (v[i] % 2 != 0) {
            x = v[i];
            for (int j = i; j < n; j++)
                if (v[j] % 2 == 0) {
                    v[i] = v[j];
                    v[j] = x;
                    break;
                }
        }
}

void mostra_vetor (int v[], int n) {
int i;
for (i = 0; i < n; i++) {
printf("%d ", v[i]);
}
}

int main() {
    int v[5] = {1, 2, 3, 4, 5};
    int n = 5;
    trocarParIm(v, n);
    mostra_vetor(v, n);
    return 0;
}