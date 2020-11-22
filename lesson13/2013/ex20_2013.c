#include <stdio.h>
#include <stdlib.h>
struct taltype {
    int             tal;
    struct taltype *peger1, *peger2;
};
int main(void) {
    struct taltype *p1, *p2, *p3;
    int             i;
    p1 = NULL;
    for (i = 1; i < 10; i++) {
        p2 = malloc(sizeof(struct taltype));
        if (p1 == NULL)
            p3 = p2;
        p2->tal    = i * i;
        p2->peger1 = p1;
        if (p2->peger1 != NULL)
            p1->peger2 = p2;
        p1 = p2;
    }
    p2->peger2 = NULL;
    printf("Tallet er: %d \n", p3->tal);
    printf("Tallene er:\n");
    while (p1 != NULL) {
        printf("%d\t", p1->tal);
        p1 = p1->peger1;
    }
    return EXIT_SUCCESS;
}