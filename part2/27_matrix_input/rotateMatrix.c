#include <stdio.h>
#include <stdlib.h>

void printMatrix(char matrix[10][10]);

void rotate(char matrix[10][10]);

int main(int argc, char ** argv) {
  if (argc != 2) {
    fprintf(stderr, "Need 1 argument for the file name to read the matrix\n");
    return EXIT_FAILURE;
  }

  FILE * f = fopen(argv[1], "r");
  if (f == NULL) {
    fprintf(stderr, "Problem with opening a FIEE * \n");
    return EXIT_FAILURE;
  }

  char myMatrix[10][10];

  int c;
  int i = 0;
  int j = 0;
  while (i < 10) {
    while (j < 11) {
      c = fgetc(f);
      if (j < 10 && (c == '\n')) {
        printf("i: %d, j: %d\n", i, j);
        fprintf(stderr, "This line contains too few characters:29\n");
        return EXIT_FAILURE;
      }
      myMatrix[i][j] = c;
      j++;
      if (j == 11 && (c != '\n')) {
        fprintf(stderr, "This line contains more than 10 characters:35\n");
        return EXIT_FAILURE;
      }
    }
    j = 0;
    i++;
  }
  if ((c=fgetc(f)) != EOF) {
    fprintf(stderr, "This input has too many lines:43\n");
    return EXIT_FAILURE;
  }

  rotate(myMatrix);
  printMatrix(myMatrix);
  
  return EXIT_SUCCESS;
}

void printMatrix(char matrix[10][10]) {
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      printf("%c", matrix[i][j]);
    }
    printf("\n");
  }
} 

void rotate(char matrix[10][10]) {
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