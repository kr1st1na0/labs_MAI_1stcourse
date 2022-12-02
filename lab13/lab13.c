#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef UINT_WIDTH
#define UINT_WIDTH (32)
#endif

#define ALPHABET (26U)

#define VOWELS ( \
    1U << ('a' - 'a') | \
    1U << ('e' - 'a') | \
    1U << ('i' - 'a') | \
    1U << ('o' - 'a') | \
    1U << ('u' - 'a') \
)
#define CONSONANTS (UINT_MAX >> (UINT_WIDTH - ALPHABET) & ~VOWELS)

typedef unsigned set_data_elem;

enum {
    bits_per_char = 8,
    bits_per_elem = sizeof(set_data_elem) * bits_per_char,
    datalen = (1 << bits_per_char) / bits_per_elem,
};

typedef struct {
    set_data_elem data[datalen];
} set;

void set_clear(set *s) {
    memset(s->data, 0, sizeof(s->data));
}

void set_insert(set *s, int symbol) {
    s->data[symbol / bits_per_elem] |= 1U << (symbol % bits_per_elem);
}

bool set_in(const set *s, int symbol) {
    return (s->data[symbol / bits_per_elem] & (1U << symbol % bits_per_elem)) != 0;
}

set set_difference(const set *s1, const set *s2) {
    set result;
    for (int i = 0; i != datalen; ++i)
        result.data[i] = s1->data[i] ^ s2->data[i];
    return result;
}

typedef enum {
    IN,
    NOT_UNIQUE,
    OUT
} State;

bool is_consonant(int);
bool process();

int main() {
    if (process())
        printf("YES");
    else
        printf("NO");
    printf("\n");
    return 0;
}

bool process() {
    set word;
    State state = OUT;
    bool result = false;
    for (int ch = getchar(); ch != EOF; ch = getchar())
        switch (state) {
            case OUT: // outside the word
                if (!isalpha(ch))
                    break;
                set_clear(&word);
                state = IN;
                // fallthrough
            case IN:
                if (!isalpha(ch)) {
                    result = true;
                    state = OUT;
                } else if (is_consonant(ch)) {
                    const int value = ch - 'a';
                    if (set_in(&word, value)) // word isnt correct -> skip it
                        state = NOT_UNIQUE;
                    else // char isn't in set
                        set_insert(&word, value);
                }
                break;
            case NOT_UNIQUE:
                if (!isalpha(ch))
                    state = OUT;
                break;
        }
    return result;
}

bool is_consonant(int ch) {
    if (!isalpha(ch))
        return false;
    ch = tolower(ch);
    const set consonants = { { CONSONANTS } };
    return set_in(&consonants, ch - 'a');
}
