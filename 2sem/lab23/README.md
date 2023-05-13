# Отчёт по лабораторной работе №23 по курсу “Языки и методы программирования”

<b>Студент группы:</b> <ins>М80-108Б-22 Былькова Кристина Алексеевна, № по списку 2</ins>

<b>Контакты e-mail:</b> <ins>kristina.bilckova@yandex.ru</ins>

<b>Работа выполнена:</b> «22» <ins>апреля</ins> <ins>2023</ins> г.

<b>Преподаватель:</b> <ins>асп. каф. 806 Сахарин Никита Александрович</ins>

<b>Входной контроль знаний с оценкой:</b> <ins>5</ins>

<b>Отчет сдан</b> «22» <ins>апреля</ins> <ins>2023</ins> г., <b>итоговая оценка</b>5<ins>

<b>Подпись преподавателя:</b> ___________


## 1. Тема
Динамические структуры данных. Обработка деревьев
## 2. Цель работы
Составить программу на языке Си для построения и обработки дерева общего вида или упорядоченного двоичного дерева, содержащего узлы типа float.
## 3. Задание (вариант № 2)
Проверить, является ли двоичное дерево B-деревом (нет ни одного узла степени 1).

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

- nodeCreat - создание вершины дерева
- treeCreat - создание дерева
- treeInsert - вставка элемента в дерево
- treeIsEmpty - проверка дерева на пустоту
- treeSize - размер дерева
- clearNode - очистка узла дерева
- clearTree - очистка дерева
- treeSearch - поиск элемента в дереве
- treeDelete - удаление элемента из дерева
- treePrint - печать дерева
- treePreorder - прямой обход дерева
- treeInorder - центрированный обход дерева
- treePostorder - обратный обход дерева
- treeB - проверка на B-дерево

## 7. Сценарий выполнения работы [план работы, первоначальный текст программы в черновике (можно на отдельном листе) и тесты либо соображения по тестированию].

``` :src/lab23.c
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <errno.h>
#include <assert.h>
#include <limits.h>

struct TreeNode {
    struct TreeNode *left;
    struct TreeNode *right;
    struct TreeNode *parent;
    float value;
};

typedef struct TreeNode TreeNode;

typedef struct {
    TreeNode *root;
    size_t size;
} Tree;

TreeNode *nodeCreat(TreeNode * const node, const float val) {
    TreeNode *new = malloc(sizeof(TreeNode));
    new->value = val;
    new->left = NULL;
    new->right = NULL;
    new->parent = node;
    return new;
}

Tree *treeCreat(const float val) {
    Tree *tree = malloc(sizeof(Tree));
    tree->root = nodeCreat(NULL, val);
    ++tree->size;
    return tree;
}

float treeInsert(Tree * const tree, const float val) {
    TreeNode **ptr = &tree->root, *node = NULL;
    while (*ptr != NULL) {
        node = *ptr;
        if (node->value > val) {
            ptr = &node->left;
        }
        else {
            ptr = &node->right;
        }
    }
    *ptr = malloc(sizeof(TreeNode));
    ++tree->size;
    (*ptr)->parent = node;
    (*ptr)->left = NULL;
    (*ptr)->right = NULL;
    (*ptr)->value = val;
    return 0;
}

bool treeIsEmpty(Tree * const tree) {
    return tree->size == 0;
}

size_t treeSize(Tree * const tree) {
    return tree->size;
}

void clearNode(TreeNode * const node) {
    if (node->left) {
        clearNode(node->left);
    }
    if (node->right) {
        clearNode(node->right);
    }
    free(node);
}

void clearTree(Tree * const tree) {
    if (tree->root != NULL){
        clearNode(tree->root);
        tree->root = NULL;
    }
    tree->size = 0;
}

TreeNode *treeSearch(TreeNode *const node, const float val) {
    if ((node == NULL) || (node->value == val)) {
        return node;
    }        
    if (val < node->value) {
        return treeSearch(node->left, val);
    }
    else {
        return treeSearch(node->right, val);
    }
}

float treeDelete(Tree * const tree, const float value) {
    TreeNode **ptr = &tree->root, *node = NULL;
    while (*ptr != NULL) {
        node = *ptr;
        if (node->value > value)
            ptr = &node->left;
        else if (node->value < value)
            ptr = &node->right;
        else
            break;
    }
    assert(node->value == value);
    if (node->left != NULL && node->right != NULL) {
        float * const value = &node->value;
        ptr = &node->right;
        node = node->right;
        while (node->left != NULL) {
            ptr = &node->left;
            node = node->left;
        }
        *value = node->value;
    }
    if (node->left != NULL) {
        assert(node->right == NULL);
        *ptr = node->left;
        node->left->parent = node->parent;
    } else if (node->right != NULL) {
        assert(node->left == NULL);
        *ptr = node->right;
        node->right->parent = node->parent;
    } else
        *ptr = NULL;
    free(node);
    --tree->size;
}

void treePrint(TreeNode * const node, int level) {
    if (node == NULL)
        return;
    for (int i = 0; i < level; i++) {
        printf("\t");
    }
    printf("%-.2f\n", node->value); 
    treePrint(node->right, level + 1);
    treePrint(node->left, level + 1); 
}

void treePreorder(TreeNode * const node) {
    if (node == NULL)
        return;
    if (node->value)
        printf("%.2f ", node->value);
    treePreorder(node->left);
    treePreorder(node->right);
}

void treeInorder(TreeNode * const node) {
    if (node == NULL)
        return;
    treeInorder(node->left);
    if (node->value)
        printf("%.2f ", node->value);
    treeInorder(node->right);
}

void treePostorder(TreeNode * const node) {
    if (node == NULL)
        return;
    treePostorder(node->left);
    treePostorder(node->right);
    if (node->value)
        printf("%.2f ", node->value);
}


bool treeB(TreeNode * const node) {
    if (node == NULL) {
        return true;
    }
    if (node->right != NULL && node->left == NULL)  {
        return false;
    }
    if (node->right == NULL && node->left != NULL)  {
        return false;
    }
    return treeB(node->left) && treeB(node->right);
}

int main() {
    Tree *tree = NULL;
    tree = treeCreat(8);
    treeInsert(tree, 4.5);
    treeInsert(tree, 12.1);
    treeInsert(tree, 2.8);
    treeInsert(tree, 6.19);
    treeInsert(tree, 1.47);
    treeInsert(tree, 3.23);
    treeInsert(tree, 5);
    treeInsert(tree, 7.455);
    treeInsert(tree, 10.12);
    treeInsert(tree, 14.902);
    treeInsert(tree, 9.1);
    treeInsert(tree, 13.0);
    treeInsert(tree, 15.1909);

    printf("Size of the tree = %ld\n", treeSize(tree));
    treePrint(tree->root, 0);
    if (treeB(tree->root)) {
        printf("This is a B-tree\n");
    } else {
        printf("This is not a B-tree\n");
    }
    treePreorder(tree->root);
    printf("\n");
    treeInorder(tree->root);
    printf("\n");
    treePostorder(tree->root);
    printf("\n"); 

    treeDelete(tree, 9.1);

    printf("-\nSize of the tree = %ld\n", treeSize(tree));
    treePrint(tree->root, 0);
    if (treeB(tree->root)) {
        printf("This is a B-tree\n");
    } else {
        printf("This is not a B-tree\n");
    }
    treePreorder(tree->root);
    printf("\n");
    treeInorder(tree->root);
    printf("\n");
    treePostorder(tree->root);
    printf("\n");

    treeDelete(tree, 4.5);
    printf("-\nSize of the tree = %ld\n", treeSize(tree));
    treePrint(tree->root, 0);
    if (treeB(tree->root)) {
        printf("This is a B-tree\n");
    } else {
        printf("This is not a B-tree\n");
    }
    treePreorder(tree->root);
    printf("\n");
    treeInorder(tree->root);
    printf("\n");
    treePostorder(tree->root);
    printf("\n");

    clearTree(tree);

    treeInsert(tree, 8.88);
    treeInsert(tree, 3.2);
    printf("-\nSize of the tree = %ld\n", treeSize(tree));
    treePrint(tree->root, 0);
    if (treeB(tree->root)) {
        printf("This is a B-tree\n");
    } else {
        printf("This is not a B-tree\n");
    }
    return 0;
}
```

Пункты 1-7 отчета составляются сторого до начала лабораторной работы.
Допущен к выполнению работы.  
<b>Подпись преподавателя:</b> _____________________

## 8. Распечатка протокола 

```
kristinab@LAPTOP-SFU9B1F4:/mnt/c/Users/Admin/Projects/C$ gcc lab23.c && ./a.out
Size of the tree = 14
8.00
        12.10
                14.90
                        15.19
                        13.00
                10.12
                        9.10
        4.50
                6.19
                        7.45
                        5.00
                2.80
                        3.23
                        1.47
This is not a B-tree
8.00 4.50 2.80 1.47 3.23 6.19 5.00 7.45 12.10 10.12 9.10 14.90 13.00 15.19
1.47 2.80 3.23 4.50 5.00 6.19 7.45 8.00 9.10 10.12 12.10 13.00 14.90 15.19
1.47 3.23 2.80 5.00 7.45 6.19 4.50 9.10 10.12 13.00 15.19 14.90 12.10 8.00
-
Size of the tree = 13
8.00
        12.10
                14.90
                        15.19
                        13.00
                10.12
        4.50
                6.19
                        7.45
                        5.00
                2.80
                        3.23
                        1.47
This is a B-tree
8.00 4.50 2.80 1.47 3.23 6.19 5.00 7.45 12.10 10.12 14.90 13.00 15.19
1.47 2.80 3.23 4.50 5.00 6.19 7.45 8.00 10.12 12.10 13.00 14.90 15.19
1.47 3.23 2.80 5.00 7.45 6.19 4.50 10.12 13.00 15.19 14.90 12.10 8.00
-
Size of the tree = 12
8.00
        12.10
                14.90
                        15.19
                        13.00
                10.12
        5.00
                6.19
                        7.45
                2.80
                        3.23
                        1.47
This is not a B-tree
8.00 5.00 2.80 1.47 3.23 6.19 7.45 12.10 10.12 14.90 13.00 15.19
1.47 2.80 3.23 5.00 6.19 7.45 8.00 10.12 12.10 13.00 14.90 15.19
1.47 3.23 2.80 7.45 6.19 5.00 10.12 13.00 15.19 14.90 12.10 8.00
-
Size of the tree = 2
8.88
        3.20
This is not a B-tree
```

## 9. Дневник отладки должен содержать дату и время сеансов отладки и основные события (ошибки в сценарии и программе, нестандартные ситуации) и краткие комментарии к ним. В дневнике отладки приводятся сведения об использовании других ЭВМ, существенном участии преподавателя и других лиц в написании и отладке программы.

| № |  Лаб. или дом. | Дата | Время | Событие | Действие по исправлению | Примечание |
| ------ | ------ | ------ | ------ | ------ | ------ | ------ |
| 1 | дом. | 22.04.23 | 13:00 | Выполнение лабораторной работы | - | - |

## 10. Замечания автора по существу работы

<b>div2</b>

- [Задача во время контеста](https://mai2022.contest.codeforces.com/group/Ej1bTQMkro/contest/427391/submission/198785991)
- [Задача во время контеста](https://mai2022.contest.codeforces.com/group/Ej1bTQMkro/contest/427391/submission/198798762)
- [Дорешка](https://mai2022.contest.codeforces.com/group/Ej1bTQMkro/contest/427391/submission/203823875)


## 11. Выводы
Были изучены динамические структуры данных. Была составлена программа на языке Си для обработки двоичного дерева. Были приобретены навыки, которые будут полезны для выполнения других лабораторных работ и курсовых проектов.

Недочёты при выполнении задания могут быть устранены следующим образом: —

<b>Подпись студента:</b> _________________


