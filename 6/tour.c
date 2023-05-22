#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Island node
typedef struct {
  char *name;
  char *opens;
  char *closes;
  struct island *next;
} island;

// Creates a new island
//
// Parameters:
// char *name: char pointer to new island's name
//
// Returns:
// A pointer to the newly created island
island *create(char *name) {
  island *i = malloc(sizeof(island));
  i->name = strdup(name);
  i->opens = "09:00";
  i->closes = "17:00";
  i->next = NULL;
  return i;
}

// Releases the heap memory allocated to an island
//
// Parameters:
// island *start: pointer to the island to be free
void release(island *start) {
  island *i = start;
  island *next = NULL;

  // loop through the linked list of islands, free up memory
  for (; i != NULL; i = next) {
    next = i->next;
    free(i->name);  // first frees up the island's name
    free(i);        // then frees the entire island struct itself
  }
}

// Displays the linked list of islands
void display(island *start) {
  island *i = start;

  if (i == NULL) {
    printf("The list is empty.\n");
    return;
  }

  for (; i != NULL; i = i->next) {
    /* code */
    printf("Name: %s Open: %s-%s\n", i->name, i->opens, i->closes);
  }
}

int main(void) {
  // create islands
  // island amity = {"Amity", "09:00", "17:00", NULL};
  // island craggy = {"Craggy", "09:00", "17:00", NULL};
  // island isla_nublar = {"Isla Nublar", "09:00", "17:00", NULL};
  // island shutter = {"Shutter", "09:00", "17:00", NULL};

  // // link islands
  // // PATH: Amity -> Craggy -> Isla Nublar -> Shutter
  // amity.next = &craggy;
  // craggy.next = &isla_nublar;
  // isla_nublar.next = &shutter;

  // // create a new island
  // island skull = {"Skull", "09:00", "17:00", NULL};

  // // Insert it between Isla Nublar and Shutter
  // isla_nublar.next = &skull;
  // skull.next = &shutter;

  // display(&amity);

  island *start = NULL;
  island *i = NULL;
  island *next = NULL;

  char name[80];

  for (; fgets(name, 80, stdin) != NULL; i = next) {
    next = create(name);
    if (start == NULL) {
      start = next;
    }
    if (i != NULL) {
      i->next = next;
    }
  }

  display(start);
  release(start);

  return 0;
}
