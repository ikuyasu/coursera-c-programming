#include <stdio.h>
#include <stdlib.h>

void rotate(char matrix[10][10]) {
  int n = 10;
  for (int i = 0; i < n - 1; i++) {
    for (int j = i; j < n - i; j++) {
      int temp01 = matrix[j][n-j];
      int temp02 = matrix[n-j][n-j];
      matrix[j][n-j] = matrix[i][j];
      matrix[n-j][n-j] = temp01;
      temp01 = matrix[n-j][i];
      matrix[n-j][i] = temp02;
      matrix[i][j] = temp01;


    }
  }
}