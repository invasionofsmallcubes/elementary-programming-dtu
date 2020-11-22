#include <stdio.h>
#include <stdlib.h>
int main(void) {
    int   i;
    char *theBigFive[] = {"elefant", "næsehorn", "bøffel", "løve", "leopard"};
    *(theBigFive + 4)  = "giraf";
    printf("\nTabellen "
           "theBigFive"
           ":\n");
    for (i = 0; i < 5; i++)
        printf("%s \t", *(theBigFive + i));
    return EXIT_SUCCESS;
}