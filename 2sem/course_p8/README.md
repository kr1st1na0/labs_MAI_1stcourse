# Отчёт по курсовой работе №8 по курсу “Языки и методы программирования”

<b>Студент группы:</b> <ins>М80-108Б-22 Былькова Кристина Алексеевна, № по списку 2</ins>

<b>Контакты e-mail:</b> <ins>kristina.bilckova@yandex.ru</ins>

<b>Работа выполнена:</b> «6» <ins>мая</ins> <ins>2023</ins> г.

<b>Преподаватель:</b> <ins>асп. каф. 806 Сахарин Никита Александрович</ins>

<b>Входной контроль знаний с оценкой:</b> <ins>5</ins>

<b>Отчет сдан</b> «6» <ins>мая</ins> <ins>2023</ins> г., <b>итоговая оценка</b>5<ins>

<b>Подпись преподавателя:</b> ___________


## 1. Тема
Линейные списки
## 2. Цель работы
Составить и отладить программу на языке Си для обработки линейного списа заданной организации с отображением списка на динамические структуры, содержащего узлы типа int. Навигацию по списку следует реализовать с применением итераторов.
## 3. Задание (вариант № 2)
- Тип элемента спика: 8 % 8 + 1 = 1 - целый
- Вид списка: (2 div 2) % 6 + 1 = 2 - линейный однонаправленный
- Нестандартное действие: 2 % 15 + 1 = 3 - удалить из списка все элементы, предшествующие и последующие заданному значению

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

1. listIteratorEnd - итератор последнего элемента 
2. listIteratorBegin - итератор первого элемента
3.listIterator Equal - проверка на равенство двух итераторов
4. listIteratorGet - возвращает значение по итератора
5. listIteratorSet - устанавливает значение по итератору
6. listIteratorNext - возвращает итератор следующего элемента 
7. listIteratorIs - возвращает итератор элемента 
8. listCreate - создание списка
9. listIsEmpty - проверка списка на пустоту
10. listSize - размер списка
11. listInsert - добавление нового элемента в список
12. listDelete - удаление элемента из списка
13. listPrint - печатать списка
14. listClear - очистка списка
15. listTask - процедура, выполняющая нестандартной действие по номеру варианта 


## 7. Сценарий выполнения работы [план работы, первоначальный текст программы в черновике (можно на отдельном листе) и тесты либо соображения по тестированию].

``` :src/cp8.c
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <errno.h>

struct ListNode {
    struct ListNode *next;
    int value;
};

typedef struct ListNode ListNode;

typedef struct {
    struct ListNode *head;
    int size;
} List;

typedef struct {
    struct ListNode *node;
} ListIterator;

ListIterator listIteratorEnd(List * const list) {
    ListIterator tmp = {list->head->next};
    return tmp;
}

ListIterator listIteratorBegin(List * const list) {
    ListIterator tmp = {list->head};
    return tmp;
}

bool listIteratorEqual(ListIterator * const first, ListIterator * const second) {
    return first->node == second->node;
}

int listIteratorGet(ListIterator * const i) {
    return i->node->value;
}

void listIteratorSet(const ListIterator *i, const int value) {
    i->node->value = value;
}

ListIterator *listIteratorNext(ListIterator * const i) {
    i->node = i->node->next;
    return i;
}

ListIterator listIteratorIs(List * const list, const int n) {
    ListIterator tmp = listIteratorBegin(list);
    for (int i = 0; i < n; i++) {
        listIteratorNext(&tmp);
    }
    return tmp;
}

void listCreate(List * const list) {
    list->head = malloc(sizeof(ListNode));
    list->head->next = list->head;
    list->size = 0;
}

bool listIsEmpty(List * const list) {
    return list->size == 0;
}

size_t listSize(List * const list) {
    return list->size;
}

void listInsert(List * const list, ListIterator * const i, const int value) {
    ListIterator tmp = {malloc(sizeof(ListNode))};
    tmp.node->value = value;
    tmp.node->next = i->node->next;
    i->node->next = tmp.node;
    list->size++;
}

ListIterator listDelete(List * const list, ListIterator * const i) {
    ListIterator tmp = listIteratorBegin(list);
    ListIterator next = {i->node->next};
    if (listIteratorEqual(&tmp, &next)) {
        return tmp;
    }
    tmp.node = i->node->next->next;
    ListNode *t = i->node->next;
    i->node->next = tmp.node;
    free(t);
    list->size--;
    return tmp;
}

void listPrint(List * const list) {
    if (list->head == NULL) {
        return;
    }
    ListIterator tmp = listIteratorBegin(list);
    for (ListIterator i = listIteratorEnd(list); !listIteratorEqual(&i, &tmp); listIteratorNext(&i)) {
        printf("%d ", listIteratorGet(&i));
    }
    printf("\n");
}

void listClear(List * const list) {
    ListNode *tmp = list->head->next;
    while (tmp != list->head) {
        ListNode *t = tmp;
        tmp = tmp->next;
        free(t);
    }
    free(list->head);
    list->head = 0;
    list->size = 0;
}

bool listTask(List * const list, int value) {
    ListIterator i = listIteratorEnd(list); 
    ListIterator tmp = listIteratorBegin(list); 
    bool f = false;
    while (!listIteratorEqual(&i, &tmp)) {
        if (i.node->value == value)  {
            f = true;
            break;
        }
        i = *listIteratorNext(&i);
    }
    if (f) {
        listClear(list);
        listCreate(list);
        ListIterator i = listIteratorIs(list, 0);
        listInsert(list, &i, value);
        return true;
    }
    return false;
}

int main() {
    List *list = malloc(sizeof(List));
    listCreate(list);
    ListIterator i = listIteratorBegin(list);
    int prev_index;
    int value = 5;
    listInsert(list, &i, value);
    //Добавление элементов
    prev_index = 1;
    value = 44;
    i = listIteratorIs(list, prev_index);
    listInsert(list, &i, value);
    prev_index = 2;
    value = 23;
    i = listIteratorIs(list, prev_index);
    listInsert(list, &i, value);
    prev_index = 3;
    value = 19;
    i = listIteratorIs(list, prev_index);
    listInsert(list, &i, value);
    prev_index = 4;
    value = 90;
    i = listIteratorIs(list, prev_index);
    listInsert(list, &i, value);
    prev_index = 5;
    value = 10;
    i = listIteratorIs(list, prev_index);
    listInsert(list, &i, value);
    listPrint(list);
    // Удаление элемента по номеру
    int num = 1;
    if (0 <= num && num < listSize(list)) {
        i = listIteratorIs(list, num);
        listDelete(list, &i);
    } else {
        printf("Element with %d number doesn't exists\n", num);
    }
    listPrint(list);
    // Задание
    /*
    Удалить из списка все элементы, предшествующие
    и последующие заданному значению.
    */
    listTask(list, 23);
    listPrint(list);
    
    return 0;
}
```

Пункты 1-7 отчета составляются сторого до начала лабораторной работы.
Допущен к выполнению работы.  
<b>Подпись преподавателя:</b> _____________________

## 8. Распечатка протокола 

```
kristinab@LAPTOP-SFU9B1F4:/mnt/c/Users/Admin/Projects/C$ gcc cp8.c && ./a.out
5 44 23 19 90 10
5 23 19 90 10
23
```

## 9. Дневник отладки должен содержать дату и время сеансов отладки и основные события (ошибки в сценарии и программе, нестандартные ситуации) и краткие комментарии к ним. В дневнике отладки приводятся сведения об использовании других ЭВМ, существенном участии преподавателя и других лиц в написании и отладке программы.

| № |  Лаб. или дом. | Дата | Время | Событие | Действие по исправлению | Примечание |
| ------ | ------ | ------ | ------ | ------ | ------ | ------ |
| 1 | дом. | 06.05.23 | 13:00 | Выполнение лабораторной работы | - | - |

## 10. Замечания автора по существу работы

<b>div2</b>

- [Задача во время контеста](https://mai2022.contest.codeforces.com/group/Ej1bTQMkro/contest/427393/submission/201028473)
- [Задача во время контеста](https://mai2022.contest.codeforces.com/group/Ej1bTQMkro/contest/427393/submission/201038743)
- [Дорешка](https://mai2022.contest.codeforces.com/group/Ej1bTQMkro/contest/427393/submission/204335653)


## 11. Выводы
Была составлена программа на языке Си для обработки линейного списка заданной организации с отображением на динамические структуры и написана процедура для выполнения нестандартного действия по номеру варианта. Была изучена навигация по списку с применением итераторов. Были приобретены навыки, которые будут полезны для выполнения других лабораторных работ и курсовых проектов.

Недочёты при выполнении задания могут быть устранены следующим образом: —

<b>Подпись студента:</b> _________________


