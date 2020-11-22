#include <stdio.h>
int main(int argc, char **argv) {
    int i;
    int tabel[] = {5, 10, 15, 20, 25, 30};
    for (i = 0; i < 5; i++)
        printf("%d\t", tabel[i] * i);
    return 0;
}