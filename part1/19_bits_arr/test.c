#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int getNthBit(uint32_t number, int bit) {
  if (bit <0 || bit >= 32) {
    printf("Bit %d is invalid\n", bit);
    exit (EXIT_FAILURE);
  }
  return (number & (1<<bit)) != 0;
}


int main(void) {
  uint32_t array1[] = { 1, 2, 3, 4, 5, 15, 109};
  uint32_t number = 15;
  int bit0 = getNthBit(number, 0);
  int bit1 = getNthBit(number, 1);
  int bit2 = getNthBit(number, 2);
  int bit3 = getNthBit(number, 3);
  int bit4 = getNthBit(number, 4);
  int bit5 = getNthBit(number, 5);

  printf("bit: 0th 1th 2th 3rd 4th 5th\n");
  printf("      %d  %d  %d  %d  %d  %d\n", bit0, bit1, bit2, bit3, bit4, bit5);

  int hello = atoi("123");
  int hi = atoi("12");
  printf("hello: %d\n", hello);
  printf("hi: %d\n", hi);

  double myMatrix[4][3];
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 3; j++) {
      printf("&matrix[i][j]: %p\n", &myMatrix[i][j]);
    }
  }

  return EXIT_SUCCESS;
}
