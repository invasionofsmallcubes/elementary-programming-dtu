#include <stdio.h>
int power(int x, int n) {
    int result = 1;
    for (; n > 0; n = n - 1) {
        result = result * x;
    }
    printf("n: %d\n", n);
    return result;
}

int main(void) {
    int n = 4;
    printf("%d\n", power(3, n));
    printf("n: %d\n", n);
}