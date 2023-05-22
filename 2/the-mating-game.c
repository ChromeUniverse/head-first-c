#include <stdio.h>
int main() {
  // initial value
  int contestants[] = {1, 2, 3};
  // will store a pointer to the 1st element of contestants[]
  int *choice = contestants;
  // set the 1st element to the integer 2
  contestants[0] = 2;
  // set the 2nd element to be the 3rd element, i.e., the integer 3
  contestants[1] = contestants[2];
  // set the 3rd element to the dereferenced value of the choice pointer,
  // i.e., the first element of contestants, i.e., the integer 2
  contestants[2] = *choice;

  // therefore, the final array is now:
  // {2, 3, 2}

  printf("I'm going to pick contestant number %i\n", contestants[2]);
  return 0;
}