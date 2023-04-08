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
