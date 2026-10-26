#include <stdio.h>

int potencia(int a, int n) {

    if (n == 0) {
        return 1;
    }
    
    //recursividade:
    return a * potencia(a, n - 1);
}