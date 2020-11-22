#include <stdio.h>
#include <stdlib.h>
#define N 10
void Funktion(int *tabel);
int main() {
    int i, tabel[N] = {1, 2, 3, 4, 5};
    Funktion(tabel);
    printf("Efter funktionen:\n");
    for (i = 0; i < N; i++)
        printf("i: %d\t%d\n", i, *(tabel + i));
    return EXIT_SUCCESS;
}
void Funktion(int *tabel) {
    int i;
    printf("\nI funktionen:\n");
    for (i = 0; i < N; i++)
        printf("i: %d\t%d\n", i, *(tabel + i));
    for (i = 0; i < N; i++)
        *(tabel + i) += 2;
}