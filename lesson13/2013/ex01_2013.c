#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int tal1 = 13, tal2 = 35, tal3;
    tal3       = tal1 + tal2 * 2;
    float tal4 = tal3 * 0.5;
    printf("%d %.4f", tal3, tal4);
    return EXIT_SUCCESS;
}