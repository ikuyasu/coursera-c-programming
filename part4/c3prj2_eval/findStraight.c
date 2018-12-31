#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


int findStraight(int hand[], int n, int index) {
  if ( n == 0 ) {
    printf("reached here\n");
    return 1;
  } else {
    if (hand[index+1] < hand[index]) {
      
    }
    return findStraight(hand, n - 1, index);
  }
}

int main(void) {
  int found = 0;
  int hand[] = {9,9,8,8,7,6,5,4,4,4,3,2,1};
  found = findStraight(hand, 13, 4);
  if (found) {
    printf("Find the straight\n");
  }
  return EXIT_SUCCESS;
}