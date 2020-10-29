#include <stdlib.h>
#include <stdio.h>

int main(void) {
    printf("I'm using malloc\n");
    int  size = 10000000;
    int *arr  = malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("memory could not be allocated\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < size; i++) {
        arr[i] = i;
    }
    printf("Check the memory of the process\n");
    int c;
    scanf("%d", &c);
    printf("I'm using realloc\n");
    int *newArr = realloc(arr, 5 * sizeof(int));
    if (newArr == NULL) {
        printf("memory could not be allocated\n");
        exit(EXIT_FAILURE);
    }
    int d;
    printf("Check the memory of the process\n");
    scanf("%d", &d);
    for (int i = 0; i < 15; i++) {
        printf("%d\n", arr[i]);
    }
    free(newArr);
    //free(arr);
    for (int i = 0; i < 15; i++) {
        printf("%d\n", newArr[i]);
    }
}