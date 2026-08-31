#include <stdio.h>
#include <stdbool.h>

void leituraDados(int v[], int n){
    for (int i = 0; i < n; i++){
        printf("Digite o elemento %d: ", i);
        scanf("%d", &v[i]);
    }
}

void mudarDados(int v[], int n){
    int x;
    int f = n-1;
    for (int i = 0; i < f; i++){
        x = v[i];
        v[i] = v[f];
        v[f] = x;
        f--;
    }
}

void mostra_vetor (int v[], int n) {
int i;
for (i = 0; i < n; i++) {
printf("%d ", v[i]);
}
}

int main() {
    int v[5];
    leituraDados(v, 5);
    mudarDados(v, 5);
    mostra_vetor(v, 5);
    return 0;
}
