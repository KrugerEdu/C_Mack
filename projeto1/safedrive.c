#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_AMOSTRAS 100

// Funcoes:
float calcularMediana(float a, float b, float c) {
    float temp;
    if (a > b) { temp = a; a = b; b = temp; }
    if (a > c) { temp = a; a = c; c = temp; }
    if (b > c) { temp = b; b = c; c = temp; }
    return b;
}

void fusaoSensores(float frontais[][3], float processamento[][2], int indice) {
    processamento[indice][0] = calcularMediana(frontais[indice][0], frontais[indice][1], frontais[indice][2]);
}

void calculoDistanciaSegura(float velocidades[][2], float processamento[][2], int indice, int sensibilidade, int atrito) {
    float vel_ms = velocidades[indice][0] / 3.6; // Conversão de km/h para m/s
    float tempo_reacao = 1.0; 
    
    if (sensibilidade == 2) tempo_reacao = 1.5;
    else if (sensibilidade == 3) tempo_reacao = 2.0;

    float dist = (vel_ms * tempo_reacao) + ((vel_ms * vel_ms) / (2.0 * atrito * 9.81));
    processamento[indice][1] = dist;
}

void analiseRiscoFrontal(float velocidades[][2], float processamento[][2], int status[][3], int indice) {
    float vel_rel = velocidades[indice][0] - velocidades[indice][1];
    float validada = processamento[indice][0];
    float segura = processamento[indice][1];

    if (vel_rel <= 0) {
        status[indice][0] = 0; // seguro
    } else {
        if (validada >= segura) {
            status[indice][0] = 0; // dnv seguro
        } else if (validada >= (0.5 * segura)) {
            status[indice][0] = 1; // atenção
        } else {
            status[indice][0] = 2; // risco de colisão
        }
    }
}

void assistenteFaixa(float velocidades[][2], float laterais[][2], int status[][3], int indice) {
    float vel_atual = velocidades[indice][0];
    float margem_dinamica = 0.50;

    if (vel_atual > 80.0) {
        margem_dinamica += (vel_atual - 80.0) * 0.01;
    }
    
    float zona_atencao = margem_dinamica + 0.20;

    for (int lado = 0; lado < 2; lado++) {
        float leitura = laterais[indice][lado];
        if (leitura < margem_dinamica) {
            status[indice][lado + 1] = 2; // perigo de Invasão
        } else if (leitura <= zona_atencao) {
            status[indice][lado + 1] = 1; // atenção
        } else {
            status[indice][lado + 1] = 0; // normal
        }
    }
}

int carregarDadosIniciais(float vel[][2], float frontais[][3], float laterais[][2], int qtde_atual) {
    if (qtde_atual + 50 > MAX_AMOSTRAS) return qtde_atual;

    for (int i = qtde_atual; i < qtde_atual + 50; i++) {
        vel[i][0] = 50.0 + (rand() % 70); // de 50 a 119
        vel[i][1] = 40.0 + (rand() % 80); // de 40 a 119
        
        frontais[i][0] = 10.0 + (rand() % 100); 
        frontais[i][1] = frontais[i][0] + ((rand() % 10) - 5); 
        frontais[i][2] = frontais[i][0] + ((rand() % 10) - 5); 
        
        laterais[i][0] = 0.3 + ((rand() % 100) / 100.0);
        laterais[i][1] = 0.3 + ((rand() % 100) / 100.0);
    }
    return qtde_atual + 50;
}

void exibirRelatorio(float vel[][2], float frontais[][3], float laterais[][2], float processamento[][2], int status[][3], int num_amostras) {
    printf("\n--- RELATORIO DE RISCOS E TELEMETRIA ---\n");
    for (int i = 0; i < num_amostras; i++) {
        printf("\n[Amostra %d]\n", i + 1);
        printf("1. Dados de entrada:\n");
        printf("   - Velocidade Atual: %.2f km/h | Veiculo Frente: %.2f km/h\n", vel[i][0], vel[i][1]);
        printf("   - Sensores Frontais -> Radar: %.2f | Lidar: %.2f | Camera: %.2f\n", frontais[i][0], frontais[i][1], frontais[i][2]);
        printf("   - Sensores Laterais -> Faixa Esq: %.2f | Faixa Dir: %.2f\n", laterais[i][0], laterais[i][1]);
        
        printf("2. Dados processados:\n");
        printf("   - Distancia Validada: %.2f m\n", processamento[i][0]);
        printf("   - Distancia Segura Exigida: %.2f m\n", processamento[i][1]);
        
        printf("3. Status do Sistema:\n");
        
        // Frontal
        printf("   - Status Frontal: ");
        if (status[i][0] == 0) printf("SEGURO\n");
        else if (status[i][0] == 1) printf("ATENCAO\n");
        else printf("RISCO DE COLISAO (AEB ACIONADO)\n");

        // Laterais
        for (int lado = 1; lado <= 2; lado++) {
            printf("   - Faixa %s: ", (lado == 1) ? "Esquerda" : "Direita");
            if (status[i][lado] == 0) printf("NORMAL\n");
            else if (status[i][lado] == 1) printf("ATENCAO\n");
            else printf("PERIGO DE INVASAO\n");
        }

        // Decisão Geral
        printf("4. DECISAO GERAL: ");
        if (status[i][0] == 2 || status[i][1] == 2 || status[i][2] == 2) {
            printf("STATUS GERAL: INTERVENCAO CRITICA EXIGIDA\n");
        } else if (status[i][0] == 1 || status[i][1] == 1 || status[i][2] == 1) {
            printf("STATUS GERAL: ATENCAO\n");
        } else {
            printf("STATUS GERAL: NORMAL\n");
        }
        printf("----------------------------------------\n");
    }
}


int main() {
    srand(time(NULL));

    float velocidade[MAX_AMOSTRAS][2];
    float sensores_frontais[MAX_AMOSTRAS][3];
    float sensores_laterais[MAX_AMOSTRAS][2];
    float processamento[MAX_AMOSTRAS][2];
    int status[MAX_AMOSTRAS][3];
    int amostras_atuais = 0;

    int atrito;
    int sensibilidade;
    
    printf("Informacoes Iniciais\nMe diga o atrito da via: \n");
    scanf("%d", &atrito);
    printf("Agora me indique a Sensibilidade do ADAS\n(1-Esportivo, 2-Normal, 3-Seguro)\n");
    scanf("%d", &sensibilidade);

    int opcao = 0;
    do {
        printf("\n--SafeDrive--\n");
        printf("1) Carregar dados iniciais (50 aleatorios)\n");
        printf("2) Inserir nova amostra\n");
        printf("3) Processar e exibir Relatorio de risco\n");
        printf("4) Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                amostras_atuais = carregarDadosIniciais(velocidade, sensores_frontais, sensores_laterais, amostras_atuais);
                printf("Dados carregados, amostras atuais: %d\n", amostras_atuais);
                break;
                
            case 2:
                if (amostras_atuais < MAX_AMOSTRAS) {
                    printf("Inserindo amostra %d:\n", amostras_atuais + 1);
                    printf("Velocidade atual e Veiculo a frente (separados por espaco): ");
                    scanf("%f %f", &velocidade[amostras_atuais][0], &velocidade[amostras_atuais][1]);
                    
                    printf("Leituras frontais - Radar, Lidar e Camera: ");
                    scanf("%f %f %f", &sensores_frontais[amostras_atuais][0], &sensores_frontais[amostras_atuais][1], &sensores_frontais[amostras_atuais][2]);
                    
                    printf("Distancia lateral - Esquerda e Direita: ");
                    scanf("%f %f", &sensores_laterais[amostras_atuais][0], &sensores_laterais[amostras_atuais][1]);
                    
                    amostras_atuais++;
                    printf("Amostra registrada com sucesso.\n");
                } else {
                    printf("Memoria de amostras cheia!\n");
                }
                break;
                
            case 3:
                if (amostras_atuais == 0) {
                    printf("Nenhuma amostra para processar.\n");
                } else {

                    for (int i = 0; i < amostras_atuais; i++) {
                        fusaoSensores(sensores_frontais, processamento, i);
                        calculoDistanciaSegura(velocidade, processamento, i, sensibilidade, atrito);
                        analiseRiscoFrontal(velocidade, processamento, status, i);
                        assistenteFaixa(velocidade, sensores_laterais, status, i);
                    }

                    exibirRelatorio(velocidade, sensores_frontais, sensores_laterais, processamento, status, amostras_atuais);
                }
                break;
                
            case 4:
                printf("Adios!\n");
                break;
                
            default:
                printf("Opcao invalida\n");
        }
    } while(opcao != 4);

    return 0;
}