#include <stdio.h>

#include "encrypt.h"

int main(int argc, char const *argv[]) {
  char line[100];

  // check for correct number of arguments
  if (argc != 2) {
    fputs("Please specify a file to be encrypted.\n", stderr);
    return 1;
  }

  // Open files
  FILE *in_file = fopen(argv[1], "r");
  FILE *out_file = fopen("encrypted.txt", "w");

  // read input file, encrypt, write to output file
  while (fgets(line, 100, in_file)) {
    encrypt(line);
    fputs(line, out_file);
  }

  return 0;
}