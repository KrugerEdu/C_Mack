#include <stdio.h>

int main() {
    int a;
    int b;
    int c;
    
    
    printf("Lado A: \n");
    scanf("%d", &a);
    printf("Lado B: \n");
    scanf("%d", &b);
    printf("Lado C: \n");
    scanf("%d", &c);

    if (a < b + c && b < a + c && c < a + b) {
        printf("Triangulo existente!\n");
    } else {
        printf("Nao existe esse triangulo!\n");
    }
    return 0;
}