#include <stdio.h>
#include <string.h>

// Array of songs in the jukebox
char tracks[][80] = {
    "I left my heart in Harvard Med School",
    "Newark, Newark - a wonderful town",
    "Dancing with a Dork",
    "From here to maternity",
    "The girl from Iwo Jima",
};

// alternative declaration: an array of pointers for string literals (constants)
// char *tracks[] = {
//     "I left my heart in Harvard Med School",
//     "Newark, Newark - a wonderful town",
//     "Dancing with a Dork",
//     "From here to maternity",
//     "The girl from Iwo Jima",
// };

// Finds tracks with titles that match the search string
void find_track(char search_for[]) {
  for (int i = 0; i < 5; i++) {
    if (strstr(tracks[i], search_for)) {
      printf("Track %i: '%s'\n", i, tracks[i]);
    }
  }
}

int main() {
  // read user input

  char search_for[80];
  printf("Search for: ");

  // need to remove newline character at the end of the input!
  fgets(search_for, 80, stdin);
  search_for[strcspn(search_for, "\n")] = '\0';

  find_track(search_for);
  return 0;
}
