#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char ** argv) {
  if (argc != 2) {
    fprintf(stderr, "Need only 1 argument for the name of input file\n");
    exit(EXIT_FAILURE);
  }

  FILE * f = fopen(argv[1], "r");
  if (f == NULL) {
    fprintf(stderr, "Something went wrong with opening a file\n");
    exit(EXIT_FAILURE);
  }

  int c;
  int frequencyOfChars[26] = {0};
  while ( (c = fgetc(f)) != EOF ) {
    if (isalpha(c)) {
      c = tolower(c);
      if (c >= 97 && c <= 122) {  // c >= 'a' && c <= 'z'
	frequencyOfChars[c-97]++;
      }
    }
  }

  fclose(f);

  int largestIndex = 0;
  for (size_t i = 1; i < 26; i++) {
    if (frequencyOfChars[i] > frequencyOfChars[largestIndex]) {
      largestIndex = i;
    }
  }
  
  int key = (largestIndex - ('e'-'a') + 26) % 26;
  fprintf(stdout, "%d\n", key);
 
  return EXIT_SUCCESS;
 }
