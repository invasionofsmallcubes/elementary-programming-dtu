#include <stdio.h>

int main(int argc, char *argv[]) {
    printf("Number of parameters is %d\n", argc);
    printf("The program name is %s\n", argv[0]);
    if (argc == 2) {
        printf("The argument supplied is %s\n", argv[1]);
    } else if (argc > 2) {
        printf("Too many arguments supplied, I only accept one.\n");
    } else {
        printf("Error: one argument expected.\n");
    }

    printf("\nThis is all that was passed:\n");
    for(int i = 0; i < argc; i++) {
      printf(" - %s\n", argv[i]);
    }
}