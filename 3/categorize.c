#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  char line[80];

  // check for correct number of arguments
  if (argc != 6) {
    fprintf(stderr, "You need to give 5 arguments\n");
    return 1;
  }

  // open file stream from gps data
  FILE *in = fopen("spooky.csv", "r");
  // open file streams to output files
  FILE *file1 = fopen(argv[2], "w");
  FILE *file2 = fopen(argv[4], "w");
  FILE *file3 = fopen(argv[5], "w");

  // read gps data
  while (fscanf(in, "%79[^\n]\n", line) == 1) {
    if (strstr(line, argv[1]))
      fprintf(file1, "%s\n", line);
    else if (strstr(line, argv[3]))
      fprintf(file2, "%s\n", line);
    else
      fprintf(file3, "%s\n", line);
  }

  // close file streams
  fclose(file1);
  fclose(file2);
  fclose(file3);
  return 0;
}