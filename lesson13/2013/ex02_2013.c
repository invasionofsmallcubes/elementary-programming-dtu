#include <stdio.h>
#include <stdlib.h>
int main(void) {
    int   tal1;
    float tal2 = 40.5;
    printf("Indtast et heltal: "); // Indtast et heltal: 10
    fflush(stdout);
    scanf("%d", &tal1);
    printf("Indtast et decimaltal: "); // Indtast et decimaltal: 20.5
    fflush(stdout);
    scanf("%f", &tal2);
    tal2 = tal1 + tal2;
    printf("\nFølgende tal er gemt: %d %.4f", tal1, tal2);
    return EXIT_SUCCESS;
}