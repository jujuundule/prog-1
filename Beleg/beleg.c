
#include <stdio.h>

#define ROWS 6
#define COLS 7

char board[ROWS][COLS];

void initializeBoard() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = ' ';
        }
    }
}

void printBoard() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("| %c ", board[i][j]);
        }
        printf("|\n");
    }
    printf("-----------------------------\n");
}

int dropPiece(int col, char player) {
    for (int i = ROWS - 1; i >= 0; i--) {
        if (board[i][col] == ' ') {
            board[i][col] = player;
            return 1;  // Successful move
        }
    }
    return 0;  // Column is full
}

int checkWin(char player) {
    // TODO: Implement the win-checking logic
    return 0;
}

int main() {
    char currentPlayer = 'X';
    int column;

    initializeBoard();

    do {
        printBoard();
        printf("Spieler %c, wählen Sie eine Spalte (0-6): ", currentPlayer);
        scanf("%d", &column);

        if (column < 0 || column >= COLS) {
            printf("Ungültige Spalte. Bitte wählen Sie erneut.\n");
            continue;
        }

        if (dropPiece(column, currentPlayer)) {
            if (checkWin(currentPlayer)) {
                printBoard();
                printf("Spieler %c gewinnt!\n", currentPlayer);
                break;
            }

            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';  // Wechsel des Spielers
        } else {
            printf("Spalte ist voll. Bitte wählen Sie erneut.\n");
        }

    } while (1);  // Endlosschleife für das Spiel

    return 0;
}