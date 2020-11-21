#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char* concatOneX(char *src);
void checkFatal(char *ptr);

int main(void) {
    char *input = "Something";
    char *output = concatOneX(input);
    printf("Length: %d\n", strlen(output));
    printf("%s\n", output);
    free(output);
}

void checkFatal(char *ptr) {
    if (ptr == NULL) {
        printf("Something wrong\n");
        exit(EXIT_FAILURE);
    }
}

char* concatOneX(char *src) {
    int   size    = strlen(src) + 1;
    char *sOutput = malloc(size * sizeof(char));
    checkFatal(sOutput);
    sOutput = strcpy(sOutput, src);
    checkFatal(sOutput);
    char *errorCheck = strcat(sOutput, "X");
    checkFatal(errorCheck);
    return sOutput;
}