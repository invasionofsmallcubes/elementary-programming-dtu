#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int nummer;
    int antal;
} Maaler;
int main(void) {
    Maaler liste1[5], liste2[5];
    int    i;
    for (i = 0; i < 5; i++) {
        liste1[i].antal = i * i;
    }
    for (i = 0; i < 5; i++)
        liste2[i] = liste1[i];
    printf("Følgende antal blev gemt:\n");
    for (i = 0; i < 5; i++) {
        printf("%d \t", liste2[i].antal);
    }
    return EXIT_SUCCESS;
}