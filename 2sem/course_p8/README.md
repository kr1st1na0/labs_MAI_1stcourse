# Отчёт по курсовой работе №8 по курсу “Языки и методы программирования”

<b>Студент группы:</b> <ins>М80-108Б-22 Былькова Кристина Алексеевна, № по списку 2</ins>

<b>Контакты e-mail:</b> <ins>kristina.bilckova@yandex.ru</ins>

<b>Работа выполнена:</b> «6» <ins>мая</ins> <ins>2023</ins> г.

<b>Преподаватель:</b> <ins>асп. каф. 806 Сахарин Никита Александрович</ins>

<b>Входной контроль знаний с оценкой:</b> <ins>-</ins>

<b>Отчет сдан</b> «6» <ins>мая</ins> <ins>2023</ins> г., <b>итоговая оценка</b>-<ins>

<b>Подпись преподавателя:</b> ___________


## 1. Тема
Линейные списки
## 2. Цель работы
Составить и отладить программу на языке Си для обработки линейного списа заданной организации с отображением списка на динамические структуры, содержащего узлы типа int.
## 3. Задание (вариант № 3)
Нестандартное действие: 2 % 15 + 1 = 3

Удалить из списка все элементы, предшествующие и последующие заданному значению.

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

1. listCreate - создание списка
2. listClear - очистка списка
3. listPushBack - добавление нового элемента в конец списка
4. listPushFront - добавление нового элемента в начало списка
5. listPopBack - удаление последнего элемента
6. listPopFront - удаление первого элемента
7. listSize - размер списка
8. listIsEmpty - проверка списка на пустоту
9. listPrint - печатать списка
10. listTask - процедура, выполняющая нестандартной действие по номеру варианта 


## 7. Сценарий выполнения работы [план работы, первоначальный текст программы в черновике (можно на отдельном листе) и тесты либо соображения по тестированию].

```
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <errno.h>

struct ListNode {
    struct ListNode *next;
    struct ListNode *prev;
    int value;
};

typedef struct ListNode ListNode;

typedef struct {
    ListNode *head;
    ListNode *tail;
    size_t size;
} List;

List* listCreate() {
    List *tmp = (List*) malloc(sizeof(List));
    tmp->size = 0;
    tmp->head = tmp->tail = NULL;
    return tmp;
}

void listClear(List * const list) {
    ListNode *node = list->head;
    ListNode *tmp = NULL;
    while (node) {
        tmp = node->next;
        free(node);
        node = tmp;
    }
    list->head = list->tail = NULL;
    list->size = 0;
}

int listPushBack(List * const list, int value) {
    ListNode *tmp = (ListNode*) malloc(sizeof(ListNode));
    if (tmp == NULL) {
        return errno;
    }
    tmp->value = value;
    tmp->next = NULL;
    tmp->prev = list->tail;
    if (list->tail) {
        list->tail->next = tmp;
    }
    list->tail = tmp;
 
    if (list->head == NULL) {
        list->head = tmp;
    }
    list->size++;
}

int listPushFront(List * const list, int value) {
    ListNode *tmp = (ListNode*) malloc(sizeof(ListNode));
    if (tmp == NULL) {
        return errno;
    }
    tmp->value = value;
    tmp->next = list->head;
    tmp->prev = NULL;
    if (list->head) {
        list->head->prev = tmp;
    }
    list->head = tmp;
 
    if (list->tail == NULL) {
        list->tail = tmp;
    }
    list->size++;
}

int listPopBack(List * const list) {
    if (list->size == 0)
        return EINVAL;
    ListNode * const node = list->tail;
    list->tail = list->tail->prev;
    free(node);
    if (list->tail == NULL)
        list->head = NULL;
    else
        list->tail->next = NULL;
    --list->size;
    return 0;
}

int listPopFront(List * const list) {
    if (list->size == 0)
        return EINVAL;
    ListNode * const node = list->head;
    list->head = list->head->next;
    free(node);
    if (list->head == NULL)
        list->tail = NULL;
    else
        list->head->prev = NULL;
    --list->size;
    return 0;
}

size_t listSize(List * const list) {
    return list->size;
}

bool listIsEmpty(List * const list) {
    return list->size == 0;
}

void listPrint(List * const list) {
    ListNode *tmp = list->head;
    while (tmp != NULL) {
        if (tmp->next != NULL) {
            printf("%d <-> ", tmp->value);
        }
        else {
            printf("%d", tmp->value);
        }
        tmp = tmp->next;
    }
    printf("\n");
}

void listTask(List * const list, int value) {
    ListNode *tmp = list->head;
    bool f = false;
    while (tmp != NULL) {
        if (tmp->value == value) {
            f = true;
            break;
        }
        tmp = tmp->next;
    }
    if (f) {
        listClear(list);
        listPushFront(list, value);
    }
    else {
        printf("This element is not in the list\n");
    }
}

int main() {
    List *list = listCreate();
    listPushBack(list, 5);
    listPushBack(list, 7);
    listPushBack(list, 10);
    listPrint(list);
    if (listIsEmpty(list)) printf("The list is empty\n");
    else printf("The list is not empty\n");
    printf("Size of the list = %ld\n_\n", listSize(list));

    listClear(list);
    if (listIsEmpty(list)) printf("The list is empty\n_\n");
    else printf("The list is not empty\n_\n");

    listPushBack(list, 5);
    listPushBack(list, 7);
    listPushBack(list, 10);
    listPushFront(list, 8);
    listPushBack(list, 90);
    listPushBack(list, 45);
    listPrint(list);
    printf("Size of the list = %ld\n_\n", listSize(list));

    listPopBack(list);
    listPrint(list);
    printf("Size of the list = %ld\n_\n", listSize(list));
    
    listPopFront(list);
    listPrint(list);
    printf("Size of the list = %ld\n_\n", listSize(list));

    listPushBack(list, 100);
    listPushBack(list, 6);
    listPushBack(list, 23);
    listPushFront(list, 44);
    listPrint(list);
    printf("Size of the list = %ld\n", listSize(list));

    /*
    Удалить из списка все элементы, предшествующие
    и последующие заданному значению.
    */
    int x;
    printf("_\nTASK:\nEnter the value: ");
    scanf("%d", &x);
    listTask(list, x);
    listPrint(list);
    printf("Size of the list = %ld\n", listSize(list));
    printf("_\n");
    listPushBack(list, 1);
    listPushBack(list, 2);
    listPushFront(list, 3);
    listPrint(list);
    printf("Size of the list = %ld\n", listSize(list));
    return 0;
}
```

Пункты 1-7 отчета составляются сторого до начала лабораторной работы.
Допущен к выполнению работы.  
<b>Подпись преподавателя:</b> _____________________

## 8. Распечатка протокола 

```
kristinab@LAPTOP-SFU9B1F4:/mnt/c/Users/Admin/Projects/C$ gcc cp8-1.c && ./a.out
5 <-> 7 <-> 10
The list is not empty
Size of the list = 3
_
The list is empty
_
8 <-> 5 <-> 7 <-> 10 <-> 90 <-> 45
Size of the list = 6
_
8 <-> 5 <-> 7 <-> 10 <-> 90
Size of the list = 5
_
5 <-> 7 <-> 10 <-> 90
Size of the list = 4
_
44 <-> 5 <-> 7 <-> 10 <-> 90 <-> 100 <-> 6 <-> 23
Size of the list = 8
_
TASK:
Enter the value: 100
100
Size of the list = 1
_
3 <-> 100 <-> 1 <-> 2
Size of the list = 4
kristinab@LAPTOP-SFU9B1F4:/mnt/c/Users/Admin/Projects/C$ gcc cp8-1.c && ./a.out
5 <-> 7 <-> 10
The list is not empty
Size of the list = 3
_
The list is empty
_
8 <-> 5 <-> 7 <-> 10 <-> 90 <-> 45
Size of the list = 6
_
8 <-> 5 <-> 7 <-> 10 <-> 90
Size of the list = 5
_
5 <-> 7 <-> 10 <-> 90
Size of the list = 4
_
44 <-> 5 <-> 7 <-> 10 <-> 90 <-> 100 <-> 6 <-> 23
Size of the list = 8
_
TASK:
Enter the value: 55
This element is not in the list
44 <-> 5 <-> 7 <-> 10 <-> 90 <-> 100 <-> 6 <-> 23
Size of the list = 8
_
3 <-> 44 <-> 5 <-> 7 <-> 10 <-> 90 <-> 100 <-> 6 <-> 23 <-> 1 <-> 2
Size of the list = 11
kristinab@LAPTOP-SFU9B1F4:/mnt/c/Users/Admin/Projects/C$ gcc cp8-1.c && ./a.out
5 <-> 7 <-> 10
The list is not empty
Size of the list = 3
_
The list is empty
_
8 <-> 5 <-> 7 <-> 10 <-> 90 <-> 45
Size of the list = 6
_
8 <-> 5 <-> 7 <-> 10 <-> 90
Size of the list = 5
_
5 <-> 7 <-> 10 <-> 90
Size of the list = 4
_
44 <-> 5 <-> 7 <-> 10 <-> 90 <-> 100 <-> 6 <-> 23
Size of the list = 8
_
TASK:
Enter the value: 44
44
Size of the list = 1
_
3 <-> 44 <-> 1 <-> 2
Size of the list = 4
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
Была составлена программа на языке Си для обработки линейного списка заданной организации с отображением на динамические структуры и написана процедура для выполнения нестандартного действия по номеру варианта. Были приобретены навыки, которые будут полезны для выполнения других лабораторных работ и курсовых проектов.

Недочёты при выполнении задания могут быть устранены следующим образом: —

<b>Подпись студента:</b> _________________


