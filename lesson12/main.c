#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char * concatOneX(char *output, char *src) {
    int   size    = strlen(src) + 1;
    char *sOutput = malloc(size * sizeof(char));
    if (sOutput == NULL) {
        return sOutput;
    }
    char * sOutput1 = strcpy(sOutput, src);
    if (sOutput1 == NULL) {
        free(sOutput);
        return sOutput1;
    }
    char *errorCheck = strcat(sOutput, "X");
    if (errorCheck == NULL) {
        free(sOutput);
        return errorCheck;
    }
    strcpy(output, sOutput);
    free(sOutput);
}

struct Smt {};

int main(void) {
    struct Smt *smt = caesar("something", 1);
}

struct Smt *caesar(char *dest, int key) {
    struct Smt smt; //local
    return &smt;    // local escaping outside
}