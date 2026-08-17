#include <stdio.h>

int main() {
    int n1;
    int n2;
    int n3;
    int x;
    printf("Digite o primeiro numero: \n");
    scanf("%d", &n1);
    printf("Digite o segundo numero: \n");
    scanf("%d", &n2);
    printf("Digite o terceiro numero: \n");
    scanf("%d", &n3);
    if (n2 < n1) {
        x = n1;
        n1 = n2;
        n2 = x;
    }
    if (n3 < n2) {
        x = n2;
        n2 = n3;
        n3 = x;
    }
    if (n2 < n1) {
        x = n1;
        n1 = n2;
        n2 = x;
    }
    printf("%d %d %d", n1, n2, n3);
    return 0;
}