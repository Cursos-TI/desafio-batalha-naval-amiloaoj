#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Nível Novato - Posicionamento dos Navios (um horizontal e um vertical); inicialização do tabuleiro 10x10.

// LEGENDA: 0 - Água | 3 - Navio

// Código para a exibição do tabuleiro
void exibirTabuleiro(int tabuleiro[10][10]){
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
    int tabuleiro[10][10] = {
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

    int linhaNavioUm = 0;
    int colunaNavioUm = 3;
    int linhaNavioDois = 6;
    int colunaNavioDois = 7;

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

    // Exibição do tabuleiro com os navios posicionados (representados por 3)
    exibirTabuleiro(tabuleiro);

    return 0;
}
