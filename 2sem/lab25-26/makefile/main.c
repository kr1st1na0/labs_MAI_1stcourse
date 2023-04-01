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