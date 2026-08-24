#include <stdio.h>

int main() {
    int n, i, primo;

    scanf("%d", &n);

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

    return 0;
}