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
    return primo;
}

int main() {
    int n, i, primo;
    char *r;
    r = "s";
    printf("Digite um numero e descobra se ele eh primo: \n");
    scanf("%d", &n);
    if (ehprimo(n, primo, i) == 0) {
        r = "n";
    }
    printf("Eh Primo?: %s\n", r);
    return 0;
}