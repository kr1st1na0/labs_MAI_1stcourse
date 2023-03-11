#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_N (8)

int max(int n, int (*matrix)[n]) {
  int max_elem = INT_MIN;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++) {
      if (matrix[i][j] > max_elem)
        max_elem = matrix[i][j];
    }
  }
  return max_elem;
}

int min(int n, int (*matrix)[n]) {
  int min_elem = INT_MAX;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++) {
      if (matrix[i][j] < min_elem)
        min_elem = matrix[i][j];
    }
  }
  return min_elem;
}

int columns_count(int n, int (*matrix)[n], int min_elem) {
  int count = 0;
  for (int j = 0; j < n; j++){
    int k = 0;
    for (int i = 0; i < n; i++) {
      if (matrix[i][j] == min_elem)
        ++k;
    }
  if (k > 0)
    ++count;
  }
  return count;
}

void replace(int n, int (*matrix)[n], int max_elem, int count) {
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++) {
      if (matrix[i][j] == max_elem)
        matrix[i][j] = count;
    }
  }
}

int main() {
  int n;
  printf("Matrix size: ");
  scanf("%d", &n);
  int matrix[MAX_N * MAX_N];
  printf("Matrix:\n");
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++) {
      scanf("%d", &matrix[i * n + j]);
    }
  }
  //max
  int max_elem = max(n, (int (*)[n]) matrix);
  printf("Max elem: %d", max_elem);
  printf("\n");
  //min
  int min_elem = min(n, (int (*)[n]) matrix);
  printf("Min elem: %d", min_elem);
  printf("\n");
  //count
  int count = columns_count(n, (int (*)[n]) matrix, min_elem);
  printf("Number of columns with min_elem: %d", count);
  printf("\n");
  //replace
  replace(n, (int (*)[n]) matrix, max_elem, count);
  //output
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++) {
      printf("%d ", matrix[i * n + j]);
    }
    printf("\n");
  }
}
