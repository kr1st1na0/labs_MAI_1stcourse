#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>

#define MAX_N (7)

int main() {
  srand(time(0));
  int n;
  printf("Matrix size: ");
  scanf("%d", &n);
  int matrix[MAX_N][MAX_N];
  int i, j, k;
  printf("Matrix:\n");
  for (i = 0; i < n; i++){
    for (j = 0; j < n; j++) {
      //scanf("%d", &matrix[i][j]);
      matrix[i][j] = rand() % 10;
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
}
  printf("Out: ");
  for (i = n - 1; i >= 0; i-- ) {
    for (j = i, k = 0; j < n; j++, k++) {
      printf("%d ", matrix[k][j]);
    }
  }
  for (i = 1; i < n; i++) {
    for (j = 0, k = i; k < n; j++, k++) {
      printf("%d ", matrix[k][j]);
    }
  }
    printf("\n");
    return 0;
}
