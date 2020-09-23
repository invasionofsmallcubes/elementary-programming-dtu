#include <stdio.h>
int main(void) {
  float number = 10.5f;
  float frac_part = number - (int) number;
  printf("%f\n", frac_part);
}