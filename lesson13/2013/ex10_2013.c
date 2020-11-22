#include <stdio.h>
#include <stdlib.h>
void Funktion(float tal) {
    tal *= 10;
    printf("Værdien i funktionen: %.2f\n", tal);
}
int main(void) {
    float tal = 10.50;
    Funktion(tal);
    printf("Værdien i main: %.2f\n", tal);
    return EXIT_SUCCESS;
}