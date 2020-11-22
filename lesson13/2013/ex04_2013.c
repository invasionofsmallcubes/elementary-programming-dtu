#include <stdio.h>
#include <stdlib.h>
int main(void) {
    int tal2 = 10;
    do {
        int tal1 = 1;
        printf("%d\t%d\n", ++tal1, tal2);
        tal2 = tal2 * tal2;
    } while (tal2 <= 100);
    return EXIT_SUCCESS;
}