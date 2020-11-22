#include <stdio.h>
#include <stdlib.h>
int main(void) {
    int i;
    for (i = 1; i <= 10; i++) {
        if (i % 2 == 0)
            printf("%d\t", i);
    };
    return EXIT_SUCCESS;
}