#include <stdio.h>
#include <stdbool.h>

bool ordem(int v[], int n) {
    int i;
    for (i = 0; i < n-1; i++) {
        if (v[i] > v[i+1]) {
            return false;
        } else {
            return true;
        }
    }
}

void leituraDados(int v[], int n){
    for (int i = 0; i < n; i++){
        printf("Digite o elemento %d: ", i);
        scanf("%d", &v[i]);
    }
}

int main() {
    int v[10] = {1,2,3,4,5,6,7,8,9,10};
    if (ordem(v, 10))
        printf("Vetor Crescente");
    else
        printf("Vetor Decrescente!");
    return 0;
}