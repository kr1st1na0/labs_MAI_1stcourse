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
2. vectorDestroy - уничтожение вектора 
3. vectorPushBack - добавление элемента в конец вектора
4. elemCount - подсчёт количества элементов в матрице
5. linesCount - подсчёт количества строк в матрице
6. matrixInput - преобразование матрицы в вектор
7. vectorMax - поиск максимального элемента в векторе
8. vectorTask - выполнение задания
9. vectorPrint - печать матрицы в соответствии со схемой размещения

## 7. Сценарий выполнения работы [план работы, первоначальный текст программы в черновике (можно на отдельном листе) и тесты либо соображения по тестированию].

``` :src/cp7.c
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
    vectorCreate(&temp, n * m);
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
```

Пункты 1-7 отчета составляются сторого до начала лабораторной работы.
Допущен к выполнению работы.  
<b>Подпись преподавателя:</b> _____________________

## 8. Распечатка протокола 

```
kristinab@LAPTOP-SFU9B1F4:/mnt/c/Users/Admin/Projects/C/cp7$ cat test1.txt
25 0 0 1 0
5 0 0 0 2
0 0 4 0 0
0 1 0 0 3
0 0 0 0 0
kristinab@LAPTOP-SFU9B1F4:/mnt/c/Users/Admin/Projects/C/cp7$ gcc cp7.c && ./a.out test1.txt
Matrix in one vector:
1 1 25 4 1 0 2 1 5 5 2 0 3 3 4 0 4 2 1 5 3 0 0
Max = 25, Column = 1
Task:
1.00 0 0 1 0
0.20 0 0 0 2
0.00 0 4 0 0
0.00 1 0 0 3
0.00 0 0 0 0
kristinab@LAPTOP-SFU9B1F4:/mnt/c/Users/Admin/Projects/C/cp7$ cat test2.txt
1 2 3 4
0 0 1 0
1 0 0 0
5 0 0 1
8 2 0 50
0 0 9 0
kristinab@LAPTOP-SFU9B1F4:/mnt/c/Users/Admin/Projects/C/cp7$ gcc cp7.c && ./a.out test2.txt
Matrix in one vector:
1 1 1 2 2 3 3 4 4 0 2 3 1 0 3 1 1 0 4 1 5 4 1 0 5 1 8 2 2 4 50 0 6 3 9 0 0
Max = 50, Column = 4
Task:
1 2 3 0.08
0 0 1 0.00
1 0 0 0.00
5 0 0 0.02
8 2 0 1.00
0 0 9 0.00
kristinab@LAPTOP-SFU9B1F4:/mnt/c/Users/Admin/Projects/C/cp7$ cat test3.txt
0 4 0 0 1
0 0 1 0 2
2 0 0 0 3
0 2 0 1 0
kristinab@LAPTOP-SFU9B1F4:/mnt/c/Users/Admin/Projects/C/cp7$ gcc cp7.c && ./a.out test3.txt
Matrix in one vector:
1 2 4 5 1 0 2 3 1 5 2 0 3 1 2 5 3 0 4 2 2 4 1 0 0
Max = 4, Column = 2
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


