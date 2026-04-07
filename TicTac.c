#include <stdio.h>
#include <stdlib.h>

#define X 1
#define O -1
#define EMPTY 0

int board[3][3]; // tabuleiro
int player;      // jogador corrente

void clearBoard() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = EMPTY;
    player = X;
}

void putMark(int i, int j) {
    if (i < 0 || i > 2 || j < 0 || j > 2 || board[i][j] != EMPTY) {
        printf("Jogada inválida!\n");
        return;
    }
    board[i][j] = player;
    player = -player;
}

int isWin(int mark) {
    return (
        (board[0][0] + board[0][1] + board[0][2] == mark * 3) ||
        (board[1][0] + board[1][1] + board[1][2] == mark * 3) ||
        (board[2][0] + board[2][1] + board[2][2] == mark * 3) ||
        (board[0][0] + board[1][0] + board[2][0] == mark * 3) ||
        (board[0][1] + board[1][1] + board[2][1] == mark * 3) ||
        (board[0][2] + board[1][2] + board[2][2] == mark * 3) ||
        (board[0][0] + board[1][1] + board[2][2] == mark * 3) ||
        (board[2][0] + board[1][1] + board[0][2] == mark * 3)
    );
}

int winner() {
    if (isWin(X)) return X;
    if (isWin(O)) return O;
    return 0;
}

void printBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            char c;
            switch (board[i][j]) {
                case X: c = 'X'; break;
                case O: c = 'O'; break;
                default: c = ' '; break;
            }
            printf("%c", c);
            if (j < 2) printf("|");
        }
        if (i < 2) printf("\n-----\n");
    }
    printf("\n");
}

void jogo() {
    int row, col, moves = 0;
    clearBoard();

    while (1) {
        printBoard();
        printf("digite linha e coluna ex:(0 0): ");
        scanf("%d %d", &row, &col);

        putMark(row, col);
        moves++;

        int win = winner();
        if (win != 0) {
            printBoard();
            printf("Jogador %c vence!\n", win == X ? 'X' : 'O');
            break;
        }

        if (moves == 9) {
            printBoard();
            printf("Empate!\n");
            break;
        }
    }
}

int main() {
    jogo();
    return 0;
}

