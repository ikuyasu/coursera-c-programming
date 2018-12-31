#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "deck.h"

void print_hand(deck_t * hand){
  card_t ** cards = hand -> cards;
  size_t n_cards = hand -> n_cards;
  for (int i = 0; i < n_cards; i++) {
    print_card(*cards[i]);
    printf(" ");
  }
}

int compareCards(card_t c1, card_t c2) {
  // return 1 if same, 0 different
  return (c1.value == c2.value) && (c1.suit == c2.suit);
}

int deck_contains(deck_t * d, card_t c) {
  card_t ** cards = d -> cards;
  size_t n_cards = d -> n_cards;
  for (int i = 0; i < n_cards; i++) {
    if (compareCards(c, *cards[i])) { // 1
      return 1;
    }
  }
  return 0;
}



void shuffle(deck_t * d){
  card_t ** cards = d -> cards;
  size_t n_cards = d -> n_cards;
  int r = 0;
  int n_shuf = 10;
  for (int shuf = 0; shuf < n_shuf; shuf++) {
    for (int i = 0; i < n_cards - 1; i++) {
      r = rand() % 2; // rand() -> 0 to RAND_MAX
      if (r) {
        card_t * temp = cards[i];
        cards[i] = cards[i+1];
        cards[i+1] = temp;
      }
    }
  }
}

void assert_full_deck(deck_t * d) {
  card_t ** cards = d -> cards;  
  size_t n_cards = d -> n_cards;
  for (size_t i = 0; i < n_cards - 1; i++)  { // no card left to comparefor the last card
    for (size_t j = i + 1; j < n_cards; j++) {
      if (compareCards(*cards[i], *cards[j])) {
        fprintf(stderr, "The deck contains a duplicate.\n");
        exit(EXIT_FAILURE);
      }
    }
  }
}
