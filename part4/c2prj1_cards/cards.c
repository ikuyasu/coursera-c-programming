#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cards.h"


void assert_card_valid(card_t c) {
  assert(c.value >=2);
  assert(c.value <= VALUE_ACE);
  assert(c.suit >= SPADES);
  assert(c.suit <= CLUBS);
}

const char * ranking_to_string(hand_ranking_t r) {
  char * ranking;
  switch (r) {
    case STRAIGHT_FLUSH:
      ranking = "STRAIGHT_FLUSH";
      break;
    case FOUR_OF_A_KIND:
      ranking = "FOUR_OF_A_KIND";
      break;
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
  int value;
  if (c.value >=2 && c.value <= 9) {
    value = '0' + c.value;
  } else if (c.value == 10) {
    value = '0';
  } else if (c.value == 11) {
    value = 'J';
  } else if (c.value == 12) {
    value = 'Q';
  } else if (c.value == 13) {
    value = 'K';
  } else {
    value = 'A';
  }
  return value;
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
  assert_card_valid(c);
  printf("%c%c", value_letter(c), suit_letter(c));
}

unsigned letter_value(char value_let) {
  if (value_let >= '2' && value_let <= '9') {
    return value_let - '0';
  } else if (value_let == '0') {
    return 10;
  } else if (value_let == 'J') {
    return 11;
  } else if (value_let == 'Q') {
    return 12;
  } else if (value_let == 'K') {
    return 13;
  } else if (value_let == 'A') {
    return 14;
  } else {
    fprintf(stderr, "Failed on letter for card.value\n'");
    exit(EXIT_FAILURE);
  }
}

suit_t letter_suit(char suit_let) {
  if (suit_let == 's') {
    return SPADES;
  } else if (suit_let == 'h') {
    return HEARTS;
  } else if (suit_let == 'd') {
    return DIAMONDS;
  } else if (suit_let == 'c') {
    return CLUBS;
  } else {
    fprintf(stderr, "Failed on letter for card.suit\n");
    exit(EXIT_FAILURE);
  }
}

card_t card_from_letters(char value_let, char suit_let) {
  card_t c = {.value = letter_value(value_let),
              .suit = letter_suit(suit_let)};

  assert_card_valid(c);

  return c;
}

card_t card_from_num(unsigned c) {
  assert( c >= 0);
  assert( c <= 51 );
  
  suit_t suit;
  switch (c / 13) {
    case 0:
      suit = SPADES;
      break;
    case 1:
      suit = HEARTS;
      break;
    case 2:
      suit = DIAMONDS;
      break;
    case 3:
      suit = CLUBS;
      break;
    default:
      printf("The number is not between 0 and 52\n");
      exit(EXIT_FAILURE);
  }
  card_t card;
  card.value = (c % 13) + 2;
  card.suit = suit;
  return card;
}
