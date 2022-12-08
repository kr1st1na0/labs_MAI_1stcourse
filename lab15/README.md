# Отчёт по лабораторной работе №15 по курсу "Фундаментальная информатика"

<b>Студент группы:</b> <ins>М80-108Б-22 Былькова Кристина Алексеевна, № по списку 2</ins> 

<b>Контакты e-mail:</b> <ins>kristina.bilckova@yandex.ru</ins>

<b>Работа выполнена:</b> «8» <ins>декабря</ins> <ins>2022</ins> г.

<b>Преподаватель:</b> <ins>асп. каф. 806 Сахарин Никита Александрович</ins>

<b>Входной контроль знаний с оценкой:</b> <ins> </ins>

<b>Отчет сдан</b> «8» <ins>декабря</ins> <ins>2022</ins> г., <b>итоговая оценка</b> <ins> </ins>

<b>Подпись преподавателя:</b> ________________

## 1. Тема
Обработка матриц
## 2. Цель работы
Составить программу на языке Си, производящую обработку квадратной матрицы порядка NxN (1 <= N <= 8), из целых чисел, вводимой из стандартного входного текстового файла.
## 3. Задание (вариант № 2)
Замена всех максимальных элементов матрицы на чисто столбцов, содержащих её минимальный элемент.
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

<b>Редактор текстов:</b> emacs версия 25.2.2

<b>Утилиты операционной системы:</b> -

<b>Прикладные системы и программы:</b> gcc

<b>Местонахождение и имена файлов программ и данных на домашнем компьютере:</b> /home/kristina

## 6. Идея, метод, алгоритм решения задачи (в формах: словесной, псевдокода, графической [блок-схема, диаграмма, рисунок, таблица] или формальные спецификации с пред- и постусловиями)
1. Ввод размера матрицы; 
2. Создание матрицы;
3. Написание функций, необходимых для выполнения задачи;
4. Вывод ответа.

## 7. Сценарий выполнения работы [план работы, первоначальный текст программы в черновике (можно на отдельном листе) и тесты либо соображения по тестированию]. 
```
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
```

Пункты 1-7 отчета составляются сторого до начала лабораторной работы.
Допущен к выполнению работы.  
<b>Подпись преподавателя:</b> ________________
## 8. Распечатка протокола 
```
kristina@kristina-VirtualBox:~/Рабочий стол/lab15$ cc -g lab15.c && ./a.out
4
1 2 3 49
0 50 1 2
5 6 7 8
9 10 11 12

1 2 3 49 
0 1 1 2 
5 6 7 8 
9 10 11 12
kristina@kristina-VirtualBox:~/Рабочий стол/lab15$ cc -g lab15.c && ./a.out
7
1 2 3 4 5 6 49
-3 9 10 11 12 13 14
15 16 -3 18 19 20 21 
22 23 24 25 26 -3 28
29 30 49 -3 33 34 35
36 37 38 -3 40 41 42
49 44 45 -3 47 48 49

1 2 3 4 5 6 4 
-3 9 10 11 12 13 14 
15 16 -3 18 19 20 21 
22 23 24 25 26 -3 28 
29 30 4 -3 33 34 35 
36 37 38 -3 40 41 42 
4 44 45 -3 47 48 4 
```
## 9. Дневник отладки должен содержать дату и время сеансов отладки и основные события (ошибки в сценарии и программе, нестандартные ситуации) и краткие комментарии к ним. В дневнике отладки приводятся сведения об использовании других ЭВМ, существенном участии преподавателя и других лиц в написании и отладке программы.

| № |  Лаб. или дом. | Дата | Время | Событие | Действие по исправлению | Примечание |
| ------ | ------ | ------ | ------ | ------ | ------ | ------ |
| 1 | дом. | 08.12.22 | 13:00 | Выполнение лабораторной работы | - | - |
## 10. Замечания автора по существу работы — Написание команд для отработки навыков работы в ОС UNIX.
Приведение матрицы к ступенчатому виду.
```
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
```
```
kristina@kristina-VirtualBox:~/Рабочий стол/lab15$ cc -g lab15-2.c && ./a.out
3 3
1 2 3
4 5 6
7 8 9
7.000000 8.000000 9.000000 
0.000000 0.857143 1.714286 
0.000000 0.000000 0.000000 
kristina@kristina-VirtualBox:~/Рабочий стол/lab15$ cc -g lab15-2.c && ./a.out
3 2
1 2
3 4
5 6
5.000000 6.000000 
0.000000 0.800000 
0.000000 0.000000 
```
## 11. Выводы

Была написана программа на языке на Си, выполняющая указанное вариантом действие над квадратной матрицей. В результате выполнения работы, были приобретены навыки для работы с квадратными матрицами и обработки их элементов.

Недочёты при выполнении задания могут быть устранены следующим образом: —

<b>Подпись студента:</b> ____________________
