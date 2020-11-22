#include <stdio.h>
#include <stdlib.h>
int main(void) {
    char tegn;
    printf("Indtast et tegn: \n");
    scanf("%c", &tegn); // Indtast et tegn: 1
    switch (tegn) {
    case 'a':
        printf("Du indtastede et bogstav\n");
        break;
    case 'b':
        printf("Du indtastede et bogstav\n");
        break;
    case '1':
        printf("Du indtastede et ciffer\n");
    case '2':
        printf("Du indtastede et ciffer\n");
        break;
    default:
        printf("Du indtastede noget andet\n");
        break;
    };
    return EXIT_SUCCESS;
}