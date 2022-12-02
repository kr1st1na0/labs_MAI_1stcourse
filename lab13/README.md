# Отчёт по лабораторной работе №13 по курсу "Фундаментальная информатика"

<b>Студент группы:</b> <ins>М80-108Б-22 Былькова Кристина Алексеевна, № по списку 2</ins> 

<b>Контакты e-mail:</b> <ins>kristina.bilckova@yandex.ru</ins>

<b>Работа выполнена:</b> «26» <ins>ноября</ins> <ins>2022</ins> г.

<b>Преподаватель:</b> <ins>асп. каф. 806 Сахарин Никита Александрович</ins>

<b>Входной контроль знаний с оценкой:</b> <ins>5 (отлично)</ins>

<b>Отчет сдан</b> «26» <ins>ноября</ins> <ins>2022</ins> г., <b>итоговая оценка</b> <ins>5 (отлично)</ins>

<b>Подпись преподавателя:</b> ________________

## 1. Тема
Множества.
## 2. Цель работы
В соответствии с вариантом задания составить программу проверки характеристик введённых последовательностей слов и печати развёрнутого ответа.
## 3. Задание (вариант № 2)
Есть ли слово, все согласные которого различны?
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
1. Считываем входные данные; 
2. Если текущий символ - буква, то проверяем наличие этой буквы в множестве согласных. Не буква - идём дальше;
3. Если согласная - проверяем, есть ли в текущем множестве. Гласная - идём дальше;
4. Если согласная есть в текущем множестве, то слово нам не подходит - пропускаем его. Если нет в текущем множестве - добавляем данную согласную в множество.

## 7. Сценарий выполнения работы [план работы, первоначальный текст программы в черновике (можно на отдельном листе) и тесты либо соображения по тестированию]. 
```
#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef UINT_WIDTH
#define UINT_WIDTH (32)
#endif

#define ALPHABET (26U)

#define VOWELS ( \
    1U << ('a' - 'a') | \
    1U << ('e' - 'a') | \
    1U << ('i' - 'a') | \
    1U << ('o' - 'a') | \
    1U << ('u' - 'a') \
)
#define CONSONANTS (UINT_MAX >> (UINT_WIDTH - ALPHABET) & ~VOWELS)

typedef unsigned set_data_elem;

enum {
    bits_per_char = 8,
    bits_per_elem = sizeof(set_data_elem) * bits_per_char,
    datalen = (1 << bits_per_char) / bits_per_elem,
};

typedef struct {
    set_data_elem data[datalen];
} set;

void set_clear(set *s) {
    memset(s->data, 0, sizeof(s->data));
}

void set_insert(set *s, int symbol) {
    s->data[symbol / bits_per_elem] |= 1U << (symbol % bits_per_elem);
}

bool set_in(const set *s, int symbol) {
    return (s->data[symbol / bits_per_elem] & (1U << symbol % bits_per_elem)) != 0;
}

set set_difference(const set *s1, const set *s2) {
    set result;
    for (int i = 0; i != datalen; ++i)
        result.data[i] = s1->data[i] ^ s2->data[i];
    return result;
}

typedef enum {
    IN,
    NOT_UNIQUE,
    OUT
} State;

bool is_consonant(int);
bool process();

int main() {
    if (process())
        printf("YES");
    else
        printf("NO");
    printf("\n");
    return 0;
}

bool process() {
    set word;
    State state = OUT;
    bool result = false;
    for (int ch = getchar(); ch != EOF; ch = getchar())
        switch (state) {
            case OUT: // outside the word
                if (!isalpha(ch))
                    break;
                set_clear(&word);
                state = IN;
                // fallthrough
            case IN:
                if (!isalpha(ch)) {
                    result = true;
                    state = OUT;
                } else if (is_consonant(ch)) {
                    const int value = ch - 'a';
                    if (set_in(&word, value)) // word isnt correct -> skip it
                        state = NOT_UNIQUE;
                    else // char isn't in set
                        set_insert(&word, value);
                }
                break;
            case NOT_UNIQUE:
                if (!isalpha(ch))
                    state = OUT;
                break;
        }
    return result;
}

bool is_consonant(int ch) {
    if (!isalpha(ch))
        return false;
    ch = tolower(ch);
    const set consonants = { { CONSONANTS } };
    return set_in(&consonants, ch - 'a');
}
```

Пункты 1-7 отчета составляются сторого до начала лабораторной работы.
Допущен к выполнению работы.  
<b>Подпись преподавателя:</b> ________________
## 8. Распечатка протокола 
```
kristina@kristina-VirtualBox:~/Рабочий стол/lab13$ cc -g lab13.c && ./a.out
ggttoooe pop
NO
kristina@kristina-VirtualBox:~/Рабочий стол/lab13$ cc -g lab13.c && ./a.out
koeuooeul
pppp
gg
sssoe
YES
```
## 9. Дневник отладки должен содержать дату и время сеансов отладки и основные события (ошибки в сценарии и программе, нестандартные ситуации) и краткие комментарии к ним. В дневнике отладки приводятся сведения об использовании других ЭВМ, существенном участии преподавателя и других лиц в написании и отладке программы.

| № |  Лаб. или дом. | Дата | Время | Событие | Действие по исправлению | Примечание |
| ------ | ------ | ------ | ------ | ------ | ------ | ------ |
| 1 | дом. | 26.11.22 | 13:00 | Выполнение лабораторной работы | - | - |
## 10. Замечания автора по существу работы — Написание команд для отработки навыков работы в ОС UNIX.
```
#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N (4096) //capacity in bits

typedef unsigned uint;

enum {
    BITS_PER_ELEM = sizeof(uint) * CHAR_BIT,
    DATALEN = (N + BITS_PER_ELEM - 1) / BITS_PER_ELEM,
};

typedef struct {
    uint data[DATALEN];
} set;

set set_intersection(const set *s1, const set *s2) {
  set result;
  for (int i = 0; i != DATALEN; ++i)
    result.data[i] = s1->data[i] & s2->data[i];
  return result;
}

set set_difference(const set *s1, const set *s2) {
  set result;
  for (int i = 0; i != DATALEN; ++i)
    result.data[i] = s1->data[i] & ~(s2->data[i]);
  return result;
}

set set_symmetric_difference(const set *s1, const set *s2) {
  set result;
  for (int i = 0; i != DATALEN; ++i)
    result.data[i] = s1->data[i] ^ s2->data[i];
  return result;
}

set set_union(const set *s1, const set *s2) {
  set result;
  for (int i = 0; i != DATALEN; ++i)
    result.data[i] = s1->data[i] | s2->data[i];
  return result;
}

bool set_includes(const set *s1, const set *s2) {
  for (int i = 0; i != DATALEN; ++i)
    if ((s1->data[i] | s2->data[i]) != s1->data[i])
      return false;
  return true;
}

void set_clear(set *s) {
    memset(s->data, 0, sizeof(s->data));
}

void set_insert(set *s, int symbol) {
    s->data[symbol / BITS_PER_ELEM] |= 1U << (symbol % BITS_PER_ELEM);
}

bool set_in(const set *s, int symbol) {
    return (s->data[symbol / BITS_PER_ELEM] >> (symbol % BITS_PER_ELEM)) & 1U;
}

int main() {
  set s1, s2, s;
  set_clear(&s1);
  set_clear(&s2);

  for (int i = 1; i <= 5; i++) {
    set_insert(&s1, i);
  }
  for (int i = 1; i <= 10; i++) {
    set_insert(&s2, i);
  }
//Union
  printf("Union\n");
  s = set_union(&s1, &s2);
  for (int i = 1; i <= 10; i++) {
    if (set_in(&s, i))
      printf("%dYes\n", i);
    else
      printf("%dNo\n", i);
  }
//Difference
  printf("Difference\n");
  s = set_difference(&s1, &s2);
  for (int i = 1; i <= 10; i++) {
    if (set_in(&s, i))
      printf("%dYes\n", i);
    else
      printf("%dNo\n", i);
  }
//Symmetric difference
  printf("Symmetric difference\n");
  s = set_symmetric_difference(&s1, &s2);
  for (int i = 1; i <= 10; i++) {
    if (set_in(&s, i))
      printf("%dYes\n", i);
    else
      printf("%dNo\n", i);
  }
  //Includes
  printf("s2 includes s1: ");
  printf("%d\n", set_includes(&s2, &s1));
  printf("s1 includes s2: ");
  printf("%d\n", set_includes(&s1, &s2));
  return 0;
}
```
## 11. Выводы

Была написана программа на языке на Си, выполняющая указанное вариантом действие над значениями в целом типе данных. В результате выполнения работы, были приобретены навыки для работы с числами в целом типе данных.

Недочёты при выполнении задания могут быть устранены следующим образом: —

<b>Подпись студента:</b> ____________________
