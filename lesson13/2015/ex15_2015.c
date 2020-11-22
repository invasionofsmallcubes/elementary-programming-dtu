#include <stdio.h>
void Beregn(int *pris, int *ialt);
int  main(int argc, char **argv) {
    int pris = 50, ialt = 5;
    Beregn(&pris, &ialt);
    printf("Efter beregningen:\n");
    printf("pris %d og ialt %d\n", pris, ialt);
    return 0;
}
void Beregn(int *pris, int *ialt) {
    *pris = *pris * *ialt;
    printf("I funktionen:\n");
    printf("pris %d og ialt %d\n", *pris, *ialt);
}