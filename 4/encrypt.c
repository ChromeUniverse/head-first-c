#include "encrypt.h"

// Loops through the characters in the "message" char pointer and
// XORs them with the integer 31.
//
// Note: uses pointer dereferencing to access the current char and
// pointer arithmetic to advance through the chars in the array.
void encrypt(char *message) {
  while (*message) {
    *message = *message ^ 31;
    message++;
  }
}