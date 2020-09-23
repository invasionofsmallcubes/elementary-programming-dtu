#include <stdio.h>
int main(void) {
    int n;
    scanf("%d", &n);
    int a[n];
    int size = sizeof(a)/sizeof(a[0]);
    printf("The size is: %d\n", size);
    for (int i = 0; i < n; i++) {
        a[i] = i;
    }
}