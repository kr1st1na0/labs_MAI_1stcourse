#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N (4096) //capacity in bits

typedef unsigned uint;

enum {
    BITS_PER_ELEM = sizeof(uint) * CHAR_BIT,
    DATALEN = (N + BITS_PER_ELEM - 1) / BITS_PER_ELEM,
};

typedef struct {
    uint data[DATALEN];
} set;

set set_intersection(const set *s1, const set *s2) {
  set result;
  for (int i = 0; i != DATALEN; ++i)
    result.data[i] = s1->data[i] & s2->data[i];
  return result;
}

set set_difference(const set *s1, const set *s2) {
  set result;
  for (int i = 0; i != DATALEN; ++i)
    result.data[i] = s1->data[i] & ~(s2->data[i]);
  return result;
}

set set_symmetric_difference(const set *s1, const set *s2) {
  set result;
  for (int i = 0; i != DATALEN; ++i)
    result.data[i] = s1->data[i] ^ s2->data[i];
  return result;
}

set set_union(const set *s1, const set *s2) {
  set result;
  for (int i = 0; i != DATALEN; ++i)
    result.data[i] = s1->data[i] | s2->data[i];
  return result;
}

bool set_includes(const set *s1, const set *s2) {
  for (int i = 0; i != DATALEN; ++i)
    if ((s1->data[i] | s2->data[i]) != s1->data[i])
      return false;
  return true;
}

void set_clear(set *s) {
    memset(s->data, 0, sizeof(s->data));
}

void set_insert(set *s, int symbol) {
    s->data[symbol / BITS_PER_ELEM] |= 1U << (symbol % BITS_PER_ELEM);
}

bool set_in(const set *s, int symbol) {
    return (s->data[symbol / BITS_PER_ELEM] >> (symbol % BITS_PER_ELEM)) & 1U;
}

int main() {
  set s1, s2, s;
  set_clear(&s1);
  set_clear(&s2);

  for (int i = 1; i <= 5; i++) {
    set_insert(&s1, i);
  }
  for (int i = 1; i <= 10; i++) {
    set_insert(&s2, i);
  }
//Union
  printf("Union\n");
  s = set_union(&s1, &s2);
  for (int i = 1; i <= 10; i++) {
    if (set_in(&s, i))
      printf("%dYes\n", i);
    else
      printf("%dNo\n", i);
  }
//Difference
  printf("Difference\n");
  s = set_difference(&s1, &s2);
  for (int i = 1; i <= 10; i++) {
    if (set_in(&s, i))
      printf("%dYes\n", i);
    else
      printf("%dNo\n", i);
  }
//Symmetric difference
  printf("Symmetric difference\n");
  s = set_symmetric_difference(&s1, &s2);
  for (int i = 1; i <= 10; i++) {
    if (set_in(&s, i))
      printf("%dYes\n", i);
    else
      printf("%dNo\n", i);
  }
  //Includes
  printf("s2 includes s1: ");
  printf("%d\n", set_includes(&s2, &s1));
  printf("s1 includes s2: ");
  printf("%d\n", set_includes(&s1, &s2));
  return 0;
}
