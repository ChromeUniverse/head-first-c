#include <getopt.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
  char* delivery = "";
  int thick = 0;
  int count = 0;
  char ch;

  while ((ch = getopt(argc, argv, "d:t")) != EOF) {
    switch (ch) {
      // delivery option
      case 'd':
        delivery = optarg;
        break;

      // thickness option
      case 't':
        thick = 1;
        break;

      default:
        fprintf(stderr, "Unknown option: '%s", optarg);
        return 1;
    }
  }

  // skipping past options, moving to arguments
  argc -= optind;
  argv += optind;

  if (thick) {
    puts("Thick crust");
  }

  if (delivery[0]) {
    printf("To be delivered %s.\n", delivery);
  }

  puts("Ingredients:");

  // arguments
  for (count = 0; count < argc; count++) {
    puts(argv[count]);
  }

  return 0;
}
