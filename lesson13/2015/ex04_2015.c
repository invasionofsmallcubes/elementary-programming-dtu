#include <stdio.h>
int main(int argc, char **argv) {
    int a = 1, b = 2, c = 3;
    int svar = 3;
    switch (svar) {
    case 0:
        c = ++a + ++b;
        printf("c= %d", c);
        break;
    case 1:
        c = a++ + b++;
        printf("c= %d", c);
        break;
    case 2:
        c = a++ + ++b;
        printf("c= %d", c);
        break;
    case 3:
        c = ++a + b++ + 4;
        printf("c= %d", c);
        break;
    default:
        printf("c= %d", c);
    }
    return 0;
}