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