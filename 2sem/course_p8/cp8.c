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