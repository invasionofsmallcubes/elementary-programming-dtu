#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void clearScreen() {
#if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
    system("clear");
#endif

#if defined(_WIN32) || defined(_WIN64)
    system("cls");
#endif
}

#define BUFFERSIZE 1024
#define FOG_OF_WAR '*'
#define BOMB 'b'
#define EMPTY 'e'

typedef short boolean;
#define TRUE 1
#define FALSE 0

FILE *readFile() {
    FILE *ptr = fopen("config.txt", "r");
    if (ptr == NULL) {
        printf("error reading file\n");
        exit(EXIT_FAILURE);
    }
    return ptr;
}

int readConfig(FILE *ptr) {
    char buffer[100];
    fgets(buffer, BUFFERSIZE, ptr);
    int config;
    sscanf(buffer, "%*s %d", &config);
    return config;
}

void debugPrintMatrix(int size, char m[][size]) {
    printf("=======\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%c ", m[i][j]);
        }
        printf("\n");
    }
    printf("=======\n");
}

// generic print function
// void printArray(void * source, int numElements, int size, void (*printFunction)(void *)){
//     int i;
//     for (i = 0; i < numElements; i++){
//         printFunction(((char *)source) + i * size);
//      }
// }

void printGrid(int     gridSize,
               char    gridContent[][gridSize],
               int     s,
               boolean gridVisibility[][s]) {
    printf("   0 1 2 3 4\n\n");
    for (int i = 0; i < gridSize; i++) {
        printf("%d  ", i);
        for (int j = 0; j < gridSize; j++) {
            char cell = gridVisibility[i][j] ? gridContent[i][j] : FOG_OF_WAR;
            printf("%c ", cell);
        }
        printf("\n");
    }
    printf("\n");
}

char countBombs(int i, int j, int s, char array[][s]) {
    /*
      top left (i-1, j-1)    - top (i-i, j)   - top right (i-1, j+1)
      left (i, j-1)          - current (i,j)  - right (i, j+1)
      bottom left (i+1, j-1) - bottom (i+1,j) - bottom right (i+1, j+1)
  */

    int bombCount = 0;

    for (int k = -1; k <= 1; k++) {
        for (int h = -1; h <= 1; h++) {
            int newI = i + k;
            int newJ = j + h;
            if (array[newI][newJ] == BOMB && newI > -1 && newJ > -1) {
                bombCount = bombCount + 1;
            }
        }
    }

    char result;
    if (bombCount >= 10) {
        result = 'A' + bombCount - 10;
    } else {
        result = '0' + bombCount;
    }

    return result;
}

void assignBombCounterOnEmptySpaces(int gridSize, char gridContent[][gridSize]) {
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {
            if (gridContent[i][j] != BOMB) {
                char bombCount = countBombs(i, j, gridSize, gridContent);
                // printf("bomb(%d,%d): %c\n", j, j, bombCount);
                gridContent[i][j] = bombCount;
            }
        }
    }
}

void assignRandomBombs(int mines, int gridSize, char gridContent[][gridSize]) {
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {
            gridContent[i][j] = EMPTY;
        }
    }
    for (int i = 0; i < mines; i++) {
        boolean isBomb;
        do {
            int x  = rand() % gridSize;
            int z  = rand() % gridSize;
            isBomb = FALSE;
            if (gridContent[x][z] == BOMB) {
                isBomb = TRUE;
            } else {
                gridContent[x][z] = BOMB;
            }
        } while (isBomb);
    }
}

void initVisibility(int s, boolean array[][s]) {
    for (int i = 0; i < s; i++) {
        for (int j = 0; j < s; j++) {
            array[i][j] = FALSE;
        }
    }
}

void enableVisibility(int     row,
                      int     column,
                      int     gridSize,
                      char    gridContent[][gridSize],
                      boolean gridVisibility[][gridSize]) {
    if (row > -1 && column > -1 && gridVisibility[row][column] == FALSE
        && gridContent[row][column] != BOMB) {
        // printf("%d %d\n", row, column);
        gridVisibility[row][column] = TRUE;
        if (gridContent[row][column] == '0') {
            // top
            enableVisibility(row - 1, column - 1, gridSize, gridContent, gridVisibility);
            enableVisibility(row - 1, column, gridSize, gridContent, gridVisibility);
            enableVisibility(row - 1, column + 1, gridSize, gridContent, gridVisibility);
            // middle
            enableVisibility(row, column - 1, gridSize, gridContent, gridVisibility);
            enableVisibility(row, column + 1, gridSize, gridContent, gridVisibility);
            // bottom
            enableVisibility(row + 1, column - 1, gridSize, gridContent, gridVisibility);
            enableVisibility(row + 1, column, gridSize, gridContent, gridVisibility);
            enableVisibility(row + 1, column + 1, gridSize, gridContent, gridVisibility);
        }
    }
}

boolean findBomb(int     row,
                 int     column,
                 int     gridSize,
                 char    gridContent[][gridSize],
                 boolean gridVisibility[][gridSize]) {
    if (gridContent[row][column] == BOMB) {
        return FALSE;
    } else {
        gridVisibility[row][column] = TRUE;
        if (gridContent[row][column] == '0') {
            /*
              top left (i-1, j-1)    - top (i-i, j)   - top right (i-1, j+1)
              left (i, j-1)          - current (i,j)  - right (i, j+1)
              bottom left (i+1, j-1) - bottom (i+1,j) - bottom right (i+1, j+1)
            */
            // top
            enableVisibility(row - 1, column - 1, gridSize, gridContent, gridVisibility);
            enableVisibility(row - 1, column, gridSize, gridContent, gridVisibility);
            enableVisibility(row - 1, column + 1, gridSize, gridContent, gridVisibility);
            // middle
            enableVisibility(row, column - 1, gridSize, gridContent, gridVisibility);
            enableVisibility(row, column + 1, gridSize, gridContent, gridVisibility);
            // bottom
            enableVisibility(row + 1, column - 1, gridSize, gridContent, gridVisibility);
            enableVisibility(row + 1, column, gridSize, gridContent, gridVisibility);
            enableVisibility(row + 1, column + 1, gridSize, gridContent, gridVisibility);
        }
        return TRUE;
    }
}

void checkWinCondition(int mines, int s, boolean visibilityMatrix[][s]) {
    int notVisibileCells = 0;
    for (int i = 0; i < s; i++) {
        for (int j = 0; j < s; j++) {
            if (visibilityMatrix[i][j] == FALSE) {
                notVisibileCells = notVisibileCells + 1;
            }
        }
    }
    //printf("not visible: %d \n", notVisibileCells);
    if (notVisibileCells == mines) {
        printf("You won!");
        exit(EXIT_SUCCESS);
    }
}

int main(void) {
    srand((unsigned)time(NULL));

    FILE *ptr      = readFile();
    int   mines    = readConfig(ptr);
    int   gridSize = readConfig(ptr);
    fclose(ptr);

    printf(
        "Initializing the game with %d mines and a grid size of %d\n\n", mines, gridSize);

    char gridContent[gridSize][gridSize];

    assignRandomBombs(mines, gridSize, gridContent);
    assignBombCounterOnEmptySpaces(gridSize, gridContent);

    debugPrintMatrix(gridSize, gridContent);

    boolean gridVisibility[gridSize][gridSize];
    initVisibility(gridSize, gridVisibility);
    boolean bombNotFound = TRUE;
    do {
        clearScreen();
        checkWinCondition(mines, gridSize, gridVisibility);
        printGrid(gridSize, gridContent, gridSize, gridVisibility);
        printf("Tell me row and column in the format row,column: ");
        int row;
        int column;
        scanf("%d,%d", &row, &column);
        printf("%d %d", row, column);
        bombNotFound = findBomb(row, column, gridSize, gridContent, gridVisibility);
        printf("\n");
    } while (bombNotFound);

    if (!bombNotFound) {
        printf("BOOM!\n");
    }

    exit(EXIT_SUCCESS);
}