#include <stdio.h>
int main(int argc, char **argv) {
    int a = 10, b;
    a     = a + 10;
    b     = a - 10;
    if (b < 10)
        b /= 10;
    else
        b += 10;
    printf("Tal b= %d", b);
    return 0;
}