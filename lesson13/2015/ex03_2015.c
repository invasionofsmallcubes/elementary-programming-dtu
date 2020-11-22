#include <stdio.h>
int main(int argc, char **argv) {
    int   a = 5, b = 10;
    float c = 15.0f, d = 20.5f;
    d = a + b;
    printf("a= %d b= %d c= %.2f d= %f\n", a, b, c, d);
    return 0;
}