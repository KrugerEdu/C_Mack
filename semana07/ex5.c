#include <stdio.h>
//Questao A

int busca_linear(int v[], int n, int x) {
    if (n == 0) {
        return -1;
    }
    
    if (v[n - 1] == x) {
        return n - 1;
    }
    
    return busca_linear(v, n - 1, x);
}

//Questao B

int menor_elemento(int v[], int n) {
    if (n == 1) {
        return v[0];
    }
    
    int menor_resto = menor_elemento(v, n - 1);
    
    if (v[n - 1] < menor_resto) {
        return v[n - 1];
    } else {
        return menor_resto;
    }
}

//Questao C
int soma(int v[], int n) {
    if (n == 1) {
        return v[0];
    }
    
    return v[n - 1] + soma(v, n - 1);
}