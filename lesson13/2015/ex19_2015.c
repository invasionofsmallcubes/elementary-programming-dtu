#include <stdio.h>
typedef struct {
    int    nr;
    double pris;
} Kursustype;
int main(int argc, char **argv) {
    Kursustype kursusliste[5], salgsliste[5];
    int        i;
    for (i = 0; i < 5; i++) {
        kursusliste[i].nr   = i + 1;
        kursusliste[i].pris = 5000 * (i + 1);
    }
    for (i = 0; i < 5; i++)
        salgsliste[i] = kursusliste[i];
    printf("\nFølgende kurser er overført til salgslisten:\n");
    for (i = 2; i < 5; i++)
        printf("Nr %d\tpris %.2f \n", salgsliste[i].nr, salgsliste[i].pris);
    return 0;
}