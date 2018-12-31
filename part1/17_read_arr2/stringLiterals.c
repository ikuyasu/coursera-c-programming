#include <stdio.h>
#include <stdlib.h>

#define NSTRS 3
  
int main(void) {

  const char * strs[NSTRS] = {"apple", "bannana", "carrot"};
  const char * strs2[NSTRS] = {"apple", "bannana", "carrot"};

  printf("&strs[0] = %p\n", &strs[0]);
  printf("&strs[1] = %p\n", &strs[1]);
  printf("&strs[2] = %p\n", &strs[2]);
  printf("&strs2[0] = %p\n", &strs2[0]);
  printf("&strs2[1] = %p\n", &strs2[1]);
  printf("&strs2[2] = %p\n", &strs2[2]);

  printf("strs[0] = %p\n", strs[0]);
  printf("strs[1] = %p\n", strs[1]);
  printf("strs[2] = %p\n", strs[2]);
  printf("strs2[0] = %p\n", strs2[0]);
  printf("strs2[1] = %p\n", strs2[1]);
  printf("strs2[2] = %p\n", strs2[2]);

  const char * ptr = "carrot";
  char xxx = *ptr + 3;
  printf("xxx = %c\n", xxx);  
  printf("xxx = 99 + 3 = 102 = 'f'?\n");


  //const char * str = "Hello World\n";
  char x = 'a';
  char y = 'b';
  char * str1 = "Hello";
  char * str2 = "Hello";

  char z = 'c';

  printf("%p\n", &x);
  printf("%p\n", &y);
  printf("%p\n", &str1[0]);
  printf("%p\n", &str2[0]);
  printf("%p\n", &z);

  char str[] = {'H', 'e', 'l', 'o', ' ', 'W', 'l', 'd', '\n', '\0'};

  return 0;
}