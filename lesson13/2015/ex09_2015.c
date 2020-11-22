#include <stdio.h>
int main(int argc, char **argv) {
    int valg, semester;
    printf("Hvilket kursus vil du tilmelde dig?\n");
    printf("C-programmering - tast 1\n");
    printf("C++-programmering - tast 2\n");
    printf("Java-programmering - tast 3\n");
    printf("Indtast dit svar: ");
    scanf("%d", &valg);
    printf("Forårskursus - tast 1\n");
    printf("Efterårskursus - tast 2\n");
    printf("Indtast dit svar: ");
    scanf("%d", &semester);
    switch (valg) {
    case 1:
        printf("Du kan komme på C-kursus\n");
        break;
    case 2:
        if (semester == 1)
            printf("Kurset afholdes ikke");
        else
            printf("Du kan komme på C++-kursus\n");
        break;
    case 3:
        if (semester == 2)
            printf("Kurset afholdes ikke");
        else
            printf("Du kan komme på Java-kursus\n");
        break;
    }
    return 0;
}