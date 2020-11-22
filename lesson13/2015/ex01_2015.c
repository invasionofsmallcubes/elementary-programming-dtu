#include <stdio.h>
int main(int argc, char **argv) {
    int    a = 5, b = 20;
    double d = 100.0, e = 20.0;
    printf("Indtast et heltal: "); // 10
    scanf("%d", &a);
    printf("Indtast et decimaltal: "); // 10.0
    scanf("%lf", &e);
    b = b / a;
    d = d * e;
    printf("b= %d d= %f\n", b, d);
    return 0;
}