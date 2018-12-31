#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct vegi_tag {
  char * name;
  int price;
};
typedef struct vegi_tag vegi_t;

struct vegi_pack_tag {
  vegi_t ** vegiPack;
  size_t n_vegis;
};
typedef struct vegi_pack_tag vegi_pack_t;

vegi_t createVegiItem(char * name, int price) {
  vegi_t * vegi;
  vegi -> name = name;
  vegi -> price = price;
  return *vegi;
}

void printVegi(vegi_t vegi) {
  printf("%s is sold at %d\n", vegi.name, vegi.price);
}

int main(void) {
  printf("starting the program...\n");
  vegi_t eggplant = createVegiItem("eggplant", 2);
  vegi_t * vegiPack[3];
  char * vegis[] = {"eggplant", "pumpkin", "cucumber"};
  int prices[] = {2, 3, 4};
  printf("in main: 35\n");
  size_t n_vegis = 3;
  for (size_t i = 0; i < n_vegis; i++) {
    printf("in for loop: 38\n");
    vegi_t v = createVegiItem(vegis[i], prices[i]);
    vegiPack[i] = &v;
  }

  for (size_t i = 0; i < n_vegis; i++) {
    printVegi(*vegiPack[i]);
  }
  return EXIT_SUCCESS;
}