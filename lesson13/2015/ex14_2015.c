#include <stdio.h>
void visPriser(double vareliste[5], double *tal) {
    int i;
    for (i = 0; i < 5; i++)
        *tal = *tal + vareliste[i];
}
int main(int argc, char **argv) {
    double vareliste[5] = {10, 20, 30, 40, 50}, tal = 0;
    visPriser(vareliste, &tal);
    printf("\nResultatet er: %.2f", tal);
    return 0;
}