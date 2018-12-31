#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cards.h"

int main(void) {

  // card_from_letters(char value_let, char suit_let)
  card_t card = card_from_num(52);
  char value = value_letter(card);
  printf("value: %c\n", value);
  printf("Testing print_card()...\n");
  print_card(card);
  printf("\n");
  return EXIT_SUCCESS;
}