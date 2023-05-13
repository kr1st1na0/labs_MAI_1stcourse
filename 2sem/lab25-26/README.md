# Отчёт по лабораторным работам №25-26 по курсу “Языки и методы программирования”

<b>Студент группы:</b> <ins>М80-108Б-22 Былькова Кристина Алексеевна, № по списку 2</ins>

<b>Контакты e-mail:</b> <ins>kristina.bilckova@yandex.ru</ins>

<b>Работа выполнена:</b> «1» («8») <ins>апреля</ins> <ins>2023</ins> г.

<b>Преподаватель:</b> <ins>асп. каф. 806 Сахарин Никита Александрович</ins>

<b>Входной контроль знаний с оценкой:</b> <ins>5</ins>

<b>Отчет сдан</b> «1» («8») <ins>апреля</ins> <ins>2023</ins> г., <b>итоговая оценка</b>5<ins>

<b>Подпись преподавателя:</b> ___________


## 1. Тема
Автоматизация сборки программ модульной структуры на языке Си с использованием утилиты make. Абстрактные типы данных. Рекурсия. Модульное программирование на языке Си.
## 2. Цель работы
Составить и отладить модуль определений и модуль реализации по заданной схее модуля определений для абстрактного (пользовательского) типа данных (стека, очереди, списка или дека, в зависимости от варианта задания). Составить программный модуль, сортирующий экземляр указанного абстрактного типа данных заданным методом, используя только операции, импортированные из модуля UUDT. Использовать утилиту make.
## 3. Задание (вариант № 2)
Номер процедуры и метода: (2 + 1) % 6 + 1 = 4

Тип данных: (2 + 1) % 4 + 1 = 4 - линейный список

Процедура: поиск в списке двух элементов, идущих подряд, первый из которых больше второго. Если такие 
элементы найдены, их перестановка.

Метод: сортировка методом пузырька.

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

1. pushBack - добавляет новый элемент в конец списка
2. pushFront - добавляет новый элемент в начало списка
3. popBack - удаляет последний элемент
4. popFront - удаляет первый элемент
5. Erase - удаляет элемент по его значению
6. Destroy - полностью удаляет список
7. Clear - затирает список
8. listSize - печатает размер списка
9. bubbleSort - сортировка пузырьком
10. isEmpty - проверяет, пуст ли список
11. printList - печатает список

7. Procedure - меняет местами два элемента, если первый больше второго

<b>Lab26</b>
``` :src/lab26.c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>
#include <errno.h>

#define MAX_SIZE (100U)

typedef struct {
    int value;
    ptrdiff_t prev;
    ptrdiff_t next;
} Node;

typedef struct {
	Node *data;
    ptrdiff_t head;
    ptrdiff_t tail;
    size_t size;
} List;

bool create(List * const list) {
    Node * const ptr = malloc(MAX_SIZE * sizeof(Node));
    if (ptr == NULL)
        return false;
    list->data = ptr;
    list->head = list->tail = -1;
    list->size = 0;
    return true;
}

void clear(List * const list) {
    list->head = list->tail = -1;
    list->size = 0;
}

void destroy(List * const list) {
    free(list->data);
}

void unlink(List * const list, const ptrdiff_t index) {
    Node * const node = list->data + index;
    if (list->head == index)
        list->head = node->next;
    else
        list->data[node->prev].next = node->next;
    if (list->tail == index)
        list->tail = node->prev;
    else
        list->data[node->next].prev = node->prev;
    --list->size;
}

// Delete the node
bool erase(List * const list, int value) {
    for (ptrdiff_t index = list->head; index != -1; index = list->data[index].next)
        if (list->data[index].value == value) {
            unlink(list, index);
            return true;
        }
    return false;
}

bool back(const List * const list, int * const value) {
    if (list->size == 0)
        return false;
    *value = list->data[list->tail].value;
    return true;
}

bool front(const List * const list, int * const value) {
	  if (list->size == 0)
        return false;
    *value = list->data[list->head].value;
    return true;
}

// Add a new node in the end of the list
bool pushBack(List * const list, int value) {
    if (list->size == MAX_SIZE)
        return false;
    const ptrdiff_t index = list->size;
    list->data[index].value = value;
    list->data[index].prev = list->tail;
    list->data[index].next = -1;
    if (list->size == 0) {
        list->head = index;
        list->tail = index;
    } else {
        list->data[list->tail].next = index;
        list->tail = index;
    }
    ++list->size;
    return true;
}

bool pushFront(List * const list, int value) {
    if (list->size == MAX_SIZE)
        return false;
    const ptrdiff_t index = list->size;
    list->data[index].value = value;
    list->data[index].prev = -1;
    list->data[index].next = list->head;
    if (list->size == 0) {
        list->head = index;
        list->tail = index;
    } else {
        list->data[list->head].prev = index;
        list->head = index;
    }
    ++list->size;
    return true;
}

bool popBack(List * const list) {
    if (list->size == 0)
        return false;
    unlink(list, list->tail);
    return true;
}

bool popFront(List * const list) {
    if (list->size == 0)
        return false;
    unlink(list, list->head);
    return true;
}

// Print the list
void printList(const List * const list) {
    for (ptrdiff_t index = list->head; index != -1; index = list->data[index].next)
        if (list->data[index].next != -1)
            printf("%d <-> ", list->data[index].value);
        else
            printf("%d", list->data[index].value);
}

// Check if list is empty
bool isEmpty(const List * const list) {
    return list->size == 0;
}

size_t listSize(const List * const list) {
    return list->size;
}

void swap(List * const first, List * const second) {
    List tmp = *first;
    *first = *second;
    *second = tmp;
}

// Swaps 2 elements if the first is greater than the second one
bool procedure(List * const list, List * const tmp) {
    bool flag = false;
    while (!isEmpty(list)) {
        int first, second;
        front(list, &second);
        popFront(list);
        if (back(tmp, &first) && second < first) {
            popBack(tmp);
            pushBack(tmp, second);
            pushBack(tmp, first);
            flag = true;
        } else
            pushBack(tmp, second);
    }
    swap(list, tmp);
    return flag;
}

bool bubbleSort(List * const list) {
    List result, tmp;
    if (!create(&result))
        return false;
    if (!create(&tmp)) {
        destroy(&result);
        return false;
    }
    while (procedure(list, &tmp)) {
        int value;
        back(list, &value);
        popBack(list);
        pushFront(&result, value);
    }
    while (!isEmpty(&result)) {
        int value;
        front(&result, &value);
        popFront(&result);
        pushBack(list, value);
    }
    destroy(&tmp);
    destroy(&result);
    return true;
}

int main() {
    printf("Doubly linked list\n-\n");
    List list;
    create(&list);
    // Empty
    int temp = 0;
    printf("Enter '1' if you want ot check if list empty or enter any another number: ");
    scanf("%d", &temp);
    if (temp == 1) {
        bool empty = isEmpty(&list);
        if (empty) {
            printf("The list is empty\n");
        }
        else {
            printf("The list is not empty\n");
        }
    }

    // List generation
    int value, n;
    printf("Enter the size: ");
    scanf("%d", &n);
    while (n > 0) {
        printf("Enter the node value: ");
        scanf("%d", &value);
        pushBack(&list, value);
        n -= 1;
    }
    printf("Your list: ");
    printList(&list);
    int number, t = 1;
    printf("\n1. pushBack;\n2. pushFront;\n3. popBack;\n4. popFront;\n5. Erase;\n6. Destroy;\n7. Clear;\n8. Size;\n9. bubbleSort;\n10. Check if the list is empty;\n11. Print list;\n0. Quit.\n-\n");
    while (t != 0) {
        printf("Enter the number: ");
        scanf("%d", &number);
        if (number == 1) {  
            printf("Enter the node value: ");
            scanf("%d", &value);
            pushBack(&list, value);
        }
        else if (number == 2) {
            printf("Enter the node value: ");
            scanf("%d", &value);
            pushFront(&list, value);
        }
        else if (number == 3) {
            popBack(&list);
        }
        else if (number == 4) {
            popFront(&list);
        }
        else if (number == 5) {
            printf("Enter the node value: ");
            scanf("%d", &value);
            erase(&list, value);
        }
        else if (number == 6) {
            destroy(&list);
        }
        else if (number == 7) {
            clear(&list);
        }
        else if (number == 8) {
            size_t size = listSize(&list);
            printf("List size = %zu\n", size);
        }
        else if (number == 9) {
            bubbleSort(&list);
            printf("Bubble Sort completed\n");
        }
        else if (number == 10) {
            bool empty = isEmpty(&list);
            if (empty) {
                printf("The list is empty\n");
            }
            else {
                printf("The list is not empty\n");
            }
        }
        else if (number == 11) {
            printList(&list);
            printf("\n");
        }
        else if (number == 0) {
            printf("Finished\n");
            t = 0;
        }
    }
    return 0;
}

```

## 7. Сценарий выполнения работы [план работы, первоначальный текст программы в черновике (можно на отдельном листе) и тесты либо соображения по тестированию].

<b>Lab25</b>

Makefile:
``` :src/makefile/Makefile
CC = gcc
CFLAGS = -g
OBJ = main.o list.o sort.o
PROG = program

build: main.o list.o sort.o
	$(CC) $(CFLAGS) -o $(PROG) $(OBJ)

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

list.o: list.c list.h
	$(CC) $(CFLAGS) -c list.c

sort.o: sort.c sort.h
	$(CC) $(CFLAGS) -c sort.c

clean: 
	rm $(PROG)
```

main.c:
``` :src/makefile/main.c
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

#include "list.h"

int main() {
    node* root = NULL;
    printf("Doubly linked list\n-\n");

    // Empty
    int temp = 0;
    printf("Enter '1' if you want ot check if list empty or enter any another number: ");
    scanf("%d", &temp);
    if (temp == 1) {
        bool empty = ListIsEmpty(root);
        if (empty) {
            printf("The list is empty\n");
        }
        else {
            printf("The list is not empty\n");
        }
    }

    // List generation
    printf("Enter the size: ");
    int n, r, x;
    scanf("%d", &n);
    printf("Enter the root value: ");
    scanf("%d", &r);
    root = ListInit(r);
    while (n - 1 > 0) {
        printf("Enter the node value: ");
        scanf("%d", &x);
        Add(root, x);
        n -= 1;
    }
    printf("Your list: ");
    PrintList(root);

    // List modul
    int number, value, t = 1;
    printf("\n1. Add;\n2. Delete node;\n3. Bubble Sort;\n4. Print List;\n5. Check if list is empty;\n0. Quit.\n-\n");
    while (t != 0) {
        printf("Enter the number: ");
        scanf("%d", &number);
        if (number == 1) {  
            printf("Enter the node value: ");
            scanf("%d", &value);
            if (root == NULL) {
                printf("ERROR\nList is empty\n");
            } 
            else {
                Add(root, value);
            }
        }
        else if (number == 2) {
            printf("Enter the node value: ");
            scanf("%d", &value);
            if (root == NULL) {
                printf("ERROR\nTree is empty\n");
            } 
            else if (value == r) {
                printf("ERROR\nYou are trying to delete the root\n");
            }
            else {
                Delete(root, value);
            }
        }
        else if (number == 3) {
            int count = ListSize(root);
            int mas[count];
            ListToArray(root, mas, count);
            BubbleSort(mas, count);
            ArrayToList(root, mas, count);
            printf("Bubble Sort completed\n");
        }
        else if (number == 4) {
            PrintList(root);
            printf("\n");
        }
        else if (number == 5) {
            bool empty = ListIsEmpty(root);
            if (empty) {
                printf("The list is empty\n");
            }
            else {
                printf("The list is not empty\n");
            }
        }
        else if (number == 0) {
            printf("Finished\n");
            t = 0;
        }
    }
    return 0;
}
```


list.h:
``` :src/makefile/list.h
#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

typedef struct list {
    int value;
    struct list *next;
    struct list *prev;
} node;

node* ListInit(int value);

node* Add(node* root, int value);

node* Delete(node* root, int value);

void PrintList(node* root);

bool ListIsEmpty(node* root);

int ListSize(node* root);

void ListToArray(node *root, int *mas, int count);

void ArrayToList(node *root, int *mas, int count);

#endif // LIST_H
```

list.c:
``` :src/makefile/list.c
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

#include "list.h"

//Init the root
node* ListInit(int value) {
    node* root = (node*) malloc(sizeof(node));
    root->value = value;
    root->next = NULL;
    root->prev = NULL;
    return root;
}

//Add a new node in the end of the list
node* Add(node* root, int value) {
    node* temp;
    temp = (node*) malloc(sizeof(node)); 
    while (root->next != NULL) {
        root = root->next;
    }
    root->next = temp;
    temp->value = value;
    temp->prev = root;
    temp->next = NULL;
    return temp;
}

//Delete the node
node* Delete(node* root, int value) {
    node* item;
    node* temp;
    temp = root;
    if (temp->value == value) {
        temp = temp->next;
    }
    while (temp->next->value != value) {
        temp = temp->next;
    }
    item = temp->next;
    if (item->next == NULL) {
        temp->next = NULL;
    } else {
        temp->next = item->next;
        item->next->prev = temp;
    }
    free(item);
    return temp;
}

// Print the list
void PrintList(node* root) {
    node* p;
    p = root;
    while (p != NULL) {
        if (p->next != NULL) {
            printf("%d <-> ", p->value);
        } else {
            printf("%d", p->value);
        }
        p = p->next;
    }
}

// Check if list is empty
bool ListIsEmpty(node* root) {
    bool flag = false;
    if (root == NULL) {
        flag = true;
    }
    return flag;
}

// Number of nodes
int ListSize(node* root) {
    node* temp = root;
    int count = 1;
    while (temp->next != NULL) {
        count += 1;
        temp = temp->next;
    }
    return count;
}

//List to mas
void ListToArray(node *root, int *mas, int count) {
    for (int i = 0; i < count; ++i) {
        mas[i] = root->value;
        root = root->next;
    }
}

// Mas to list
void ArrayToList(node *root, int *mas, int count) {
    for (int i = 0; i < count; ++i) {
        root->value = mas[i];
        root = root->next;
    }
}
```

sort.h:
``` :src/makefile/sort.h
#ifndef SORT_H
#define SORT_H

#include "list.h"

void BubbleSort(int *mas, int count);

#endif // SORT_H
```

sort.c:
```
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

#include "list.h"

// Bubble Sort
void BubbleSort(int *mas, int count) {
    for (int i = 0; i < count - 1; ++i)  {
        for (int j = 0; j < count - i - 1; ++j) {
            if (mas[j] > mas[j + 1]) {
                int temp = mas[j];
                mas[j] = mas[j + 1];
                mas[j + 1] = temp;
            }
        }
    }
}
```

Пункты 1-7 отчета составляются сторого до начала лабораторной работы.
Допущен к выполнению работы.  
<b>Подпись преподавателя:</b> _____________________

## 8. Распечатка протокола 

<b>Lab26</b>
```
kristinab@LAPTOP-SFU9B1F4:/mnt/c/Users/Admin/Projects/C$ gcc lab26.c && ./a.out
Doubly linked list
-
Enter '1' if you want ot check if list empty or enter any another number: 1
The list is empty
Enter the size: 5
Enter the node value: 34
Enter the node value: 23
Enter the node value: 78
Enter the node value: 5
Enter the node value: 19
Your list: 34 <-> 23 <-> 78 <-> 5 <-> 19
1. pushBack;
2. pushFront;
3. popBack;
4. popFront;
5. Erase;
6. Destroy;
7. Clear;
8. Size;
9. bubbleSort;
10. Check if the list is empty;
11. Print list;
0. Quit.
-
Enter the number: 1
Enter the node value: 45
Enter the number: 11
34 <-> 23 <-> 78 <-> 5 <-> 19 <-> 45
Enter the number: 2
Enter the node value: 44
Enter the number: 11
44 <-> 34 <-> 23 <-> 78 <-> 5 <-> 19 <-> 45
Enter the number: 3
Enter the number: 11
44 <-> 34 <-> 23 <-> 78 <-> 5 <-> 19
Enter the number: 4
Enter the number: 11
34 <-> 23 <-> 78 <-> 5 <-> 19
Enter the number: 8
List size = 5
Enter the number: 10
The list is not empty
Enter the number: 9
Bubble Sort completed
Enter the number: 11
5 <-> 19 <-> 23 <-> 34 <-> 78
Enter the number: 7
Enter the number: 11

Enter the number: 6
Enter the number: 0
Finished
```

## 9. Дневник отладки должен содержать дату и время сеансов отладки и основные события (ошибки в сценарии и программе, нестандартные ситуации) и краткие комментарии к ним. В дневнике отладки приводятся сведения об использовании других ЭВМ, существенном участии преподавателя и других лиц в написании и отладке программы.

| № |  Лаб. или дом. | Дата | Время | Событие | Действие по исправлению | Примечание |
| ------ | ------ | ------ | ------ | ------ | ------ | ------ |
| 1 | дом. | 01.04.23 (08.04.23) | 13:00 | Выполнение лабораторной работы | - | - |

## 10. Замечания автора по существу работы

<b>Lab25</b>
<b>div2</b>

- [Задача во время контеста](https://codeforces.com/contest/1806/submission/197937695)
- [Дорешка](https://codeforces.com/contest/1806/submission/201235902)

<b>Lab26</b>
<b>div2</b>

- [Задача во время контеста](https://mai2022.contest.codeforces.com/group/Ej1bTQMkro/contest/427392/submission/199844869)
- [Задача во время контеста](https://mai2022.contest.codeforces.com/group/Ej1bTQMkro/contest/427392/submission/199849376)
- [Дорешка](https://mai2022.contest.codeforces.com/group/Ej1bTQMkro/contest/427392/submission/200951114)
- [Дорешка](https://mai2022.contest.codeforces.com/group/Ej1bTQMkro/contest/427392/submission/200950991)


## 11. Выводы
Были изучены различные абстрактные типы данных. Был составлен программный модуль, сортирующий экземпляр указанного типа данных заданным методом на языке Си. Также была изучена утилита make. В результате выполнения работы, были приобретены навыки, которые будут полезны для выполнения других лабораторных работ и курсовых проектов.

Недочёты при выполнении задания могут быть устранены следующим образом: —

<b>Подпись студента:</b> _________________


