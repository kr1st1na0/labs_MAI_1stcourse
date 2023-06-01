# Отчёт по курсовой работе №7 по курсу “Языки и методы программирования”

<b>Студент группы:</b> <ins>М80-108Б-22 Былькова Кристина Алексеевна, № по списку 2</ins>

<b>Контакты e-mail:</b> <ins>kristina.bilckova@yandex.ru</ins>

<b>Работа выполнена:</b> «20» <ins>мая</ins> <ins>2023</ins> г.

<b>Преподаватель:</b> <ins>асп. каф. 806 Сахарин Никита Александрович</ins>

<b>Входной контроль знаний с оценкой:</b> <ins>-</ins>

<b>Отчет сдан</b> «20» <ins>мая</ins> <ins>2023</ins> г., <b>итоговая оценка</b>-<ins>

<b>Подпись преподавателя:</b> ___________


## 1. Тема
Разреженные матрицы
## 2. Цель работы
Составить программу на языке Си с процедурами и/или функциями для обработки прямоугольных разреженных матриц с элементами целого типа, которая:
1. Вводит матрицы различного размера, представленные во входном текстовом файле в обычном формате (по строкам), с одновременным размещением ненулевых элементов в разреженной матрице в соответствии с заданной схемой;
2. Печатает введенные матрицы во внутреннем представлении согласно заданной схеме размещения и в обычном (естественном) виде;
3. Выполняет необходимые преобразования разреженных матриц (или вычисления над ними) путем обращения к соответствующим процедурам и/или функциям;
4. Печатает результат преобразования (вычисления) согласно заданной схеме размещения и в обычном виде.
## 3. Задание (вариант № 2)
- Вариант схемы размещения: ((2 + 3) % 4) + 1 = 2 - один вектор
- Вариант преобразования - ((2 – 1) % 11) + 1 = 2 - определить максимальный по модулю элемент матрицы и разделить на него все элементы столбца, в котором он находится, а если таких элементов несколько, обработать предпоследний столбец, содержащий такой элемент
- Вариант физического представления - ([1.5 * ((3 + 8) % 9)]+2) % 2 + 1 = 2 - отображение на динамические структуры

## 4. Оборудование:
<b>Процессор:</b> AMD Ryzen9-5900HS, 8 ядер

<b>ОП:</b> 16gb

<b>SSD:</b> 1 Tb SSD

<b>Монитор:</b> 15.6" - 2560x1440

<b>Графика:</b> NV GeForce RTX 3080

## 5. Программное обеспечение:
<b>Операционная система семейства:</b> VirtualBox 6.1.38 - Ubuntu 22.04.01 LTS

<b>Интерпретатор команд:</b> bash версия 4.4.19

<b>Система программирования:</b> -

<b>Редактор текстов:</b> -

<b>Утилиты операционной системы:</b> -

<b>Прикладные системы и программы:</b> -

</b>Местонахождение и имена файлов программ и данных на домашнем компьютере:</b> /home/kristina

## 6. Идея, метод, алгоритм решения задачи (в формах: словесной, псевдокода, графической [блок-схема, диаграмма, рисунок, таблица] или формальные спецификации с пред- и постусловиями)

1. vectorCreate - создание вектора
2. vectorClear - очистка вектора 
3. vectorDestroy - уничтожение вектора
4. vectorPushBack - добавление элемента в конец вектора
5. vectorMax - поиск максимального элемента в векторе
6. vectorPrint - печать матрицы в соответствии со схемой размещения
7. matrixCreate - создание матрицы
8. matrixDestroy - уничтожение матрицы
9. matrixInput - считывание матрицы в вектор
10. matrixGet - получить элемент по индексам
11. matrixSet - поместить элемент в позицию
12. matrixTask - выполнение задания

## 7. Сценарий выполнения работы [план работы, первоначальный текст программы в черновике (можно на отдельном листе) и тесты либо соображения по тестированию].

```:src/cp7.h
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

int matrixInput(FILE * f, Matrix * matrix);

#endif
```

``` :src/cp7.c
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
    matrix->vector.data->j = matrix->vector.data->i = -1;
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
```

Пункты 1-7 отчета составляются сторого до начала лабораторной работы.
Допущен к выполнению работы.  
<b>Подпись преподавателя:</b> _____________________

## 8. Распечатка протокола 

```
kristinab@LAPTOP-SFU9B1F4:/mnt/c/Users/Admin/Projects/C/cp7$ cat test1.txt
5 5
25 0 0 1 0
5 0 0 0 2
0 0 4 0 0
0 1 0 0 3
0 0 0 0 0
kristinab@LAPTOP-SFU9B1F4:/mnt/c/Users/Admin/Projects/C/cp7$ cc cp7.c && ./a.out test1.txt
Matrix in one vector:
-1 0 0 25 3 1 -1 1 0 5 4 2 -1 2 2 4 -1 3 1 1 4 3 -1 -1
Max = 25, Column = 0
Task:
1.00 0 0 1 0
0.20 0 0 0 2
0.00 0 4 0 0
0.00 1 0 0 3
0.00 0 0 0 0
kristinab@LAPTOP-SFU9B1F4:/mnt/c/Users/Admin/Projects/C/cp7$ cat test2.txt
6 4
1 2 3 4
0 0 1 0
1 0 0 0
5 0 0 1
8 2 0 50
0 0 9 0
kristinab@LAPTOP-SFU9B1F4:/mnt/c/Users/Admin/Projects/C/cp7$ cc cp7.c && ./a.out test2.txt
Matrix in one vector:
-1 0 0 1 1 2 2 3 3 4 -1 1 2 1 -1 2 0 1 -1 3 0 5 3 1 -1 4 0 8 1 2 3 50 -1 5 2 9 -1 -1
Max = 50, Column = 3
Task:
1 2 3 0.08
0 0 1 0.00
1 0 0 0.00
5 0 0 0.02
8 2 0 1.00
0 0 9 0.00
kristinab@LAPTOP-SFU9B1F4:/mnt/c/Users/Admin/Projects/C/cp7$ cat test3.txt
4 5
0 4 0 0 1
0 0 1 0 2
2 0 0 0 3
0 2 0 1 0
kristinab@LAPTOP-SFU9B1F4:/mnt/c/Users/Admin/Projects/C/cp7$ cc cp7.c && ./a.out test3.txt
Matrix in one vector:
-1 0 1 4 4 1 -1 1 2 1 4 2 -1 2 0 2 4 3 -1 3 1 2 3 1 -1 -1
Max = 4, Column = 1
Task:
0 1.00 0 0 1
0 0.00 1 0 2
2 0.00 0 0 3
0 0.50 0 1 0
```


## 9. Дневник отладки должен содержать дату и время сеансов отладки и основные события (ошибки в сценарии и программе, нестандартные ситуации) и краткие комментарии к ним. В дневнике отладки приводятся сведения об использовании других ЭВМ, существенном участии преподавателя и других лиц в написании и отладке программы.

| № |  Лаб. или дом. | Дата | Время | Событие | Действие по исправлению | Примечание |
| ------ | ------ | ------ | ------ | ------ | ------ | ------ |
| 1 | дом. | 20.05.23 | 13:00 | Выполнение лабораторной работы | - | - |

## 10. Замечания автора по существу работы

<b>div4</b>

- [Задача во время контеста](https://codeforces.com/contest/1807/submission/198132534)
- [Дорешка](https://codeforces.com/contest/1807/submission/205902444)
- [Дорешка](https://codeforces.com/contest/1807/submission/205904724)
- [Дорешка](https://codeforces.com/contest/1807/submission/205904227)


## 11. Выводы
Была составлена программа на языке Си с процедурами и функциями для обработки прямоугольных разреженных матриц с элементами целого типа. Были приобретены навыки, которые будут полезны для выполнения других лабораторных работ и курсовых проектов.

Недочёты при выполнении задания могут быть устранены следующим образом: —

<b>Подпись студента:</b> _________________


