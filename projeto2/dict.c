// Eduardo Kruger da Cunha
// RA: 10239330

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_DICIONARIO 1000
#define MAX_STOPWORDS 500
#define MAX_TAM_PALAVRA 100

typedef struct {
    char palavra[MAX_TAM_PALAVRA];
    int frequencia;
} EntradaDicionario;

int buscaBinariaDicionario(EntradaDicionario dic[], int inicio, int fim, const char *alvo) {
    if (inicio > fim) {
        return -1; 
    }

    int meio = inicio + (fim - inicio) / 2;
    int cmp = strcmp(dic[meio].palavra, alvo);

    if (cmp == 0) {
        return meio; 
    } else if (cmp > 0) {
        return buscaBinariaDicionario(dic, inicio, meio - 1, alvo); 
    } else {
        return buscaBinariaDicionario(dic, meio + 1, fim, alvo); 
    }
}

int buscaBinariaStopWords(char stopWords[][MAX_TAM_PALAVRA], int inicio, int fim, const char *alvo) {
    if (inicio > fim) {
        return -1;
    }

    int meio = inicio + (fim - inicio) / 2;
    int cmp = strcmp(stopWords[meio], alvo);

    if (cmp == 0) {
        return meio;
    } else if (cmp > 0) {
        return buscaBinariaStopWords(stopWords, inicio, meio - 1, alvo);
    } else {
        return buscaBinariaStopWords(stopWords, meio + 1, fim, alvo);
    }
}

void inserirDicionarioOrdenado(EntradaDicionario dic[], int *total, const char *novaPalavra) {
    if (*total >= MAX_DICIONARIO) {
        return; 
    }

    int i = *total - 1;

    while (i >= 0 && strcmp(dic[i].palavra, novaPalavra) > 0) {
        dic[i + 1] = dic[i];
        i--;
    }

    strcpy(dic[i + 1].palavra, novaPalavra);
    dic[i + 1].frequencia = 1;
    (*total)++;
}

void inserirStopWordOrdenada(char stopWords[][MAX_TAM_PALAVRA], int *total, const char *novaStop) {
    if (*total >= MAX_STOPWORDS) {
        return;
    }

    int i = *total - 1;
    while (i >= 0 && strcmp(stopWords[i], novaStop) > 0) {
        strcpy(stopWords[i + 1], stopWords[i]);
        i--;
    }

    strcpy(stopWords[i + 1], novaStop);
    (*total)++;
}

void lerStopWords(char stopWords[][MAX_TAM_PALAVRA], int *totalStop) {
    char linha[1024];

    while (fgets(linha, sizeof(linha), stdin) != NULL) {
        size_t len = strlen(linha);

        while (len > 0 && (linha[len - 1] == '\n' || linha[len - 1] == '\r')) {
            linha[--len] = '\0';
        }

        if (len == 0) {
            break;
        }

        char palavra[MAX_TAM_PALAVRA];
        int pos = 0;

        for (size_t i = 0; i <= len; i++) {
            unsigned char c = (unsigned char)linha[i];
            if (isalpha(c)) {
                if (pos < MAX_TAM_PALAVRA - 1) {
                    palavra[pos++] = (char)tolower(c);
                }
            } else if (pos > 0) {
                palavra[pos] = '\0';
                if (buscaBinariaStopWords(stopWords, 0, *totalStop - 1, palavra) == -1) {
                    inserirStopWordOrdenada(stopWords, totalStop, palavra);
                }
                pos = 0;
            }
        }
    }
}

void processarTextoBase(
    EntradaDicionario dic[],
    int *totalDic,
    char stopWords[][MAX_TAM_PALAVRA],
    int totalStop
) {
    char palavra[MAX_TAM_PALAVRA];
    int pos = 0;
    int ch;

    while ((ch = getchar()) != EOF) {
        unsigned char c = (unsigned char)ch;

        if (isalpha(c)) {
            if (pos < MAX_TAM_PALAVRA - 1) {
                palavra[pos++] = (char)tolower(c);
            }
        } else if (pos > 0) {
            palavra[pos] = '\0';

            if (buscaBinariaStopWords(stopWords, 0, totalStop - 1, palavra) == -1) {
                int idx = buscaBinariaDicionario(dic, 0, *totalDic - 1, palavra);

                if (idx != -1) {
                    dic[idx].frequencia++;
                } else {
                    inserirDicionarioOrdenado(dic, totalDic, palavra);
                }
            }
            pos = 0;
        }
    }

    if (pos > 0) {
        palavra[pos] = '\0';
        if (buscaBinariaStopWords(stopWords, 0, totalStop - 1, palavra) == -1) {
            int idx = buscaBinariaDicionario(dic, 0, *totalDic - 1, palavra);
            if (idx != -1) {
                dic[idx].frequencia++;
            } else {
                inserirDicionarioOrdenado(dic, totalDic, palavra);
            }
        }
    }
}

int main(void) {
    EntradaDicionario dicionario[MAX_DICIONARIO];
    char stopWords[MAX_STOPWORDS][MAX_TAM_PALAVRA];

    int totalDicionario = 0;
    int totalStopWords = 0;

    lerStopWords(stopWords, &totalStopWords);

    processarTextoBase(dicionario, &totalDicionario, stopWords, totalStopWords);

    for (int i = 0; i < totalDicionario; i++) {
        printf("%s, %d\n", dicionario[i].palavra, dicionario[i].frequencia);
    }

    printf("\ntotal de palavras diferentes no dicionario = %d\n", totalDicionario);

    return 0;
}