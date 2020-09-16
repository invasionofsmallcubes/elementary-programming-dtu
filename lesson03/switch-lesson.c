#include <stdio.h>
int main(void) {
    printf("Insert grade from 0 to 4: ");
    int grade;
    scanf("%d", &grade);
    switch (grade) {
    case 4: 
    case 3: {
        printf("Good");
        break;
    }
    case 2: {
        printf("Average");
        break;
    }
    case 1: {
        printf("Poor");
        break;
    }
    case 0: {
        printf("Failing");
        break;
    }
    default: {
        printf("Illegal grade");
        break;
    }
    }
}