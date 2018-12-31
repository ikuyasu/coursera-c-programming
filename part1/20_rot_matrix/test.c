#include <stdio.h>
#include <stdlib.h>

void rotate(int matrix[10][10]);
void printMatrix(int matrix[10][10]);

int main(void) {
  int n = 10;
  int matrix[n][n];

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      matrix[i][j] = n*i + j;
    }
  }
  printMatrix(matrix);
  rotate(matrix);
  printf("Rotated matrix\n");
  printMatrix(matrix);
}

void rotate(int matrix[10][10]) {
  int n = 10 - 1;
  for (int i = 0; i < n/2 + 1; i++) {
    for (int j = i; j < n - i; j++) {
      int temp01 = matrix[j][n-i];
      matrix[j][n-i] = matrix[i][j];
      int temp02 = matrix[n-i][n-j];
      matrix[n-i][n-j] = temp01;
      temp01 = matrix[n-j][i];
      matrix[n-j][i] = temp02;
      matrix[i][j] = temp01;
    }
    printf("\n");
  }
}
void printMatrix(int matrix[10][10]) {
  int n = 10;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%2d ", matrix[i][j]);
    }
    printf("\n");
  } 
}

  // int temp01 = matrix[j][n-j];
  // int temp02 = matrix[n-j][n-j];
  // matrix[j][n-j] = matrix[i][j];
  // matrix[n-j][n-j] = temp01;
  // temp01 = matrix[n-j][i];
  // matrix[n-j][i] = temp02;
  // matrix[i][j] = temp01;