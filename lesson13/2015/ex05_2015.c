#include <stdio.h>
int main(int argc, char **argv) {
    int i, a = 10;
    for (i = 0; i < 5; i++)
        printf("\n%d\t%d\t", i, i * a);
    return 0;
}