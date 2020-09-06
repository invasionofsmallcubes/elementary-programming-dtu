#include <stdio.h>

int main(void) {
  printf("Write two decimals on the floats, separated by spaces: \n");
  int x, y;
  float z, w;
  scanf("%d%d%f%f", &x, &y, &z, &w);
  printf("You wrote %d %d %f %f\n", x, y, z, w);
}