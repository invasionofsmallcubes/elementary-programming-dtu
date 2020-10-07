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
          if(matrix[cellI][cellJ] != BOMB) {
            int bombCounter = 0;
            // top left is r-1 c-1
            if(matrix[cellI-1][cellJ-1] == BOMB) {
              bombCounter = bombCounter + 1;
            }
            // top is r-1 c
            if(matrix[cellI-1][cellJ] == BOMB) {
              bombCounter = bombCounter + 1;
            }
            // top right is r-1 c+1
            if(matrix[cellI-1][cellJ+1] == BOMB) {
              bombCounter = bombCounter + 1;
            }
            // left is r c-1
            if(matrix[cellI][cellJ-1] == BOMB) {
              bombCounter = bombCounter + 1;
            }
            // right is r c+1
            if(matrix[cellI][cellJ+1] == BOMB) {
              bombCounter = bombCounter + 1;
            }
            // bottom left is r+1 c-1
            if(matrix[cellI+1][cellJ-1] == BOMB) {
              bombCounter = bombCounter + 1;
            }
            // bottom is r+1 c
            if(matrix[cellI+1][cellJ] == BOMB) {
              bombCounter = bombCounter + 1;
            }
            // bottom left is r+1 c+1
            if(matrix[cellI+1][cellJ+1] == BOMB) {
              bombCounter = bombCounter + 1;
            }
            matrix[cellI][cellJ] = bombCounter;
          } 
        }
    }

    do {
        printMatrix(ROW, COLUMN, fogOfWar, matrix);
        printf("Tell me row and column like this i,j : ");
        int row;
        int column;
        scanf("%d,%d", &row, &column);
        if (minefield[row][column] == BOMB) {
            gameIsOn = FALSE;
            printf("you lose!\n");
        }
        fogOfWar[row][column] = FALSE;
    } while (gameIsOn);
}