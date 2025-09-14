#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Nível Novato - Posicionamento dos Navios (um horizontal e um vertical); inicialização do tabuleiro 10x10.

// LEGENDA: 0 - Água | 3 - Navio

// Definindo uma constante para o tamanho do tabuleiro
#define LIN 10
#define COL 10

// Código para a exibição do tabuleiro
void exibirTabuleiro(int tabuleiro[LIN][COL]){
    int linha, coluna;

        printf("\t");
    for (char col = 'A'; col <= 'J'; col++){
        printf("%c  ", col);
    }
    printf("\n");
    for (linha = 0; linha < 10; linha++){
        printf("%d\t", linha + 1);
        for (coluna = 0; coluna < 10; coluna++){
            printf("%d  ", tabuleiro[linha][coluna]);
        }
        printf("\n");
    };
    printf("\n");
}

int main() {
    // Inicialização do tabuleiro
    int tabuleiro[LIN][COL] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };
    // Inicialização dos navios e definição de suas coordenadas
    int navioUm[3] = {3, 3, 3};
    int navioDois[3] = {3, 3, 3};
    int navioTres[3] = {3, 3, 3};
    int navioQuatro[3] = {3, 3, 3};

    int linhaNavioUm = 0;
    int colunaNavioUm = 3;
    int linhaNavioDois = 6;
    int colunaNavioDois = 7;
    int linhaNavioTres = 1;
    int colunaNavioTres = 1;
    int linhaNavioQuatro = 7;
    int colunaNavioQuatro = 3;

    // Variáveis auxiliares
    int linha, coluna, i;

    // Mensagem de entrada
    printf("Alto lá, marujo! Uma batalha naval nos aguarda!\n");
    printf("Vamos posicionar nossos navios!\n\n");

    // Exibição do tabuleiro apenas com água (representada por 0)
    exibirTabuleiro(tabuleiro);

    // Posicionamento do primeiro navio
    printf("Vamos colocar nosso primeiro navio na horizontal...\n");

    if (colunaNavioUm + 3 <= 10){ // verificação se o navio cabe no tabuleiro
        for (i = 0; i < 3; i++){
            tabuleiro[linhaNavioUm][colunaNavioUm + i] = navioUm[i];
        }
        printf("Navio posicionado! Suas coordenadas são: ");
        for (i = 0; i < 3; i++) { // exibição de coordenadas
            printf("%c%d ", (char)('A' + colunaNavioUm + i), linhaNavioUm + 1);
    }
        printf("\n\n");
    } else {
        printf("O navio não cabe no tabuleiro!\n\n");
    };

    // Posicionamento do segundo navio
    printf("Agora, colocaremos nosso segundo navio na vertical...\n");

    if (linhaNavioDois + 3 <= 10){ // verificação se o navio cabe no tabuleiro
        int semSobreposicao = 1; // flag de verificação de sobreposição

        for (i = 0; i < 3; i++){
            if (tabuleiro[linhaNavioDois + i][colunaNavioDois] != 0){
                semSobreposicao = 0;
                break;
            }
        }
        if (semSobreposicao == 1) {
            for (i = 0; i < 3; i++){
            tabuleiro[linhaNavioDois + i][colunaNavioDois] = navioDois[i];
            }
        printf("Navio posicionado! Suas coordenadas são: ");
        for (i = 0; i < 3; i++) { // exibição de coordenadas
            printf("%c%d ", (char)('A' + colunaNavioDois), (linhaNavioDois + i) + 1);
        }
        printf("\n\n");
        } else {
        printf("Impossível fazer isso, as coordenadas já estão ocupadas!\n\n");
        }
    } else {
    printf("O navio não cabe no tabuleiro!\n\n");
    }

    // Posicionamento do terceiro navio
    printf("E um navio na diagonal, assim eles não nos verão chegando!\n");

    if (linhaNavioTres + 3 <= 10){ // verificação se o navio cabe no tabuleiro
        int semSobreposicao = 1; // flag de verificação de sobreposição

        for (i = 0; i < 3; i++){
            if (tabuleiro[linhaNavioTres + i][colunaNavioTres + i] != 0){
                semSobreposicao = 0;
                break;
            }
        }
        if (semSobreposicao == 1) {
            for (i = 0; i < 3; i++){
            tabuleiro[linhaNavioTres + i][colunaNavioTres + i] = navioTres[i];
            }
        printf("Navio posicionado! Suas coordenadas são: ");
        for (i = 0; i < 3; i++) { // exibição de coordenadas
            printf("%c%d ", (char)(('A' + colunaNavioTres) + i), (linhaNavioTres + i) + 1);
        }
        printf("\n\n");
        } else {
        printf("Impossível fazer isso, as coordenadas já estão ocupadas!\n\n");
        }
    } else {
    printf("O navio não cabe no tabuleiro!\n\n");
    }

    // Posicionamento do quarto navio
    printf("MAIS! Mais um na diagonal! Precisamos garantir vantagem!\n");

    if (linhaNavioQuatro + 3 <= 10){ // verificação se o navio cabe no tabuleiro
        int semSobreposicao = 1; // flag de verificação de sobreposição

        for (i = 0; i < 3; i++){
            if (tabuleiro[linhaNavioQuatro + i][colunaNavioQuatro - i] != 0){
                semSobreposicao = 0;
                break;
            }
        }
        if (semSobreposicao == 1) {
            for (i = 0; i < 3; i++){
            tabuleiro[linhaNavioQuatro + i][colunaNavioQuatro - i] = navioQuatro[i];
            }
        printf("Navio posicionado! Suas coordenadas são: ");
        for (i = 0; i < 3; i++) { // exibição de coordenadas
            printf("%c%d ", (char)(('A' + colunaNavioQuatro) - i), (linhaNavioQuatro + i) + 1);
        }
        printf("\n\n");
        } else {
        printf("Impossível fazer isso, as coordenadas já estão ocupadas!\n\n");
        }
    } else {
    printf("O navio não cabe no tabuleiro!\n\n");
    }

    // Exibição do tabuleiro com os navios posicionados (representados por 3)
    printf("Muito bem, marinheiro! Vamos ver como ficaram nossas belezuras em alto mar!\n\n");
    exibirTabuleiro(tabuleiro);

    return 0;
}
