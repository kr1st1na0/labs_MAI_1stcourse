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