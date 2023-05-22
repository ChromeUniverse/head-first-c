#include <stdio.h>

int main() {
  // char pointers to string literals can't be used to update the string!
  // const char *cards = "JQK";

  // but character arrays can!
  char cards[] = "JQK";

  // card shuffling
  char a_card = cards[2];
  cards[2] = cards[1];
  cards[1] = cards[0];
  cards[0] = cards[2];
  cards[2] = cards[1];
  cards[1] = a_card;

  puts(cards);
  return 0;
}