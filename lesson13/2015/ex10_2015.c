#include <stdio.h>
#define ANTAL1 3
#define ANTAL2 4
int main(int argc, char **argv) {
    int i, j, tal = 0;
    int tabel[ANTAL1][ANTAL2] = {{10, 20, 30, 40}, {50, 60, 70, 80}, {90, 100, 110, 130}};
    for (i = 0; i < ANTAL1; i++)
        for (j = 0; j < ANTAL2; j++) {
            tal = tal + tabel[i][j];
        }
    printf("tal = %.6d", tal);
    return 0;
}