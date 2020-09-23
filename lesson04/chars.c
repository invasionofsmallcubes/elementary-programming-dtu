#include <stdio.h>

int main(void) {
  char ch;
  printf("tell me one char: ");
  scanf("%c", &ch);
  if(ch >= 'a' && ch <= 'z') {
    ch = ch - 'a' + 'A';
  }
  printf("%c\n", ch);
  for(char c = 'A'; c <= 'Z'; c++) {
    printf("%c", c);
  }
}