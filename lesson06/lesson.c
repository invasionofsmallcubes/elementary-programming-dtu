// show the field on console
// understand if current cell has a mine on it
// understand what's the situation in neighbour cells
// win the game
// lose the game

#include <stdio.h>

#define ROW 3
#define COLUMN 3
#define EMPTY_CELL 'e'
#define HIDDEN_CELL '*'
#define BOMB 'b'

#define TRUE 1
#define FALSE 0

typedef short boolean;

void printMatrix(int     row,
                 int     columns,
                 boolean fogOfWar[][columns],
                 char    matrix[][columns]) {
    for (int i = 0; i < row; i = i + 1) {
        for (int j = 0; j < columns; j = j + 1) {
            if (fogOfWar[i][j] == FALSE) {
                printf("%c ", matrix[i][j]);
            } else {
                printf("%c ", HIDDEN_CELL);
            }
        }
        printf("\n");
    }
}

int main(void) {
    char minefield[ROW][COLUMN];
    for (int i = 0; i < ROW; i = i + 1) {
        for (int j = 0; j < COLUMN; j = j + 1) {
            minefield[i][j] = EMPTY_CELL;
        }
    }
    minefield[0][0] = BOMB;
    minefield[2][2] = BOMB;

    boolean fogOfWar[ROW][COLUMN];
    for (int i = 0; i < ROW; i = i + 1) {
        for (int j = 0; j < COLUMN; j = j + 1) {
            fogOfWar[i][j] = TRUE;
        }
    }

    boolean gameIsOn = TRUE;

    for (int i = 0; i < ROW; i = i + 1) {
        for (int j = 0; j < COLUMN; j = j + 1) {
            int cellI = i;
            int cellJ = j;
            if (minefield[cellI][cellJ] != BOMB) {
                printf("Current Center is (%d,%d)\n", cellI, cellJ);
                int bombCount = 0;
                for (int x = -1; x <= 1; x = x + 1) {
                    for (int y = -1; y <= 1; y = y + 1) {
                        int cellX = cellI + x;
                        int cellY = cellJ + y;
                        if (minefield[cellX][cellY] == BOMB && cellX > -1 && cellY > -1
                            && cellX < ROW && cellY < COLUMN) {
                            printf("I'm evaluating (%d, %d)\n", cellX, cellY);
                            bombCount = bombCount + 1;
                        }
                    }
                }
                char c = '1';
                if(bombCount > 0) {
                  printf("%d \n", bombCount);
                  minefield[cellI][cellJ] = '0' + bombCount ;
                  printf("%c \n", minefield[cellI][cellJ]);
                }
                printf(
                    "Current bomb count for (%d, %d) is %d\n", cellI, cellJ, bombCount);
            }
        }
    }

    for (int i = 0; i < ROW; i = i + 1) {
        for (int j = 0; j < COLUMN; j = j + 1) {
            printf("%c ", minefield[i][j]);
        }
        printf("\n");
    }

    // do {
    //     printMatrix(ROW, COLUMN, fogOfWar, matrix);
    //     printf("Tell me row and column like this i,j : ");
    //     int row;
    //     int column;
    //     scanf("%d,%d", &row, &column);
    //     if (minefield[row][column] == BOMB) {
    //         gameIsOn = FALSE;
    //         printf("you lose!\n");
    //     }
    //     fogOfWar[row][column] = FALSE;
    // } while (gameIsOn);
}