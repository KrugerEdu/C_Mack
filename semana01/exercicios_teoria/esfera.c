#include <stdio.h>

int main() {
    const float pi = 3.141592;
    float raio;
    scanf("%f", &raio);
    float A = 4 * pi * (raio*raio);
    printf("Area da esfera: %f", A);
    return 0;
}