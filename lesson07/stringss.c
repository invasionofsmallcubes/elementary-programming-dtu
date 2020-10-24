#include <string.h>
#include <stdio.h>

char *safeStrncpy(char *str1, char *str2, int n) {
    char *p     = strncpy(str1, str2, n - 1);
    str1[n - 1] = '\0';
    return p;
}

int read_line(char str[], int n) {
    int ch, i = 0;
    while ((ch = getchar()) != '\n') {
      if(i < n) {
        str[i] = ch;
        i = i + 1;
      }
    }
    str[i] = '\0'; // we close the string with null char
    return i;
}

int main(void) {
    char str1[10];
    int  sizeOfStr1 = sizeof(str1) / sizeof(str1[0]);
    printf("size of str1: %d\n", sizeOfStr1);

    //str1="abcd"; // wrong
    char *p     = strncpy(str1, "abcd", sizeOfStr1 - 1);
    str1[sizeOfStr1 - 1] = '\0';

    if (p == NULL) {
        printf("p is NULL\n");
    } else {
        printf("p is not NULL\n");
        printf("Content is: ");
        for (int i = 0; i < sizeOfStr1; i++) {
            char *k = p + i;
            printf("%c", *k);
        }
        printf("\n");
    }

    printf("Content of str1: %s\n", str1);
    int sizeOfStr2 = sizeof(str1) / sizeof(str1[0]);
    printf("size of str1 after abcd: %d\n", sizeOfStr2);
    int sizeOfStr3 = strlen(str1);
    printf("size of str1 after abcd with strlen: %d\n", sizeOfStr3);
    strcat(str1, "abcd");
    printf("Content of str1: %s\n", str1);

    char input[10];
    printf("Insert line > limits(10):\n");
    read_line(input, 10);
    printf("You put %s\n", input);
    char input2[10];
    printf("Insert line > limits(10):\n");
    gets(input2);
    printf("You put %s\n", input2);
}