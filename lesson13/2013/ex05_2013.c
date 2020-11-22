#include <stdio.h>
#include <stdlib.h>
int main(void) {
    int i = 0, tal = 2;
    while (i < 3) {
        i++;
        tal *= tal;
        printf("%d\t%d\n", i, ++tal);
    };
    return EXIT_SUCCESS;
}