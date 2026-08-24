#include <stdio.h>

void ehprimo(int n, int primo, int i, int x) {
    for (x = 1; x <= n; x++) {
        primo = 1;
        if (x < 2) {
            primo = 0;
        }

        for (i = 2; i < x; i++) {
            if (x % i == 0) {
                primo = 0;
                break;
            }
        }
        if (primo == 1) {
            printf("%d ", x);
        }
    }
}

int main() {
    int n, i, primo, x;
    char *r;
    r = "s";
    printf("Ate que numero voce quer saber os primos: \n");
    scanf("%d", &n);
    ehprimo(n, i, primo, x);
    return 0;
}