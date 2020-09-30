#include <stdio.h>
#include <stdlib.h>

#define BUFFERLENGTH 1024

FILE * smartOpen(char * filename, char *permissions) {
    FILE *ptr = fopen(filename, permissions);
    if (ptr == NULL) {
        printf("I didn't find the file you were looking for!\n");
        exit(EXIT_FAILURE);
    }
    return ptr;
}

FILE * smartRead(char * filename) {
  return smartOpen(filename, "r");
}

int sum(int a, int b) {
  return a + b;
}

int main(void) {

    FILE *readFile = smartRead("text.txt");
    FILE * writeFile = smartOpen("textResult.txt", "w");

    char ageHeader[4];
    char cityHeader[5];
    char buffer[100];
    fgets(buffer, BUFFERLENGTH, readFile);
    int matches = sscanf(buffer, "%*s %s %s", ageHeader, cityHeader);
    if (matches == 2) {
        printf("matches %d\n", matches);
        printf("buffer: %s\n", buffer);
    } else {
        printf("number of matches is weird %d!\n", matches);
        fclose(readFile);
        exit(EXIT_FAILURE);
    }

    int  age;
    char city[86];
    int size = sizeof(city)/sizeof(city[0]);
    printf("SIZE ARRAY: %ld\n", sizeof(city));
    printf("SIZE SINGLE ARRAY: %ld\n", sizeof(city[0]));
    printf("SIZE: %d\n", size);

    fprintf(writeFile, "%s %s\n", ageHeader, cityHeader);
    while (fgets(buffer, BUFFERLENGTH, readFile)) {
        int match = sscanf(buffer, "%*s %d %s", &age, city);
        if (match != 2) {
            printf("number of matches is weird %d!\n", matches);
            fclose(readFile);
            exit(EXIT_FAILURE);
        }
        fprintf(writeFile, "%d %s\n", age, city);
    }

    fclose(writeFile);
    fclose(readFile);
}