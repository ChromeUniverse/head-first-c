#include <stdio.h>

struct exercise {
  const char *description;
  float duration;
};

struct meal {
  const char *ingredients;
  float weight;
};

struct preferences {
  struct meal food;
  struct exercise exercise;
};

typedef struct {
  const char *name;
  const char *species;
  int teeth;
  int age;
  struct preferences care;
} fish;

// Prints out the catalog entry
void catalog(fish f) {
  printf("%s is a %s with %i teeth. He is %i\n", f.name, f.species, f.teeth,
         f.age);
}

void label(fish f) {
  printf("Name: %s\nSpecies: %s\n%i years old, %i teeth\n", f.name, f.species,
         f.age, f.teeth);

  printf("Feed with %2.2f lbs of %s and allow to %s for %2.2f hours",
         f.care.food.weight, f.care.food.ingredients,
         f.care.exercise.description, f.care.exercise.duration);
}

int main() {
  fish snappy = {"Snappy",
                 "Piranha",
                 69,
                 4,
                 {{"meat", 0.2}, {"swim in the jacuzzi", 7.5}}};
  label(snappy);
  return 0;
}
