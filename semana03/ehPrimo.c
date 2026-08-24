#include <stdio.h>

int ehprimo(int n, int primo, int i) {
    primo = 1;
    
    if (n < 2) {
        primo = 0;
    }

    for (i = 2; i < n; i++) {
        if (n % i == 0) {
            primo = 0;
        }
    }
    if (primo == 1) {
        printf("Primo");
    } else {
        printf("Nao primo");
    }
}

int main() {
    int n, i, primo;
    printf("Digite um numero e descobra se ele eh primo: \n");
    scanf("%d", &n);
    printf("Eh Primo?: %d\n", ehprimo(n, primo, i));
    return 0;
}