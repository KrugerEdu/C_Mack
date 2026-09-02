#include <stdio.h>

void popular(int v[], int n) {
    int x;
    for (int i = 0; i < n; i++) {
        printf("adicione o vetor n%d\n", i+1);
        scanf("%d", &x);
        v[i] = x;
    }
}

int frequencia(int v[], int n) {
    int x;
    int melhor;
    int melhor_cont = 0;
    for (int i = 0; i < n; i++) {
       x = v[i];
       int cont = 0;
       for (int j = i+1; j < n; j++) {
        if (x == v[j]) {
            cont++;
        }
       }
       if (cont > melhor_cont) {
        melhor = x;
        melhor_cont = cont;
       }
    }
    return melhor;
}

int main() {
    int n = 5;
    int v[n];
    popular(v, n);
    int melhor = frequencia(v, n);
    printf("%d", melhor);
    return 0;
}