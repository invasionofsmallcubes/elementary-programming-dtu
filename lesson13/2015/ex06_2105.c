#include <stdio.h>
int main(int argc, char **argv) {
    int a = 5, b;
    do {
        b = 10;
        a = a + b;
        printf("\n%d\t%d\t", a, b);
    } while (a < 50);
    return 0;
}