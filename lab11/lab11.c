#include <stdio.h>

typedef enum {
  OUTSIDE,
  FIRST_SOLIDUS,
  FIRST_ASTERISK,
  WORD,
  SEPARATOR,
  LAST_ASTERISK,
  LAST_SOLIDUS,
} State;

int number();

int main(void) {
  printf("Number of words in a multiline comment: %d\n", number());
  return 0;
}

int number() {
  int result = 0;
  State state = OUTSIDE;
  for (char ch = getchar(); ch != EOF; ch = getchar()) {
    switch (state) {
      case OUTSIDE:
      if (ch == '/')
        state = FIRST_SOLIDUS;
        break;
    case FIRST_SOLIDUS:
      if (ch == '*')
        state = FIRST_ASTERISK;
        break;
    case FIRST_ASTERISK:
      if (ch == '*')
        state = SEPARATOR;
      else if (ch == '/')
        state = OUTSIDE;
      else if (ch != ' ' && ch != '\n')
        state = WORD;
        break;
    case SEPARATOR:
      if (ch == '/') {
        state = OUTSIDE;
        continue;
      }
      if (ch == '*') {
        state = LAST_ASTERISK;
        continue;
      }
      if (ch == ' ' || ch == '\n') {
        ++result;
        state = FIRST_ASTERISK;
        continue;
      }
        else {
          state =  WORD;
          continue;
            }
      case WORD:
        if (ch == '*')
          state = LAST_ASTERISK;
        else if (ch == ' ' || ch == '\n') {
          ++result;
          state = FIRST_ASTERISK;
        }
      case LAST_ASTERISK:
        if (ch == '/') {
          ++result;
          state = OUTSIDE;
          continue;
        }
        if (ch == '*') {
          state = LAST_SOLIDUS;
          continue;
        }
        else {
          state = WORD;
          continue;
        }
      case LAST_SOLIDUS:
        if (ch != '/') {
          continue;
        }
        else {
          ++result;
          state = OUTSIDE;
          continue;
        }
      }
    }
  return result;
}
