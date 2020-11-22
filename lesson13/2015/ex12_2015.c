#include <stdio.h>
void Beregn(double a) {
    int i;
    for (i = 0; i < 5; i++)
        a = a + 5;
    printf("%.1f\t", a);
}
void Udskriv(double a) {
    printf("%.1f\t", a);
}
int main(int argc, char **argv) {
    double a = 10;
    Beregn(a);
    Udskriv(a);
    printf("%.1f\t", a);
    return 0;
}