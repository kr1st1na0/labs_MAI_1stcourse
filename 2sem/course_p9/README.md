# Отчёт по курсовой работе №9 по курсу “Языки и методы программирования”

<b>Студент группы:</b> <ins>М80-108Б-22 Былькова Кристина Алексеевна, № по списку 2</ins>

<b>Контакты e-mail:</b> <ins>kristina.bilckova@yandex.ru</ins>

<b>Работа выполнена:</b> «13» <ins>мая</ins> <ins>2023</ins> г.

<b>Преподаватель:</b> <ins>асп. каф. 806 Сахарин Никита Александрович</ins>

<b>Входной контроль знаний с оценкой:</b> <ins>5</ins>

<b>Отчет сдан</b> «13» <ins>мая</ins> <ins>2023</ins> г., <b>итоговая оценка</b>5<ins>

<b>Подпись преподавателя:</b> ___________


## 1. Тема
Сортировка и поиск
## 2. Цель работы
Составить программу на языке Си с использованием процедур и функций для сортировки таблицы заданным методом и двоичного поиска по ключу в таблице.
## 3. Задание (вариант № 3)
- Номер метода сортировки: ((2 - 1) % 15) + 1 = 2 - линейный выбор с подсчетом
- Номер структуры табоицы: ((2 + 5) % 9) + 1 = 8:
1. тип ключа - комбинированный (строка + целое)
2. длина ключа в байтах - 32 (сделано для 7 байт)
3. хранение данных и ключей - вместе
4. минимальное число элементов таблицы - 18

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

Ввод каждого файла с тестами осуществляется в командой строке.

1. strLess - проверяет, меньше ли строка first, чем second
2. keyLess - проверяет, меньше ли ключ first, чем second
3. strOver - проверяет, больше ли строка first, чем second
4. keyOver - проверяет, больше ли ключ first, чем second
5. binarySearch - бинарный поиск по ключу в таблице
6. tableSort - сортирока таблицы указанным методом
7. tablePrint - печать таблицы

## 7. Сценарий выполнения работы [план работы, первоначальный текст программы в черновике (можно на отдельном листе) и тесты либо соображения по тестированию].

```
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
```

Пункты 1-7 отчета составляются сторого до начала лабораторной работы.
Допущен к выполнению работы.  
<b>Подпись преподавателя:</b> _____________________

## 8. Распечатка протокола 

```
kristinab@LAPTOP-SFU9B1F4:/mnt/c/Users/Admin/Projects/C/cp9$ gcc cp9.c && ./a.out test1.txt
---------
1. Print table;
2. Sort;
3. Binary search;
4. Exit.
Enter the number: 1
-
Table:
Key      String
aaa 1    J'suis pas tout seul à être tout seul
aaa 5    Ça fait d'jà ça d'moins dans la tête
aac 20   Et si j'comptais combien on est
aac 34   Beaucoup
aae 36   Tout ce à quoi j'ai d'jà pensé
aaf 47   Dire que plein d'autres y ont d'jà pensé
aag 55   Mais, malgré tout, je m'sens tout seul
aah 61   Du coup
aaj 68   J'ai parfois eu des pensées suicidaires
aax 73   Et j'en suis peu fier
aay 85   On croit parfois que c'est la seule manière de les faire taire
aaz 99   Ces pensées qui nous font vivre un enfer
---------
1. Print table;
2. Sort;
3. Binary search;
4. Exit.
Enter the number: 2
-
Sorted:
Key      String
aaa 1    J'suis pas tout seul à être tout seul
aaa 5    Ça fait d'jà ça d'moins dans la tête
aac 20   Et si j'comptais combien on est
aac 34   Beaucoup
aae 36   Tout ce à quoi j'ai d'jà pensé
aaf 47   Dire que plein d'autres y ont d'jà pensé
aag 55   Mais, malgré tout, je m'sens tout seul
aah 61   Du coup
aaj 68   J'ai parfois eu des pensées suicidaires
aax 73   Et j'en suis peu fier
aay 85   On croit parfois que c'est la seule manière de les faire taire
aaz 99   Ces pensées qui nous font vivre un enfer
---------
1. Print table;
2. Sort;
3. Binary search;
4. Exit.
Enter the number: 3
-
Enter key: aax 73
aax 73   Et j'en suis peu fier
---------
1. Print table;
2. Sort;
3. Binary search;
4. Exit.
Enter the number: 3
-
Enter key: aag 55
aag 55   Mais, malgré tout, je m'sens tout seul
---------
1. Print table;
2. Sort;
3. Binary search;
4. Exit.
Enter the number: 3
-
Enter key: aaz 99
aaz 99   Ces pensées qui nous font vivre un enfer
---------
1. Print table;
2. Sort;
3. Binary search;
4. Exit.
Enter the number: 5
-
Wrong number. Try again.
---------
1. Print table;
2. Sort;
3. Binary search;
4. Exit.
Enter the number: 4
-
Exit
kristinab@LAPTOP-SFU9B1F4:/mnt/c/Users/Admin/Projects/C/cp9$ gcc cp9.c && ./a.out test2.txt
---------
1. Print table;
2. Sort;
3. Binary search;
4. Exit.
Enter the number: 1
-
Table:
Key      String
aaz 99   Ces pensées qui nous font vivre un enfer
aay 85   On croit parfois que c'est la seule manière de les faire taire
aax 73   Et j'en suis peu fier
aaj 68   J'ai parfois eu des pensées suicidaires
aah 61   Du coup
aag 55   Mais, malgré tout, je m'sens tout
aaf 47   Dire que plein d'autres y ont d'jà pensé
aae 36   Tout ce à quoi j'ai d'jà pensé
aac 34   Beaucoup
aac 20   Et si j'comptais combien on est
aaa 5    Ça fait d'jà ça d'moins dans la tête
aaa 1    J'suis pas tout seul à être tout seul
---------
1. Print table;
2. Sort;
3. Binary search;
4. Exit.
Enter the number: 2
-
Sorted:
Key      String
aaa 1    J'suis pas tout seul à être tout seul
aaa 5    Ça fait d'jà ça d'moins dans la tête
aac 20   Et si j'comptais combien on est
aac 34   Beaucoup
aae 36   Tout ce à quoi j'ai d'jà pensé
aaf 47   Dire que plein d'autres y ont d'jà pensé
aag 55   Mais, malgré tout, je m'sens tout
aah 61   Du coup
aaj 68   J'ai parfois eu des pensées suicidaires
aax 73   Et j'en suis peu fier
aay 85   On croit parfois que c'est la seule manière de les faire taire
aaz 99   Ces pensées qui nous font vivre un enfer
---------
1. Print table;
2. Sort;
3. Binary search;
4. Exit.
Enter the number: 4
-
Exit
kristinab@LAPTOP-SFU9B1F4:/mnt/c/Users/Admin/Projects/C/cp9$ gcc cp9.c && ./a.out test3.txt
---------
1. Print table;
2. Sort;
3. Binary search;
4. Exit.
Enter the number: 1
-
Table:
Key      String
aaj 68   J'ai parfois eu des pensées suicidaires
aac 20   Et si j'comptais combien on est
aaa 1    J'suis pas tout seul à être tout seul
aac 34   Beaucoup
aay 85   On croit parfois que c'est la seule manière de les faire taire
aaf 47   Dire que plein d'autres y ont d'jà pensé
aah 61   Du coup
aaa 5    Ça fait d'jà ça d'moins dans la tête
aaz 99   Ces pensées qui nous font vivre un enfer
aax 73   Et j'en suis peu fier
aag 55   Mais, malgré tout, je m'sens tout seul
aae 36   Tout ce à quoi j'ai d'jà pensé
---------
1. Print table;
2. Sort;
3. Binary search;
4. Exit.
Enter the number: 2
-
Sorted:
Key      String
aaa 1    J'suis pas tout seul à être tout seul
aaa 5    Ça fait d'jà ça d'moins dans la tête
aac 20   Et si j'comptais combien on est
aac 34   Beaucoup
aae 36   Tout ce à quoi j'ai d'jà pensé
aaf 47   Dire que plein d'autres y ont d'jà pensé
aag 55   Mais, malgré tout, je m'sens tout seul
aah 61   Du coup
aaj 68   J'ai parfois eu des pensées suicidaires
aax 73   Et j'en suis peu fier
aay 85   On croit parfois que c'est la seule manière de les faire taire
aaz 99   Ces pensées qui nous font vivre un enfer
---------
1. Print table;
2. Sort;
3. Binary search;
4. Exit.
Enter the number: 4
-
Exit
```

## 9. Дневник отладки должен содержать дату и время сеансов отладки и основные события (ошибки в сценарии и программе, нестандартные ситуации) и краткие комментарии к ним. В дневнике отладки приводятся сведения об использовании других ЭВМ, существенном участии преподавателя и других лиц в написании и отладке программы.

| № |  Лаб. или дом. | Дата | Время | Событие | Действие по исправлению | Примечание |
| ------ | ------ | ------ | ------ | ------ | ------ | ------ |
| 1 | дом. | 13.05.23 | 13:00 | Выполнение лабораторной работы | - | - |

## 10. Замечания автора по существу работы

<b>div2</b>

- [Задача во время контеста](https://mai2022.contest.codeforces.com/group/Ej1bTQMkro/contest/427395/submission/202845665)
- [Задача во время контеста](https://mai2022.contest.codeforces.com/group/Ej1bTQMkro/contest/427395/submission/202859563)


## 11. Выводы
Была составлена программа на языке Си с использованием процедур и функций для сортировки таблицы заданным методом и двоичного поиска по ключу в таблице. Были приобретены навыки, которые будут полезны для выполнения других лабораторных работ и курсовых проектов.

Недочёты при выполнении задания могут быть устранены следующим образом: —

<b>Подпись студента:</b> _________________


