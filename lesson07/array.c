#include <stdlib.h>
#include <stdio.h>

int find_largest(int a[], int n) {
  printf("size of array (inside function) is %d\n", size);
  int max;
  max = a[0];
  for(int i = 1; i < n; i++) {
    if(a[i] > max) {
      max = a[i];
    }
  }
  return max;
}

int main(void) {

  int k[3] = {1, 5, -3};
  int size = sizeof(k)/sizeof(k[0]);
  printf("size of array is %d\n", size);
  printf("Largest number is %d\n", find_largest(k, 3));
}