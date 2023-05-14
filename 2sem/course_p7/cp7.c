#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

typedef struct {
    int *data;
    int size;
    int elemcount;
} vector;

void vectorCreate(vector * v, int size) {
    v->size = size;
    v->elemcount = 0;
    v->data = (int*)malloc(sizeof(int) * v->size);
}

void vectorDestroy(vector* v) {
    v->size = v->elemcount = 0;
    free(v->data);
}

void vectorPushBack(vector * v, int value) {
    if (v->elemcount == v->size) {
        v->size++;
        v->data = realloc(v->data, sizeof(int) * v->size);
    }
    v->data[v->elemcount++] = value;
}

int elemCount(char * name) {
    FILE *f = fopen(name, "r");
    int count = 0;
    int elem = 0;
    while (fscanf(f, "%d", &elem) && !feof(f)) {
        count++; 
    }
    return count;
}

int linesCount(char * name) {
    FILE *f = fopen(name, "r");
    int count = 0;
    while (!feof(f)) {
        if (fgetc(f) == '\n') {
            count++;
        }
    }
    return count;
}

vector * matrixInput(char * name, vector * v) {
    FILE *f = fopen(name, "r");
    vectorCreate(v, 1);
    int n = linesCount(name);
    int m = elemCount(name) / n;
    int *arr;
    arr = (int*)malloc(sizeof(int) * n * m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fscanf(f, "%d", &arr[i * m + j]);
        }
    }
    // PushBack
    for (int i = 0; i < n; i++) {
        int flag = 0;
        for (int j = 0; j < m; j++) {
            if (arr[i * m + j] != 0) {
                if (flag == 0) { // line
                    vectorPushBack(v, i + 1);
                    ++flag;
                }
                vectorPushBack(v, j + 1); // column
                vectorPushBack(v, arr[i * m + j]); // elem
            }
        }
        if (flag != 0) {
            vectorPushBack(v, 0); // ending of the line
        }
    }
    vectorPushBack(v, 0); // ending of the matrix
    free(arr);
    return v;
}

int vectorMax(vector * v) {
    int max = INT_MIN;
    for (int i = 2; i < v->size - 2; i += 2) {
        if (v->data[i] > max) {
            max = v->data[i];
        }
    }
    return max;
}

void vectorTask(char * name, vector * v) {
    int max = vectorMax(v);
    int column = 0;
    for (int i = 2; i < v->size - 2; i += 2) {
        if (v->data[i] == max) {
            column = v->data[i - 1];
            break;
        }
        if (v->data[i + 1] == 0) {
            i += 2;
            continue;
        }
    }
    printf("Max = %d, Column = %d\n", max, column);
    printf("Task:\n");
    FILE *f = fopen(name, "r");
    int n = linesCount(name); // lines
    int m = elemCount(name) / n; //columns
    fclose(f);
    vector temp;
    vectorCreate(&temp, n * m); // не знаю как, но оно заполнилось, ну и слава богу
    // (заполнило всё идеально, кроме первой строки матрицы)
    // for (int i = 0; i < m * n; i++) {
    //     printf("%d ", temp.data[i]);
    // }
    int k = 2;
    for  (int i = 0; i < m; i++) {
        if (v->data[k - 1] == i + 1) {
            temp.data[i] = v->data[k];
            k += 2;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (j == column - 1) {
                double tmp = temp.data[i * m + j];
                printf("%.2f ", tmp / max);
            }
            else {
                printf("%d ", temp.data[i * m + j]);
            }
        }
        printf("\n");
    } 
}

void vectorPrint(FILE * f, vector * v) {
    if (v == NULL) { 
        return;
    }
    printf("Matrix in one vector:\n");
    for (int i = 0; i < v->size; i++) {
        printf("%d ", v->data[i]);
    }
    printf("\n");
}

int main(int argc, char * argv[]) {
    char *name = argv[1];
    FILE *f = fopen(name, "r");
    if (f == NULL) {
        printf("Can not open file\n");
        return 0;
    }
    vector vec;
    vector *v = &vec;
    v = matrixInput(name, v);
    vectorPrint(f, v);
    vectorTask(name, v);
    fclose(f);
    return 0;
}


/*
Можно просто пихнуть в "void vectorTask(...)"
// Вывод задания в виде вектора (без нулевых элементов)
    printf("Task in vector:\n");
    for (int i = 2; i < v->size - 2; i += 2) {
        if (v->data[i - 1] == column) {
            double temp = v->data[i];
            printf("%.2f ", temp / max);
        }
        else {
            printf("%d ", v->data[i]);
        }
        if (v->data[i + 1] == 0) {
            i += 2;
            continue;
        }
    }
    printf("\n");
*/