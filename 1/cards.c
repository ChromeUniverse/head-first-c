#include <stdio.h>
#include <stdlib.h>

int main() {
  char card_name[3];
  int count = 0;

  while (card_name[0] != 'X') {
    // input card name
    puts("Enter the card name: ");
    scanf("%2s", card_name);

    // assign card value base on card name
    int val = 0;
    switch (card_name[0]) {
      case 'K':
      case 'Q':
      case 'J':
        val = 10;
        break;
      case 'A':
        val = 11;
        break;
      case 'X':
        continue;
      default:
        val = atoi(card_name);

        // skip rest of the loop is card is outside the 1-10 range
        if (val < 1 || val > 10) {
          puts("Card value must be in the 1-10 range.");
          continue;
        }
    }

    /* Check if the value is 3 to 6 */
    if (val >= 3 && val <= 6) {
      count++;
    }

    /* Otherwise check if the card was 10, J, Q or K */
    else if (val == 10) {
      count--;
    }

    printf("Current count: %i\n", count);
  }

  return 0;
}
