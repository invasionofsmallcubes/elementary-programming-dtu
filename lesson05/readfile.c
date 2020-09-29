#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// common function to open a file
FILE * file(const char * filename, const char * mode) {
    FILE *ptr = fopen(filename, mode);
    if (ptr == NULL) {
        printf("no such file.");
        exit(0);
    }
    return ptr;
}

// use it when you want just read a file without writing
FILE * readFile(const char * filename) {
    return file(filename, "r");
}

// use it to write a file from scratch every time is started
FILE * writeFile(const char * filename) {
    return file(filename, "w");
}

#define MAXCHAR 1024
int main() {
    FILE *ptr = readFile("text.txt");
    FILE *wptr = writeFile("result.txt");

    char cityTitle[100];
    char ageTitle[100];
    char buffer[MAXCHAR];
    fgets(buffer, MAXCHAR, ptr);
    sscanf(buffer, "%*s %s %s", ageTitle, cityTitle);
    printf("%s\t%s\n", cityTitle, ageTitle);
    fprintf(wptr, "%s\t%s\n", cityTitle, ageTitle);

    char city[100];
    int  age;
    // needs to return the right number of matched chars expected
    // while (fscanf(ptr, "%*s %d %s ", &age, city) == 2) {
      while(fgets(buffer, MAXCHAR, ptr)) {
        sscanf(buffer, "%*s %d %s ", &age, city);
        printf("%s\t%d\n", city, age);
        fprintf(wptr, "%s\t%d\n", city, age);
    }

    char city[100];
    int  age;
      while(fgets(buffer, MAXCHAR, ptr)) {
        sscanf(buffer, "%*s %d %s ", &age, city);
        printf("%s\t%d\n", city, age);
    }

    fclose(ptr);
    fclose(wptr);

    return 0;
}