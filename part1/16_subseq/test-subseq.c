#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

size_t maxSeq(int * array, size_t n);

int main(void) {
  int array01[] = {1, 2, 3};
  int array02[] = {};
  int array03[] = {2};
  int array04[] = { 1, 2, 1, 3, 5, 7, 2, 4, 6, 9};
  int array05[] = {1, 1, 3, 0, 0, 2, 1, 3, 9, 3, 1, 3, 4, 0, 7, 8};
  // int array06[] = {0, 1, 2, 2, 2, 2, 3, 4, 5, 0, 1, 0, 1, 2, 2, 0};

  int array07[] = {-1, -2, -1, -3, -5, -7, -2, -4, -6, -9};
  int array08[] = {-1, -1, 3, 0, 0, -2, -1, -3, -9, -3, 1, -3, -4, 0, -7, -8};
  int array09[] = {0, -1, -2, -2, -2, -2, -3, -4, -5, 0, -1, 0, -1, -2, -2, 0};
  int array10[] = {-3, -2, -1, 1, 2};

  if (maxSeq(array01, 3) != 3) {
    printf("Failed on 1,2,3\n");
    exit(EXIT_FAILURE);
  }

  if (maxSeq(array02, 0) != 0) {
    printf("Failed on {}\n");
    exit(EXIT_FAILURE);
  }

  if (maxSeq(array03, 1) != 1) {
    printf("Failed on 2\n");
    exit(EXIT_FAILURE);
  }

  if (maxSeq(array04, 10) != 4) {
    printf("Failed on {1, 2, ..., 6, 9}\n");
    exit(EXIT_FAILURE);
  }

  if (maxSeq(array05, 16) != 3) {
    printf("Failed on {1, 1, ... 7, 8}\n");
    exit(EXIT_FAILURE);
  }

  if (maxSeq(array05, 16) != 3) {
    printf("Failed on {1, 1, ... 7, 8}\n");
    exit(EXIT_FAILURE);
  }


int array06[] = {0, 1, 2, 2, 2, 2, 3, 4, 5, 0, 1, 0, 1, 2, 2, 0};
  if (maxSeq(array06, 16) != 4) {
    size_t x = maxSeq(array06, 16);
    printf("size_t: %lu \n", x);
    printf("Failed on array06\n");
    exit(EXIT_FAILURE);
  }
  if (maxSeq(array07, 10) != 2) {
    printf("Failed on array07\n");
    exit(EXIT_FAILURE);
  }

  if (maxSeq(array08, 16) != 3) {
    printf("Failed on array08\n");
    exit(EXIT_FAILURE);
  }

  if (maxSeq(array09, 16) != 2) {
    printf("Failed on array09\n");
    exit(EXIT_FAILURE);
  }

  if (maxSeq(array10, 5) != 5) {
    printf("Failed on array10\n");
    exit(EXIT_FAILURE);
  }
  exit(EXIT_SUCCESS);
}