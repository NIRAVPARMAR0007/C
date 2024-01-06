#include <stdio.h>
#include <stdlib.h>

void displayBoard(char board[3][3]) {
    system("clear || cls");
    printf("-------------\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("| %c ", board[i][j]);
        }
        printf("|\n-------------\n");
    }
}

int checkWinner(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1; // column
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return 1; // row
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return 1; /* \ */
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return 1; // /
    }

    // draw
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return 0;
            }
        }
    }

    return -1; // Draw
}

int main() {
    int position;
    char currentPlayer = 'X';
    int moves = 0;

    char board[3][3] = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}
    };

    do {
        displayBoard(board);

        printf("Player %c, enter your move (position 1-9): ", currentPlayer);
        scanf("%d", &position);

        int row = (position - 1) / 3;
        int column = (position - 1) % 3;

        if (position < 1 || position > 9 || board[row][column] == 'X' || board[row][column] == 'O') {
            printf("Invalid move. Try again.\n");
            continue;
        }

        board[row][column] = currentPlayer;

        int result = checkWinner(board);

        if (result == 1) {
            displayBoard(board);
            printf("Player %c wins!\n", currentPlayer);
            break;
        } else if (result == -1) {
            displayBoard(board);
            printf("It's a draw!\n");
            break;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        moves++;

    } while (moves < 9);

    return 0;
}
