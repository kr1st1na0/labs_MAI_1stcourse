#ifndef CP7_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>
#include <assert.h>
#include <stdint.h>
#include <errno.h>
#include <stddef.h>

typedef struct {
    ptrdiff_t j;
    union {
        int value;
        ptrdiff_t i;
    };
} Elem;

typedef struct {
    Elem *data;
    size_t capacity, size;
} Vector;

typedef struct {
    Vector vector;
    size_t m, n;
} Matrix;

int matrixCreate(Matrix *matrix);

void matrixDestroy(Matrix *matrix);

int matrixInput(FILE * f, Matrix *matrix);

int matrixGet(Matrix *matrix,  size_t index1,  size_t index2);

int matrixSet(Matrix *matrix,  size_t index1,  size_t index2,  int value);


#endif