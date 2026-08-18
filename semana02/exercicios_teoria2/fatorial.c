#include <stdio.h>

int main() {
    int num;
    int fat;
    printf("Digite um numero para descobrir seu fatorial: ");
    scanf("%d", &num);
    fat = num;
    for (int x = num - 1; x > 0; x--)
    {
        fat *= x;
    }
    printf("%d no fatorial eh: %d\n", num, fat);
    return 0;
}