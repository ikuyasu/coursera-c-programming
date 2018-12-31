#include <stdio.h>
#include <stddef.h>


size_t maxSeq(int * array, size_t n) {
  
  if (n == 0 || n == 1) {
    return n;
  }

  size_t sequence = 1;
  size_t mics = 1;

  for (int i = 0; i < n - 1; i++) {
    if (array[i] < array[i+1]) {
      sequence++;
      if (sequence > mics) {
        mics = sequence;
      }
    } else {
      sequence = 1;
    }
  }

  return mics;
}
