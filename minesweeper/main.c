#include <stdio.h>
#include <stdlib.h>
#define ROWS 8
#define COLS 8
#define MINES 10

int board[ROWS][COLS] = {0};

void place_mines(int board[ROWS][COLS], int num_mines) {
    int count = 0;
    while (count < num_mines) {
        int row = rand() % ROWS;
        int col = rand() % COLS;
        if (board[row][col] != -1) {
            board[row][col] = -1; // -1 represents a mine
            count++;
        }
    }
}

void print_board(int board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == -1) {
                printf("* ");
            } else if (board[i][j] == 0) {
                printf(". ");
            } else {
                printf("%d ", board[i][j]);
            }
        }
        printf("\n");
    }
}


int main()
{
        place_mines(board, MINES);
    int game_over = 0;
    while (!game_over) {
        print_board(board);
        printf("Enter row and column to uncover: ");
        int row, col;
        scanf("%d %d", &row, &col);
        if (board[row][col] == -1) {
            game_over = 1;
            printf("Game over!\n");
        } else {
            // TODO: update board state
        }
    }
    print_board(board);
    return 0;
}
