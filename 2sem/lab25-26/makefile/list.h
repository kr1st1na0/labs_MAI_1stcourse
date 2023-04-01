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