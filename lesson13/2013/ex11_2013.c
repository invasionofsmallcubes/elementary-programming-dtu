#include <stdio.h>
#include <stdlib.h>
double Funktion(float t1, int t2);
int    main(void) {
    float t1 = 1.5f;
    int   t2 = 2;
    printf("Værdi: %d %.2f", (int)Funktion(t1, t2), Funktion(t1, t2));
    return EXIT_SUCCESS;
}
double Funktion(float t1, int t2) {
    double t3 = 0;
    t3        = t1 + t2 + t3;
    return t3;
}