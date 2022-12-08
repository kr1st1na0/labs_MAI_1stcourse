#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_N (8)

#define EPSILON 2.2204460492503131e-16

typedef unsigned uint;
typedef float flt;
typedef double dbl;
typedef long double ldbl;

void switch_row(const size_t i, const size_t j, const size_t n, dbl (*mat)[n]) {
    for (size_t k = 0; k < n; ++k) {
        const dbl temp = mat[i][k];
        mat[i][k] = mat[j][k];
        mat[j][k] = temp;
    }
}

size_t find_max(const size_t i, const size_t j, const size_t m, const size_t n, const dbl (*mat)[n]) {
    size_t max_i = 0;
    dbl maxx = 0.0;
    for (size_t k = i; k < m; ++k) {
        if (fabs(mat[k][j]) > fabs(maxx)) {
            max_i = k;
            maxx = fabs(mat[k][j]);
        }
    }
    return max_i;
}

// i-th row += alpha * j-th row
void add_row(const size_t i, const dbl alpha, const size_t j, const size_t n, dbl (*mat)[n]) {
    for (size_t l = j + 1; l < n; ++l)
        mat[i][l] += alpha * mat[j][l];
}

void column_to_null(const size_t i, const size_t j, const size_t m, const size_t n, dbl (*mat)[n]) {
    for (size_t k = i + 1; k < m; ++k) {
        const dbl mu = -mat[k][j] / mat[i][j];
        mat[k][j] = 0.0;
        add_row(k, mu, i, n, mat);
    }
}

void solve(const size_t m, const size_t n, dbl (*mat)[n]) {
    for (size_t i = 0, j = 0; i < m, j < n; ++i, ++j ) {
        const size_t max_i = find_max(i, j, m, n, mat);
        if (fabs(mat[max_i][j]) < EPSILON) {
            ++j;
            continue;
        }
        if (max_i != i)
            switch_row(i, max_i, n, mat);
        column_to_null(i, j, m, n, mat);
    }
}

int main() {
  size_t m; //strings
  size_t n; //columns
  scanf("%ld%ld", &m, &n);
  dbl mat[MAX_N * MAX_N];
  for (size_t i = 0; i < m; i++){
    for (size_t j = 0; j < n; j++) {
      scanf("%lf", &mat[i * n + j]);
    }
  }
  solve(m, n, (dbl (*)[n]) mat);
  for (size_t i = 0; i < m; i++){
    for (size_t j = 0; j < n; j++) {
      printf("%lf ", mat[i * n + j]);
    }
    printf("\n");
  }
  return 0;
}
