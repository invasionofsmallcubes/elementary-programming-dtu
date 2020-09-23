#include <stdio.h>
typedef float Kgs;
typedef float Lbs;
Lbs convert(Kgs weight) {
  return weight * 2.20462262185f;
}
int main(void) {
  Kgs weight = 80.0f;
  Lbs convertedWeight = convert(weight);
  printf("%.2f\n", convertedWeight);
}