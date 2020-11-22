#include <stdio.h>
#include <stdlib.h>
#define ANTAL1 2
#define ANTAL2 5
int main(void) {
    int i, j, tal = 0;
    int tabel[][ANTAL2] = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}};
    for (i = 0; i < ANTAL1; i++)
        for (j = 0; j < ANTAL2; j++)
            tal = tal + tabel[i][j];
    printf("\n\ntal = %d", tal);
    return EXIT_SUCCESS;
}