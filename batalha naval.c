#include<stdio.h>

// Função para aplicar a matriz de habilidade no tabuleiro
void aplicar_habilidade(int tabuleiro[10][10], int habilidade[5][5], int origem_linha, int origem_coluna) {
    int escudo = 2; // centro da matriz 5x5
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int tab_i = origem_linha - escudo + i;
            int tab_j = origem_coluna - escudo + j;
            if (habilidade[i][j] == 1 &&
                tab_i >= 0 && tab_i < 10 &&
                tab_j >= 0 && tab_j < 10 &&
                tabuleiro[tab_i][tab_j] != 3) // não sobrescreve navio
            {
                tabuleiro[tab_i][tab_j] = 5;
            }
        }
    }
}

int main() {
    char colunas[10] = {'A','B','C','D','E','F','G','H','I','J'};
    int tabuleiro[10][10];

    // Inicializa o tabuleiro com água (0)
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Posiciona navio1 horizontalmente na linha 2, colunas 3,4,5
    int linha1 = 1;
    int col_inicio1 = 3;
    for (int k = 0; k < 3; k++) {
        tabuleiro[linha1][col_inicio1 + k] = 3;
    }

    // Navio na diagonal principal (↘) começando em (linha 0, coluna 0)
    for (int k = 0; k < 3; k++) {
        tabuleiro[0 + k][0 + k] = 3;
    }

    // Posiciona navio2 verticalmente na coluna 9, linhas 5,6,7
    int coluna2 = 9;
    int lin_inicio2 = 5;
    for (int k = 0; k < 3; k++) {
        tabuleiro[lin_inicio2 + k][coluna2] = 3;
    }

    // Navio na diagonal secundária (↙) começando em (linha 5, coluna 6)
    for (int k = 0; k < 3; k++) {
        tabuleiro[0 + k][9 - k] = 3;
    }

    // Matrizes de habilidade 5x5
    int cone[5][5] = {
        {0,0,1,0,0},
        {0,1,1,1,0},
        {1,1,1,1,1},
        {0,0,0,0,0},
        {0,0,0,0,0}
    };

    int cruz[5][5] = {
        {0,0,0,0,0},
        {0,0,1,0,0},
        {1,1,1,1,1},
        {0,0,1,0,0},
        {0,0,0,0,0}
    };

    int octaedro[5][5] = {
        {0,0,0,0,0},
        {0,0,1,0,0},
        {0,1,1,1,0},
        {0,0,1,0,0},
        {0,0,0,0,0}
    };

    // Aplica habilidades em diferentes pontos do tabuleiro
    aplicar_habilidade(tabuleiro, cone, 2, 2);      // Cone no ponto (2,2)
    aplicar_habilidade(tabuleiro, cruz, 7, 7);      // Cruz no ponto (7,7)
    aplicar_habilidade(tabuleiro, octaedro, 5, 5);  // Octaedro no ponto (5,5)

    // Exibe o tabuleiro
    printf("   ");
    for (int j = 0; j < 10; j++) {
        printf("%c ", colunas[j]);
    }
    printf("\n");
    for (int i = 0; i < 10; i++) {
        printf("%2d ", i + 1);
        for (int j = 0; j < 10; j++) {
            if (tabuleiro[i][j] == 0)
                printf("~ ");
            else if (tabuleiro[i][j] == 3)
                printf("3 ");
            else if (tabuleiro[i][j] == 5)
                printf("# ");
            else
                printf("? ");
        }
        printf("\n");
    }

    return 0;
}
    
   
   

    

   