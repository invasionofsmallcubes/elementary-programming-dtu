#include <stdio.h>
#include <stdlib.h>
int BehandlTabel(int tabel[]) {
    int i, antal = 0;
    for (i = 0; i < 5; i++) {
        antal = antal + tabel[i];
    }
    return antal;
}
int main(void) {
    int tabel[5];
    int i;
    for (i = 0; i < 5; i++) {
        tabel[i] = i;
    }
    BehandlTabel(tabel);
    printf("\nResultatet er: %d ", BehandlTabel(tabel));
    return EXIT_SUCCESS;
}