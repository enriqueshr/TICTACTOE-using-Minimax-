#include <stdio.h>
#include <stdlib.h>

char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};

// Function to print the Tic Tac Toe board
void printBoard() {
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("-----------\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("-----------\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
}

// Function to check if a player has won
int checkWin(char player) {
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return 1;  // Player has won
        }
    }

    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return 1;  // Player has won
    }

    return 0;  // No winner yet
}

// Function to check if the board is full
int isBoardFull() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return 0;  // Board is not full
            }
        }
    }
    return 1;  // Board is full
}

// Function to evaluate the score of the board
int evaluate() {
    if (checkWin('X')) {
        return -1;  // User wins
    } else if (checkWin('O')) {
        return 1;   // Computer wins
    } else {
        return 0;   // Draw
    }
}

// Function to check if a move is valid
int isValidMove(int row, int col) {
    return (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ');
}

// Function to save the current game state to a file
void saveGame(FILE *file) {
    fwrite(board, sizeof(board[0][0]), 3 * 3, file);
}

// Function to load a saved game state from a file
void loadGame(FILE *file) {
    fread(board, sizeof(board[0][0]), 3 * 3, file);
}

// Main game loop
int main() {
    int userRow, userCol;
    FILE *file;

    printf("Tic Tac Toe - You are 'X', and the computer is 'O'\n");

    while (1) {
        // User's turn
        printf("Enter your move (row and column, e.g., 1 2): ");
        scanf("%d %d", &userRow, &userCol);

        if (isValidMove(userRow - 1, userCol - 1)) {
            board[userRow - 1][userCol - 1] = 'X';
        } else {
            printf("Invalid move. Try again.\n");
            continue;
        }

        printBoard();

        if (checkWin('X')) {
            printf("Congratulations! You win!\n");
            break;
        }

        if (isBoardFull()) {
            printf("It's a draw!\n");
            break;
        }

        // Save the game state to a file
        file = fopen("tictactoe_save.txt", "wb");
        if (file == NULL) {
            fprintf(stderr, "Error opening file for writing.\n");
            exit(1);
        }
        saveGame(file);
        fclose(file);

        // Load a saved game state from a file
        file = fopen("tictactoe_save.txt", "rb");
        if (file == NULL) {
            fprintf(stderr, "Error opening file for reading.\n");
            exit(1);
        }
        loadGame(file);
        fclose(file);

        // Computer's turn
        printf("Computer's move...\n");
        // Assume a simple computer move for illustration
        int compRow, compCol;
        do {
            compRow = rand() % 3;
            compCol = rand() % 3;
        } while (!isValidMove(compRow, compCol));
        board[compRow][compCol] = 'O';

        printBoard();

        if (checkWin('O')) {
            printf("Computer wins! Better luck next time.\n");
            break;
        }

        if (isBoardFull()) {
            printf("It's a draw!\n");
            break;
        }
    }

    return 0;
}
