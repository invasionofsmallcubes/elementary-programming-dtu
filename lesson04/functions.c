#include <stdio.h>

double average(double a, double b);

int main(void) {
  double x, y;
  printf("Tell me two numbers: ");
  scanf("%lf %lf", &x, &y);
  printf("The average is %g", average(x, y));
}

double average(double a, double b) {
  int div = 2;
  return (a+b)/div;
}