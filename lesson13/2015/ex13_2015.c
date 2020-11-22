#include <stdio.h>
int main(int argc, char **argv) {
    int   i;
    char *vareliste[] = {"kaffe", " te", " kakao"};
    printf("\nListens indhold:\n");
    for (i = 0; i < 3; i++)
        printf("%s", *(vareliste + i));
    *(vareliste + 1) = " saft";
    printf("\nListens indhold:\n");
    for (i = 0; i < 3; i++)
        printf("%s", *(vareliste + i));
    return 0;
}