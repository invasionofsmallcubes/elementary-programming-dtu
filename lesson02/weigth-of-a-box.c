#include <stdio.h>
int main(void) {
  // declare variables to receive input from the user
  int height, length, width;

  // print the message on console to get the heigth
  printf("Enter height of box: ");
  scanf("%d", &height);

  // print the message on console to get the length
  printf("Enter length of box:");
  scanf("%d", &length);
  
  // print the message on console to get the width
  printf("Enter width of box:");
  scanf("%d", &width);

  // declare and initialize a variable called volume 
  // volume is given by multiplying height, length and width
  int volume = height * length * width;
  
  // declare and initizialize the weight calculation
  int weight = (volume + 165) / 166;

  printf("Volume (cubic inches): %d\n", volume);
  printf("Dimensional weight (pounds): %d\n", weight);
}