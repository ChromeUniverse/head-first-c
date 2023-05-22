// Instructions
//
// compile with:
// gcc geo2json.c -o geo2json
//
// redirect stdin to gpsdata.csv, redirect stdout to output.json:
// ./geo2json < gpsdata.csv > output.json

#include <stdio.h>

int main() {
  float latitude;
  float longitude;
  char info[80];
  int started = 0;

  puts("{\n\t\"data\": [");
  while (scanf("%f,%f,%79[^\n]", &latitude, &longitude, info) == 3) {
    if (started) {
      printf(",\n");
    } else {
      started = 1;
    }

    // validate GPS data
    if (latitude < -90.0 || latitude > 90.0) {
      fprintf(stderr, "Invalid latitude: %f\n", latitude);
      return 2;
    }
    if (longitude < -180.0 || longitude > 180.0) {
      fprintf(stderr, "Invalid longitude: %f\n", latitude);
      return 2;
    }

    printf("\t\t{ \"latitude\": %f, \"longitude\": %f, \"info\": \"%s\" }",
           latitude, longitude, info);
  }

  puts("\n\t]\n}");
  return 0;
}