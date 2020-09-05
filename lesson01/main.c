#include <stdio.h>

int main() {
  int j;
  int i;
  printf("Tell i\n");
  scanf("%d", &i);
  printf("Tell j\n");
  scanf("%d", &j);
  int sum = i + j;
  printf("Sum is %d", sum);
}