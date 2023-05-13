// Сортировка: линейный выбор с подсчетом
// Бинарный поиск строки по ключу

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_STRING_SIZE 100
#define MAX_TEXT_SIZE 100

typedef struct {
    char value[3]; // 28
    int data;
} key;

typedef struct {
    key k;
    char str[MAX_STRING_SIZE];
} line;

int strLess(char first[3], char second[3]) {
    for (int i = 0; i < 3; i++) {
        if (first[i] > second[i]) {
            return false;
        }
    }
    return true;
}

bool keyLess(key first, key second) {
    return (strLess(first.value, second.value)) && (first.data < second.data);
}

int strOver(char first[3], char second[3]) {
    for (int i = 0; i < 3; i++) {
        if (first[i] < second[i]) {
            return false;
        }
    }
    return true;
}

bool keyOver(key first, key second) {
    return (strOver(first.value, second.value)) && (first.data > second.data);
}

void binarySearch(line * l, int size, key k) {
    int mid, left = 0, right = size - 1;
    while (left <= right) {
        mid = (left + right) / 2;
        if (keyLess(l[mid].k, k)) {
            left = mid + 1;
        }
        else if (keyOver(l[mid].k, k)) {
            right = mid - 1;
        }
        else {
            printf("%c%c%c %d\t %s", l[mid].k.value[0], l[mid].k.value[1], l[mid].k.value[2], l[mid].k.data, l[mid].str);
            break;
        }
    }
}

void tableSort(line * l, int size) {
    int *count = malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) {
        count[i] = 0;
    }
    for (int i = 0; i < size - 1; i++) {
        for(int j = i + 1; j < size; j++) {
            if (l[i].k.data < l[j].k.data)
                ++count[j];
            else
                ++count[i];
        }
    }
    line tmpline;
    int tmp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (count[i] > count[j]) {
                tmp = count[i];
                count[i] = count[j];
                count[j] = tmp;

                tmpline = l[i];
                l[i] = l[j];
                l[j] = tmpline;
            }
        }
    }
    free(count);
}

void tablePrint(line * l, int size) {
    printf("Key\t String\n");
    for (int i = 0; i < size; i++) {
        if (l[i].k.data != 0)
            printf("%c%c%c %d\t %s", l[i].k.value[0], l[i].k.value[1], l[i].k.value[2], l[i].k.data, l[i].str);
    }
}

// gcc cp9.c && ./a.out <name>.txt

int main(int argc, char *argv[]) {
    key k1, k2;
    FILE *f;
    // char file_name[] = "test1.txt";
    // char file_name[] = "test2.txt";
    // char file_name[] = "test3.txt";
    line l[MAX_TEXT_SIZE];
    int size = 0;
    if ((f = fopen(argv[1], "r")) == NULL) {
        printf("Can not open file\n");
        return 0;
    }
    while (!feof(f)) {
        fscanf(f, "%s\t%d\t", l[size].k.value, &l[size].k.data);
        fgets(l[size].str, MAX_STRING_SIZE, f);
        ++size;
    }
    
    bool tmp = true;
    int a;
    while (tmp) {
        printf("---------\n1. Print table;\n2. Sort;\n3. Binary search;\n4. Exit.\nEnter the number: ");
        scanf("%d", &a);
        printf("-\n");
        if (a == 1) {
            printf("Table:\n");
            tablePrint(l, size);
        }
        else if (a == 2) {
            printf("Sorted:\n");
            tableSort(l, size);
            tablePrint(l, size);
        }
        else if (a == 3) {
            printf("Enter key: ");
            scanf("%s %d", k1.value, &k1.data);
            binarySearch(l, size, k1);
        }
        else if (a == 4) {
            tmp = false;
            printf("Exit\n");
        }
        else {
            printf("Wrong number. Try again.\n");
        }
    }
    fclose(f);
    return 0;
}