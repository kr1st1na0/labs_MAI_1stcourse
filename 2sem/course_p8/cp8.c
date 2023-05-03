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