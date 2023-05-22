#include <stdio.h>
#include <string.h>

// this bad boi does some mad pointer arithmetic!
void print_reverse(char *s) {
  // represents the length of s
  size_t len = strlen(s);
  // char pointer: starts pointing to the last char in s
  char *t = s + len;
  // compare memory addresses of char pointer t and first char of the string s
  while (t >= s) {
    printf("%c", *t);
    // move on to the previous char of s
    t = t - 1;
  }
  printf("\n");
}

int main() {
  char input[100];
  printf("Enter a string: ");
  fgets(input, 100, stdin);
  print_reverse(input);
  return 0;
}