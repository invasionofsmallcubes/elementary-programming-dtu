#include <stdio.h>
#include <stdlib.h>
struct taltype {
    int             tal;
    struct taltype *peger;
};
int main(void) {
    struct taltype *p1, *p2;
    int             indtal;
    p1 = NULL;
    printf("Indtast et heltal (negativt tal for slut): ");
    fflush(stdout);
    scanf("%d", &indtal); // input: 1, 2, 3, 4, 5, -1
    while (indtal >= 0) {
        p2        = malloc(sizeof(struct taltype));
        p2->tal   = indtal;
        p2->peger = p1;
        p1        = p2;
        printf("Indtast et heltal (negativt tal for slut): ");
        fflush(stdout);
        scanf("%d", &indtal);
    }
    //udskriv liste
    printf("De indtastede tal er:\n");
    while (p1 != NULL) {
        printf("%d\t", p1->tal);
        p1 = p1->peger;
    }
    return EXIT_SUCCESS;
}