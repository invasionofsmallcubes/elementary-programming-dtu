#include <stdio.h>
int main(int argc, char **argv) {
    FILE *filpeger;
    filpeger = fopen("vareliste.txt", "w");
    fprintf(filpeger, "Oversigt over varer\n");
    fclose(filpeger);
    filpeger = fopen("vareliste.txt", "a");
    fprintf(filpeger, "kaffe, te, kakao, saft\n");
    fclose(filpeger);
    filpeger = fopen("vareliste.txt", "a");
    fprintf(filpeger, "mælk, sodavand\n");
    fclose(filpeger);
    filpeger = fopen("vareliste.txt", "w");
    fprintf(filpeger, "juice, vin\n");
    fclose(filpeger);
    return 0;
}