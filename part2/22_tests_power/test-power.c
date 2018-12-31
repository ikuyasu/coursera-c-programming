#include <stdio.h>
#include <stdlib.h>

unsigned power(unsigned x, unsigned y);  // unsigned int

int main(void) {

  if (power(2, 10) != 1024) {
    printf("test failed on: power(2, 10)\n");
    exit(EXIT_FAILURE);
  }

  if (power(-2, 3) != -8) {
    printf("test failed on: power(2, 3)\n");
    exit(EXIT_FAILURE);
  }

  if (power(2, -2) != 0) {
    printf("test failed on: power(2, -2)\n");
    exit(EXIT_FAILURE);
  }

  if (power(2u, 3u) != 8) {
    printf("test failed on: power(2.2, 3.2)\n");
    exit(EXIT_FAILURE);
  }

  return EXIT_SUCCESS;
}

