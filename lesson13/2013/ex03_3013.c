#include <stdio.h>
#include <stdlib.h>
int main(void) {
    int   i;
    float tal = 2.0;
    for (i = 1; i < 10; i++) {
        printf("%5.1f", tal * i);
    }
}