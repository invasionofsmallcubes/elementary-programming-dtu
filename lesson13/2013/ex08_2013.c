#include <stdio.h>
#include <stdlib.h>
int main(void) {
    FILE *filpeger;
    filpeger = fopen("tekstfil.txt", "w");
    fprintf(filpeger, "Der var engang ...\n");
    fclose(filpeger);
    filpeger = fopen("tekstfil.txt", "a");
    fprintf(filpeger, "en mand, der hed\n");
    fclose(filpeger);
    filpeger = fopen("tekstfil.txt", "w");
    fprintf(filpeger, "Ole.\n");
    fclose(filpeger);
    return EXIT_SUCCESS;
}