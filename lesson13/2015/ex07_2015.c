#include <stdio.h>
int main(int argc, char **argv) {
    int a = 5, b = 10;
    while (10 <= b && b <= 25) {
        if (b == 10)
            b += ++a;
        else if (b < 50)
            b += a++;
        else
            b = 2 * b;
        printf("b= %d\n", b);
    }
    return 0;
}