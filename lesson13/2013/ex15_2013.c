#include <stdio.h>
#include <stdlib.h>
int main(void) {
    char navn[50], fornavn[20] = "Anders";
    char efternavn[20] = "Bertelsen";
    int  svar;
    strcpy(navn, fornavn);
    strcat(navn, " ");
    strcat(navn, efternavn);
    printf("%s \n", navn);
    svar = strcmp(fornavn, efternavn);
    if (svar < 0)
        printf("%s er mindre end %s\n", fornavn, efternavn);
    else if (svar == 0)
        printf("%s er lig med %s\n", fornavn, efternavn);
    else
        printf("%s er større end %s\n", fornavn, efternavn);
    return EXIT_SUCCESS;
}