#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#define MAX_N (7)

void spiral(int number, int n, int (*matrix)[n]);

int main() {
  int n;
  scanf("%d", &n);
  int matrix[MAX_N * MAX_N];
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++) {
      scanf("%d", &matrix[i * n + j]);
    }
  }
  int number = 1;
  spiral(number, n, (int (*)[n]) matrix);
  printf("\n");
  return 0;
}

void spiral(int number, int n, int (*matrix)[n]) {
  int l = n;
  int p = 0;
  int i = 0, j = -1;
  int temp[4] = { 1, 0, -1, 0 };
  ++number;
  while (l != 0) {
    if (i == j && (i != n - 1 && j != n - 1)) {
      ++number;
    }
    for (int k = 0; k != l; ++k) {
        j += temp[p % 4];
        i += temp[(p + 3) % 4];
        printf("%d ", matrix[i][j]);
    }
    ++p;
    l -= p % 2;
  }
}
