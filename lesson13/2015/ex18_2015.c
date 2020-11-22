#include <stdio.h>
#include <stdlib.h>
struct Kursus {
    int            nr, antalDage;
    double         pris;
    struct Kursus *p1;
};
int main(int argc, char **argv) {
    struct Kursus *p1, *p2;
    int            i;
    p1 = NULL;
    for (i = 0; i < 5; i++) {
        p2            = malloc(sizeof(struct Kursus));
        p2->nr        = i + 1;
        p2->antalDage = i + 2;
        p2->pris      = p2->antalDage * 5000;
        p2->p1        = p1;
        p1            = p2;
    }
    printf("Priserne er:\n");
    while (p1 != NULL) {
        printf("Kursusnr. %d\t%.2f kr.\n", p1->nr, p1->pris);
        p1 = p1->p1;
    }
    return 0;
}