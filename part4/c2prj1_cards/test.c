#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cards.h"

const char * ranking_to_string(hand_ranking_t r);

int main(void) {
  card_t card;
  card.value = 10;
  card.suit = CLUBS;
  // suit_t s;
  // s = CLUBS;
  printf("Suit: %d\n", DIAMONDS);
  printf("VALUE_ACE: %d\n", VALUE_ACE * 2);
  printf("value %d, and suit %d\n", card.value, card.suit);

  hand_ranking_t r = STRAIGHT_FLUSH;
  const char * ranking = ranking_to_string(r);
  printf("THe hand ranking: %s\n", ranking);
  char cardValue = value_letter(card);
  printf("card.value: %c\n", cardValue);
  print_card(card);
  printf("\n");

  printf("%d\n", '3' >= '2');
  printf("%d\n", '3');
  printf("%d\n", '2');
  return 0;
}

const char * ranking_to_string(hand_ranking_t r) {
  char * ranking;
  switch (r) {
    case STRAIGHT_FLUSH:
      ranking = "STRAIGHT_FLUSH";
      break;
    case FOUR_OF_A_KIND:
      ranking = "FOUR_OF_A_KIND";
    case FULL_HOUSE:
      ranking = "FULL_HOUSE";
      break;
    case FLUSH:
      ranking = "FLUSH";
      break;
    case STRAIGHT:
      ranking = "STRAIGHT";
      break;
    case THREE_OF_A_KIND:
      ranking = "THREE_OF_A_KIND";
      break;
    case TWO_PAIR:
      ranking = "TWO_PAIR";
      break;
    case PAIR:
      ranking = "PAIR";
      break;
    default:
      ranking = "NOTHING";
      break;
  };
  
  return ranking;
}

char value_letter(card_t c) {
  // This function should return the character that textually represents
  // the value of the passed-in card.  For values 2-9, this should
  // be that digit.  For 10, it should be '0', and for Jack, Queen, King, and Ace,
  // it should be 'J', 'Q', 'K', and 'A' respectively.
  // Hint: remember everything is a number.
  // For example, the character '0' has the decimal value 48,
  // and the character '5' has the decimal value 53, so you could represent
  // '5' as '0' + 5.
  int value = c.value;
  char charValue;
  if (value >=2 && value <= 9) {
    charValue = '0' + value;
  } else if (value == 10) {
    charValue = '0';
  } else if (value == 11) {
    charValue = 'J';
  } else if (value == 12) {
    charValue = 'Q';
  } else if (value == 13) {
    charValue = 'K';
  } else {
    charValue = 'A';
  }
  return charValue;
}

char suit_letter(card_t c) {
  char suit;
  switch (c.suit) {
    case SPADES:
      suit = 's';
      break;
    case HEARTS:
      suit = 'h';
      break;
    case DIAMONDS:
      suit = 'd';
      break;
    case CLUBS:
      suit = 'c';
      break;
    default:
      suit = '?';
      break;
  };
  return suit;
}

void print_card(card_t c) {
  printf("%c%c", value_letter(c), suit_letter(c));
}