#include <stdio.h>
#include <stdlib.h>
int Funktion(char *tekst);
int main(void) {
    int  svar;
    char tekst[] = "Dette er et eksempel til eksamen.";
    svar         = Funktion(tekst);
    printf("Følgende værdi returneres: %d \n", svar);
    return EXIT_SUCCESS;
}
int Funktion(char *tekst) {
    int i, antal = 0;
    for (i = 0; *(tekst + i) != '\0'; i++) {
        if (*(tekst + i) == ' ' || *(tekst + i) == '.')
            antal++;
    }
    return antal;
}