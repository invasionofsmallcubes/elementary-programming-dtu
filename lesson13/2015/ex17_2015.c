#include <stdio.h>
typedef struct {
    int    nr, antalDage;
    double pris;
} Kursustype;
typedef struct {
    int        mdNr;
    Kursustype liste[3];
} Kursusliste;
Kursusliste OpretListe(Kursusliste kurser);
void        Udskriv(Kursusliste kurser);
int         main(int argc, char **argv) {
    Kursusliste kurser;
    kurser = OpretListe(kurser);
    Udskriv(kurser);
    return 0;
}
Kursusliste OpretListe(Kursusliste kurser) {
    int i;
    kurser.mdNr = 9;
    for (i = 0; i < 3; i++) {
        kurser.liste[i].nr        = i + 1;
        kurser.liste[i].antalDage = i + 2;
        kurser.liste[i].pris      = kurser.liste[i].antalDage * 5000;
    }
    return kurser;
}
void Udskriv(Kursusliste kurser) {
    int i;
    printf("\nAfholdes i måned nummer %d: \n", kurser.mdNr);
    for (i = 0; i < 3; i++) {
        printf("Kursusnr. %d Antal dage %d Pris %.2f kr.\n",
               kurser.liste[i].nr,
               kurser.liste[i].antalDage,
               kurser.liste[i].pris);
    }
}