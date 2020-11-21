#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void concatOneX(char *output, char *src);

int main(void) {
    char *input = "Something";
    char *output;
    concatOneX(output, input);
    printf("Length: %d\n", strlen(output));
    printf("%s\n", output);
}

void checkFatal(char *ptr) {
    if (ptr == NULL) {
        printf("Something wrong\n");
        exit(EXIT_FAILURE);
    }
}
void concatOneX(char *output, char *src) {
    int   size    = strlen(src) + 1;
    char *sOutput = malloc(size * sizeof(char));
    checkFatal(sOutput);
    sOutput = strcpy(sOutput, src);
    checkFatal(sOutput);
    char *errorCheck = strcat(sOutput, "X");
    checkFatal(errorCheck);
    strcpy(output, sOutput);
    free(sOutput);
}