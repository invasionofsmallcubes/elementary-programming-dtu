#include <stdio.h>
#include <stdlib.h>
void Funktion(float *t1, int *t2) {
    *t2 *= *t2;
    *t1 += *t1;
    printf("Værdi i funktionen: %d %.1f\n", *t2, *t1);
}
int main(void) {
    float t1 = 1;
    int   t2 = 2;
    Funktion(&t1, &t2);
    printf("Værdi i main: %d %.1f\n", t2, t1);
    return EXIT_SUCCESS;
}