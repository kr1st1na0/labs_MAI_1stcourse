#include <stdio.h>
#include <stdlib.h>

#define MAX_N (8)

int max(int matrix[], int n) {
  int max_elem = -1e9;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++) {
      if (matrix[i * n + j] > max_elem)
        max_elem = matrix[i * n + j];
    }
  }
  return max_elem;
}

int min(int matrix[], int n) {
  int min_elem = 1e9;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++) {
      if (matrix[i * n + j] < min_elem)
        min_elem = matrix[i * n + j];
    }
  }
  return min_elem;
}

int columns_count(int matrix[], int n, int min_elem) {
  int count = 0;
  for (int j = 0; j < n; j++){
    int k = 0;
    for (int i = 0; i < n; i++) {
      if (matrix[i * n + j] == min_elem)
        ++k;
      //printf("%d ", matrix[i * n + j]);
    }
  //printf("\n");
  if (k > 0)
    ++count;
  }
  return count;
}

int replace(int matrix[], int n, int max_elem, int count) {
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++) {
      if (matrix[i * n + j] == max_elem)
        matrix[i * n + j] = count;
    }
  }
  return *matrix;
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
  int max_elem = max(matrix, n);
  printf("Max elem: %d", max_elem);
  printf("\n");
  //min
  int min_elem = min(matrix, n);
  printf("Min elem: %d", min_elem);
  printf("\n");
  //count
  int count = columns_count(matrix, n, min_elem);
  printf("Number of columns with min_elem: %d", count);
  printf("\n");
  //replace
  replace(matrix, n, max_elem, count);
  //output
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++) {
      printf("%d ", matrix[i * n + j]);
    }
    printf("\n");
  }
}
