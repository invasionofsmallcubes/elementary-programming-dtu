#include <stdio.h>

int main(void) {
  int num1, denom1, num2, denom2, result_num, result_denom;

  printf("Enter first fraction: ");
  scanf("%d/%d", &num1, &denom1);

  printf("Enter second fraction: ");
  scanf("%d/%d", &num2, &denom2);

  result_num = num1 * denom2 + num2 * denom1;
  result_denom = denom1 * denom2;

  printf("The sum is %d/%d\n", result_num, result_denom);

  printf("Write two decimals on the floats, separated by space: ");
  int x, y;
  float z, w;
  scanf("%d%d%f%f", &x, &y, &z, &w);
  printf("\nYou wrote %d %d %f %f", x, y, z, w);
}