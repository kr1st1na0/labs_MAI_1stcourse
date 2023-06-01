#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>
#include <assert.h>
#include <stdint.h>
#include <errno.h>
#include <stddef.h>

#include "cp7.h"

static int vectorCreate(Vector * const v, size_t initialCapacity) {
    if (initialCapacity == 0)
        v->data = NULL;
    else {
        v->data = (Elem *) malloc(sizeof(Elem) * initialCapacity);
        if (v->data == NULL)
            return errno;
    }
    v->capacity = initialCapacity;
    v->size = 0;
    return 0;
}

static void vectorClear(Vector * const v) {
    v->size = 0;
    // You can nullify data if you want, but it makes no difference
}

static void vectorDestroy(Vector * const v) {
    v->capacity = v->size = 0;
    free(v->data);
}

static int vectorPushBack(Vector * const v, const Elem * const elem) {
    if (v->size == v->capacity) {
        v->capacity++;
        v->data = realloc(v->data, sizeof(Elem) * v->capacity);
    }
    v->data[v->size++] = *elem;
    return 0;
}

static int vectorMax(Vector * v) {
    int max = INT_MIN;
    for (int i = 1; i < v->capacity; ++i) {
        if (v->data[i].value > max) {
            max = v->data[i].value;
        }
    }
    return max;
}

static void vectorPrint(Vector * v) {
    if (v == NULL)
        return;
    printf("Matrix in one vector:\n");
    for (int i = 0; i < v->capacity; ++i) {
        printf("%ld ", v->data[i].j);
        printf("%d ", v->data[i].value);
    }
    printf("\n");
}

int matrixCreate(Matrix * const matrix) {
    const int err = vectorCreate(&matrix->vector, 1);
    if (err != 0)
        return err;
    vectorPushBack(&matrix->vector, &(Elem) { .j = -1, .i = -1 });
    matrix->m = matrix->n = 0;
    return 0;
}

void matrixDestroy(Matrix *matrix) {
    vectorDestroy(&matrix->vector);
    matrix->m = matrix->n = 0;
}

int matrixInput(FILE * f, Matrix * matrix) {
    size_t m, n;
    if (fscanf(f, "%zu%zu", &m, &n) != 2)
        return errno;
    vectorClear(&matrix->vector);
    matrix->m = m;
    matrix->n = n;
    for (size_t i = 0; i < m; ++i) {
        bool flag = false;
        for (size_t j = 0; j < n; ++j) {
            int value;
            if (fscanf(f, "%d", &value) != 1)
                return errno;
            if (value == 0)
                continue;
            if (!flag && vectorPushBack(&matrix->vector, &(Elem) { .j = -1, .i = i }) != 0)
                return errno;
            if (vectorPushBack(&matrix->vector, &(Elem) { .j = j, .value = value }) != 0)
                return errno;
            flag = true;
        }
    }
    vectorPushBack(&matrix->vector, &(Elem) { .j = -1, .i = -1 }); // ending of the matrix
    return 0;
}

int matrixGet(Matrix *  matrix,  size_t index1,  size_t index2) {
    if (matrix->m <= index1 || matrix->n <= index2)
        return EINVAL;
    size_t p = 0, q = 0;
    int ans = 0;
    for (int i = 0; i < matrix->vector.capacity - 1; ++i) {
        if (matrix->vector.data[i].j == -1) {
            p = matrix->vector.data[i].i;
        } 
        if (matrix->vector.data[i].j != -1) {
            q = matrix->vector.data[i].j;
            if (p == index1 && q == index2) ans = matrix->vector.data[i].value;
        }
    }
    return ans;
}

int matrixSet(Matrix *  matrix,  size_t index1,  size_t index2,  int value) {
    if (matrix->m <= index1 || matrix->n <= index2)
        return EINVAL;
    size_t p = 0, q = 0;
    for (int i = 0; i < matrix->vector.capacity - 1; ++i) {
        if (matrix->vector.data[i].j == -1) {
            p = matrix->vector.data[i].i;
        } 
        if (matrix->vector.data[i].j != -1) {
            q = matrix->vector.data[i].j;
            if (p == index1 && q == index2)  {
                matrix->vector.data[i].value = value;
            }
        }
    }
    return 0;
}

void matrixTask(Matrix * matrix) {
    int max = vectorMax(&matrix->vector);
    int column = 0;
    for (int i = 0; i < matrix->vector.capacity; ++i) {
        if (matrix->vector.data[i].value == max) {
            column = matrix->vector.data[i].j;
            break;
        }
    }
    printf("Max = %d, Column = %d\n", max, column);
    printf("Task:\n");
    int p, q;
    int n = matrix->n;
    int m = matrix->m;
    int **temp;
    temp = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < m; ++i) {
        temp[i] = (int*)malloc(m * sizeof(int));
    }        
    for (int i = 0; i < matrix->vector.capacity - 1; ++i) {
        if (matrix->vector.data[i].j == -1) {
            p = matrix->vector.data[i].i;
        } 
        if (matrix->vector.data[i].j != -1) {
            q = matrix->vector.data[i].j;
            temp[p][q] = matrix->vector.data[i].value;
        } 
    }
    for (int i = 0; i < m; ++i) {
        for  (int j = 0; j < n; ++j) {
            if (j == column) {
                double tmp = temp[i][j];
                printf("%.2f ", tmp / max);
            }
            else {
                printf("%d ", temp[i][j]);
            }
        }
        printf("\n");
    }
}

int main(int argc, char * argv[]) {
    char *name = argv[1];
    FILE *f = fopen(name, "r");
    if (f == NULL) {
        printf("Can not open file\n");
        return 0;
    }
    Matrix * matrix = malloc(sizeof(Matrix));
    matrixCreate(matrix);
    matrixInput(f, matrix);
    vectorPrint(&matrix->vector);
    matrixTask(matrix);

    fclose(f);
    return 0;
}