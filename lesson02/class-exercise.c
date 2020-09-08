#include <stdio.h>

int main(void) {
  int height_inches = 8;
  int width_inches = 10;
  int length_inches = 12;
  int volume = height_inches * width_inches * length_inches;
  printf("Volume (cubic inches): %d\n", volume);

  int dimensional_weight = volume / 166;
  printf("Dimensional weight (pounds): %d\n", dimensional_weight);
}