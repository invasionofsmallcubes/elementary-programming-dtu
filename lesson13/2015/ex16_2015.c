#include <stdio.h>
void beregn(double priser[5], double *tal) {
    int i;
    for (i = 0; i < 5; i++)
        *tal = *tal + priser[i];
    printf("\nResultatet i beregn er: %.2f", *tal);
}
int main(int argc, char **argv) {
    double priser[5] = {500, 600, 700, 800}, tal = 0;
    beregn(priser, &tal);
    printf("\nI alt i main er %.2f", tal);
    return 0;
}