#include <stdio.h>

int main(void) {
  printf("Enter a nonnegative integer: ");
  int integer;
  scanf("%d", &integer);
  int digits = 0;

  do {
    integer /= 10;
    digits+=1;
  } while (integer > 0);

  printf("The number has %d digits\n", digits);

}