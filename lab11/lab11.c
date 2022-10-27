#include <stdio.h>

int number();

int main(void) {
  printf("Number of words in a multiline comment: %d\n",number());
  return 0;
}

int number() {
  int count = 0, k = 0;
  char ch;
  for (ch = getchar(); ch != EOF; ch = getchar()) {
    if (ch == '\n') {
      continue;
    }
    if (k == 0) { //ouside the comment
      if (ch == '/') {
        k = 1;
      }
      continue;
    }
    if (k == 1) {
      if (ch == '*') {
        k = 2;
        continue;
      }
    }
    if (k == 4) {
      if (ch == '/') {
        k = 0;
        continue;
      }
      if (ch == '*') {
        k = 5;
        continue;
      }
      if (ch == ' ') {
        count = count + 1;
        k = 2;
        continue;
      }
      else {
        k = 3;
        continue;
      }
    }
    if (k == 2) { //inside the comment
      if (ch == '*') {
        k = 4;
        continue;
      }
      if (ch == ' ') {
        continue;
      }
      else {
        k = 3; //see the word
      }
    }
    if (k == 3) {
      if (ch == '*') {
        k = 5;
        continue;
      }
      else {
        if (ch != ' ') {
          continue;
        }
        else {
          count = count + 1;
          k = 2;
        }
      }
    }
    if (k == 5) {
      if (ch == '/') {
        count = count + 1;
        k = 0;
        continue;
      }
      if (ch == '*') {
        k = 6;
        continue;
      }
      else {
        k = 3;
        continue;
      }
    }
    if (k == 6) {
      if (ch != '/') {
        continue;
      }
      else {
        count = count + 1;
        k = 0;
        continue;
      }
    }
  }
  return count;	
}
