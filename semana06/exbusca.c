#include <stdio.h>
#include <string.h>
#define TAM 15

// Busca Linear
int buscaLinear(char palavras[][20], int tamanho, char procurada[]) {
    for (int i = 0; i < tamanho; i++) {
        if (strcmp(palavras[i], procurada) == 0) {
            return i;
        }
    }
    return -1;
}
// Busca Binária
int buscaBinaria(char palavras[][20], int tamanho, char procurada[]) {
    int inicio = 0;
    int fim = tamanho - 1;
    int meio, comparacao;
    while (inicio <= fim) {
        meio = (inicio + fim) / 2;
        comparacao = strcmp(palavras[meio], procurada);
        if (comparacao == 0) {
            return meio;
        } else if (comparacao < 0) {
            inicio = meio + 1;
        } else {
            fim = meio -1;
        }
    }
    return -1;
}

int main() {
    char palavras[TAM][20] = {
        "abacaxi",
        "banana",
        "cachorro",
        "dado",
        "elefante",
        "foca",
        "gato",
        "hotel",
        "igreja",
        "janela",
        "kiwi",
        "laranja",
        "macaco",
        "navio",
        "ovelha"
    };
    char palavra[20];
    printf("Informe a palavra:\n");
    scanf("%19s", palavra);
    int n = buscaLinear(palavras, TAM, palavra);
    printf("Busca Linear: %d \n", n);
    n = buscaBinaria(palavras, TAM, palavra);
    printf("Busca Binaria: %d \n", n);
    return 0;
}