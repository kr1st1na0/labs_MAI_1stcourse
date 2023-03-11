#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#define MAX_N (7)

void diag(int d, int n, int (*matrix)[n]);

int main() {
  int n;
  scanf("%d", &n);
  int matrix[MAX_N * MAX_N];
  int i, j, k;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      scanf("%d", &matrix[i * n + j]);
    }
  }
  for (int d = 1; d < n*2; d++) {
    diag(d, n, (int (*)[n]) matrix);
  }
  printf("\n");
  return 0;
}

void diag(int d, int n, int (*matrix)[n]) {
  int i, j, k;
  int t = 1;
  for (i = n - 1; i >= 0; i--) {
    for (j = i, k = 0; j < n; j++, k++) {
        if (t == d) printf("%d ", matrix[k][j]);
    }
    ++t;
  }
  for (i = 1; i < n; i++) {
    for (j = 0, k = i; k < n; j++, k++) {
      if (t == d) printf("%d ", matrix[k][j]);
    }
    ++t;
  }
}
