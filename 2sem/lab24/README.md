# Отчёт по лабораторной работе №24 по курсу “Языки и методы программирования”

<b>Студент группы:</b> <ins>М80-108Б-22 Былькова Кристина Алексеевна, № по списку 2</ins>

<b>Контакты e-mail:</b> <ins>kristina.bilckova@yandex.ru</ins>

<b>Работа выполнена:</b> «3» <ins>июня</ins> <ins>2023</ins> г.

<b>Преподаватель:</b> <ins>асп. каф. 806 Сахарин Никита Александрович</ins>

<b>Входной контроль знаний с оценкой:</b> <ins>5</ins>

<b>Отчет сдан</b> «3» <ins>июня</ins> <ins>2023</ins> г., <b>итоговая оценка</b>5<ins> </ins>

<b>Подпись преподавателя:</b> ___________


## 1. Тема
Динамические структуры данных. Обработка деревьев
## 2. Цель работы
Составить программу выполнения заданных преобразований арифметических выражений с применением деревьев.
## 3. Задание (вариант № 2)
Упростить выражения, выполнив вычитание.
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

1. stackCreate - создание стека;
2. stackEmpty - проверка стека на пустоту;
3. stackPeek - посмотреть на последний элемент в стеке;
4. stackPop - удалить элемент из стека;
5. stackPush - добавить элемент в стек;
6. isLetter - проверка, является ли буквой;
7. isDigit - проверка, является ли цифрой;
8. isOperator - проверка, является ли оператором;
9. opPriority - приоритет операций;
10. infixToPostfix - преобразовать инфиксную запись в постфиксную;
11. nodeValCreate - создать вершину числа;
12. nodeVarCreate - создать вершину строки;
13. nodeOpCreate - создать вершину оператора;
14. treeDelete - удалить дерево;
15. postfixToTree - преобразовать постфиксную запись в дерево;
16. infixToTree - преобразовать инфиксную запись в дерево;
17. treeInorder - инфиксный обход дерева;
18. treePostorder - постфиксный обход дерева;
19. treePrint - вывод дерева;
20. treeSimplify - задание;
21. ipow - возведение в степень;
22. treeCalculate - подсчет дерева.


## 7. Сценарий выполнения работы [план работы, первоначальный текст программы в черновике (можно на отдельном листе) и тесты либо соображения по тестированию].

```:stc/lab24.h
#ifndef LAB24_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define VARIABLE_LENGTH (8U)
#define MAX_SIZE 100

struct Stack {
    int top;
    int capacity;
    char* array;
};
typedef struct Stack Stack;

typedef struct Node Node;

typedef struct {
    Node *left, *right;
    char op;
} Operator;

typedef union {
    Operator op;  // '+' '-' '*' '/' '^'
    float value; // числа
    char variable[VARIABLE_LENGTH]; //буквы
} NodeUnion;

typedef enum {
    OPERATOR,
    VALUE,
    VARIABLE
} NodeType;

struct Node {
    Node *parent;
    NodeUnion nodeUnion;
    NodeType nodeType;
};

Stack* stackCreate(int capacity);
int stackEmpty(Stack* stack);
char stackPeek(Stack* stack);
char stackPop(Stack* stack);
void stackPush(Stack* stack, char op);
void stackDelete(Stack* stack);

int isLetter(char ch);
int isDigit(char ch);
int isOperator(char ch);
int opPriority(char ch);
void infixToPostfix(char* infix, char* postfix);

Node* nodeValCreate(float val);
Node* nodeVarCreate(char var[]);
Node* nodeOpCreate(char op, Node* left, Node* right);
void treeDelete(Node* root);
Node* postfixToTree(char *postfix);
Node* infixToTree(char *infix);
void treeInorder(Node* const node);
void treePostorder(Node* const node);
void treePrint(Node* const node, int level);
Node* treeSimplify(Node* node);
float ipow(float x, int step);
Node* treeCalculate(Node * node);

#endif
```

```:stc/lab24.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#include "lab24.h"

Stack* stackCreate(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if (stack == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (char*)malloc(stack->capacity * sizeof(char));
    if (stack->array == NULL) {
        exit(1);
    }
    return stack;
}

int stackEmpty(Stack* stack) {
    return stack->top == -1;
}

char stackPeek(Stack* stack) {
    return stack->array[stack->top];
}

char stackPop(Stack* stack) {
    if (!stackEmpty(stack))
        return stack->array[stack->top--];
    return '~';
}

void stackPush(Stack* stack, char op) {
    stack->array[++stack->top] = op;
}

void stackDelete(Stack* stack) {
    free(stack->array);
    free(stack);
}

int isLetter(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

int isDigit(char ch) {
    return (ch >= '0' && ch <= '9');
} 

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

int opPriority(char ch) {
    switch (ch) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return -1;
}

void infixToPostfix(char* infix, char* postfix) {
    Stack* stack = stackCreate(MAX_SIZE);
    int i, j;
    i = j = 0;
    while (infix[i] != '\0') {
        if (isLetter(infix[i]) || isDigit(infix[i])) {
            postfix[j++] = infix[i];
            if (isOperator(infix[i+1])) postfix[j++] = ' ';
            if (infix[i+1] =='\0') postfix[j++] = ' ';
        }
        else if (infix[i] == '(') { stackPush(stack, infix[i]); }
        else if (infix[i] == ')') {
            while (!stackEmpty(stack) && stackPeek(stack) != '(') {
                if (postfix[j - 1] != ' ') postfix[j++] = ' ';
                postfix[j++] = stackPop(stack);
                postfix[j++] = ' ';
            }
            if (!stackEmpty(stack) && stackPeek(stack) != '(') {
                printf("Invalid infix expression!\n");
                return;
            } else { stackPop(stack); }
        } 
        else {
            if (infix[i] == '^') {
                while (stackPeek(stack) != '(' && opPriority(stackPeek(stack)) > opPriority(infix[i])) {
                postfix[j++] = stackPop(stack);
                postfix[j++] = ' ';
                }
            }
            else {
                while (!stackEmpty(stack) && (opPriority(stackPeek(stack)) >= opPriority(infix[i])) ) {
                    if (postfix[j] != ' ') postfix[j++] = ' ';
                    postfix[j++] = stackPop(stack);
                    postfix[j++] = ' ';
                }
            }
            stackPush(stack, infix[i]);
        }
        i++;
    }
    while (!stackEmpty(stack)) {
        postfix[j++] = stackPop(stack);
    }
    postfix[j] = '\0';
    stackDelete(stack);
}

Node* nodeValCreate(float val) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->nodeType = VALUE;
    node->nodeUnion.value = val;
    return node;
}

Node* nodeVarCreate(char var[]) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->nodeType = VARIABLE;
    strncpy(node->nodeUnion.variable, var, VARIABLE_LENGTH);
    node->nodeUnion.variable[VARIABLE_LENGTH - 1] = '\0';
    return node;
}

Node* nodeOpCreate(char op, Node* left, Node* right) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->nodeType = OPERATOR;
    node->nodeUnion.op.op = op;
    node->nodeUnion.op.left = left;
    node->nodeUnion.op.right = right;

    if (right != NULL) right->parent = node;
    if (left != NULL) left->parent = node;

    return node;
}

void treeDelete(Node* root) {
    if (root == NULL){
        return;
    }
    if (root->nodeType == OPERATOR) {
        treeDelete(root->nodeUnion.op.left);
        treeDelete(root->nodeUnion.op.right);
    }
    
    free(root);
}

Node* postfixToTree(char *postfix) {
    int len = strlen(postfix);
    Node* stack[len];
    int top = -1;
    for (int i = 0; i < len; i++) {
        char symbol = postfix[i];
        if (isDigit(symbol)) {
            char val[MAX_SIZE];
            int valIndex = 0;
            while (isDigit(postfix[i])) {
                val[valIndex++] = postfix[i++];
            }
            val[valIndex] = '\0';

            double value = atof(val);
            Node* valueNode = nodeValCreate(value);
            stack[++top] = valueNode;
        } 
        else if (isLetter(symbol)){
            char var[MAX_SIZE];
            int varIndex = 0;
            while (isLetter(postfix[i])) {
                var[varIndex++] = postfix[i++];
            }
            var[varIndex] = '\0';
            Node* varNode = nodeVarCreate(var);
            stack[++top] = varNode;
        }
        else if (isOperator(symbol)) {
            Node* right = stack[top--];
            Node* left = stack[top--];
            Node* opNode = nodeOpCreate(symbol, left, right);
            stack[++top] = opNode;
        }
    }
    return stack[top];
}

Node* infixToTree(char *infix) {
    char postfix[MAX_SIZE];
    infixToPostfix(infix, postfix);
    return postfixToTree(postfix);
}

void treeInorder(Node * const node) {
    if (node == NULL)
        return;
    int flag = 0;
    if (node->nodeType == OPERATOR) {
        printf("(");
        treeInorder(node->nodeUnion.op.left);
        printf("%c", node->nodeUnion.op.op);
        treeInorder(node->nodeUnion.op.right);
        printf(")");
    }
    else if (node->nodeType == VALUE) {
        printf("%.2f", node->nodeUnion.value);
    }
    else if (node->nodeType == VARIABLE) {
        printf("%s", node->nodeUnion.variable);
    }
}

void treePostorder(Node* const node) {
    if (node == NULL)
        return;
    if (node->nodeType == OPERATOR) {
        treePostorder(node->nodeUnion.op.left);
        treePostorder(node->nodeUnion.op.right);
        printf("%c ", node->nodeUnion.op.op);
    }
    else if (node->nodeType == VALUE) {
        printf("%.2f ", node->nodeUnion.value);
    }
    else if (node->nodeType == VARIABLE) {
        printf("%s ", node->nodeUnion.variable);
    }
}

void treePrint(Node * const node, int level) {
    if (node == NULL)
        return;
    for (int i = 0; i < level; ++i) {
        printf("\t");
    }
    if (node->nodeType == OPERATOR) {
        printf("%c\n", node->nodeUnion.op.op);
        treePrint(node->nodeUnion.op.right, level + 1);
        treePrint(node->nodeUnion.op.left, level + 1); 
    }
    else if (node->nodeType == VALUE) {
        printf("%.2f\n", node->nodeUnion.value);
    }
    else if (node->nodeType == VARIABLE) {
        printf("%s", node->nodeUnion.variable);
        printf("\n");
    }
}

// Упростить выражения, выполнив вычитание
Node* treeSimplify(Node* node) {
    if (node == NULL) {
        return NULL;
    }
    if (node->nodeType == OPERATOR) {
        node->nodeUnion.op.left = treeSimplify(node->nodeUnion.op.left);
        node->nodeUnion.op.right = treeSimplify(node->nodeUnion.op.right);
        if (node->nodeUnion.op.op == '-') {
            if (node->nodeUnion.op.left != NULL && node->nodeUnion.op.right != NULL) {
                if (node->nodeUnion.op.left->nodeType == VALUE && node->nodeUnion.op.right->nodeType == VALUE) {
                    int result = node->nodeUnion.op.left->nodeUnion.value - node->nodeUnion.op.right->nodeUnion.value;
                    free(node->nodeUnion.op.left);
                    free(node->nodeUnion.op.right);
                    free(node);
                    return nodeValCreate(result);
                }
            }
        }
    }
    return node;
}

float ipow(float x, int exp) {
    if (exp == 0) return 1;
    if (exp == 1) return x;
    float base = x;
    while (exp - 1 > 0) {
        x *= base;
        --exp;
    }
    return x;
}

Node* treeCalculate(Node * node) {
    if (node == NULL) {
        return NULL;
    }
    if (node->nodeType == OPERATOR) {
        node->nodeUnion.op.left = treeCalculate(node->nodeUnion.op.left);
        node->nodeUnion.op.right = treeCalculate(node->nodeUnion.op.right);
        if (node->nodeUnion.op.left != NULL && node->nodeUnion.op.right != NULL) {
            if (node->nodeUnion.op.left->nodeType == VALUE && node->nodeUnion.op.right->nodeType == VALUE) {
                if (node->nodeUnion.op.op == '+') {
                    float res = node->nodeUnion.op.left->nodeUnion.value + node->nodeUnion.op.right->nodeUnion.value;
                    return nodeValCreate(res);
                }
                if (node->nodeUnion.op.op == '-') {
                    float res = node->nodeUnion.op.left->nodeUnion.value - node->nodeUnion.op.right->nodeUnion.value;
                    return nodeValCreate(res);
                }
                if (node->nodeUnion.op.op == '^') {
                    float res = ipow(node->nodeUnion.op.left->nodeUnion.value, node->nodeUnion.op.right->nodeUnion.value);
                    return nodeValCreate(res);
                }
                if (node->nodeUnion.op.op == '*') {
                    float res = node->nodeUnion.op.left->nodeUnion.value * node->nodeUnion.op.right->nodeUnion.value;
                    return nodeValCreate(res);
                }
                if (node->nodeUnion.op.op == '/') {
                    float res = node->nodeUnion.op.left->nodeUnion.value / node->nodeUnion.op.right->nodeUnion.value;
                    return nodeValCreate(res);
                }
            }
        }
    }
    return node;
}

int main() {
    char infix[MAX_SIZE];
    printf("Enter the infix expression: ");
    fgets(infix, sizeof(infix), stdin);
    infix[strcspn(infix, "\n")] = '\0';

    Node* root = infixToTree(infix);
    printf("Tree:\n");
    treePrint(root, 0);
    printf("\n");

    printf("Task tree:\n");
    Node *snode =  treeSimplify(root);
    treePrint(snode, 0);
    printf("\n");

    printf("Infix: ");
    treeInorder(snode);
    printf("\n");
    printf("Postfix: ");
    treePostorder(snode);
    printf("\n");

    Node *calcnode = treeCalculate(snode);
    printf("Calculated:\n");
    treePrint(calcnode, 0);
    treeDelete(snode);
    treeDelete(calcnode);
    return 0;
}
```

Пункты 1-7 отчета составляются сторого до начала лабораторной работы.
Допущен к выполнению работы.  
<b>Подпись преподавателя:</b> _____________________

## 8. Распечатка протокола 

```
kristinab@LAPTOP-SFU9B1F4:/mnt/c/Users/Admin/Projects/C/lab24$ gcc lab24.c && ./a.out
Enter the infix expression: 5-6
Tree:
-
        6.00
        5.00

Task tree:
-1.00

Infix: -1.00
Postfix: -1.00
Calculated: -1.00
kristinab@LAPTOP-SFU9B1F4:/mnt/c/Users/Admin/Projects/C/lab24$ gcc lab24.c && ./a.out
Enter the infix expression: (12-4)^2+9
Tree:
+
        9.00
        ^
                2.00
                -
                        4.00
                        12.00

Task tree:
+
        9.00
        ^
                2.00
                8.00

Infix: ((8.00^2.00)+9.00)
Postfix: 8.00 2.00 ^ 9.00 +
Calculated: 73.00
kristinab@LAPTOP-SFU9B1F4:/mnt/c/Users/Admin/Projects/C/lab24$ gcc lab24.c && ./a.out
Enter the infix expression: (123+45)+(3-2)*(9-1)
Tree:
+
        *
                -
                        1.00
                        9.00
                -
                        2.00
                        3.00
        +
                45.00
                123.00

Task tree:
+
        *
                8.00
                1.00
        +
                45.00
                123.00

Infix: ((123.00+45.00)+(1.00*8.00))
Postfix: 123.00 45.00 + 1.00 8.00 * +
Calculated: 176.00
kristinab@LAPTOP-SFU9B1F4:/mnt/c/Users/Admin/Projects/C/lab24$ gcc lab24.c && ./a.out
Enter the infix expression: (19-5)/2+3
Tree:
+
        3.00
        /
                2.00
                -
                        5.00
                        19.00

Task tree:
+
        3.00
        /
                2.00
                14.00

Infix: ((14.00/2.00)+3.00)
Postfix: 14.00 2.00 / 3.00 +
Calculated: 10.00
kristinab@LAPTOP-SFU9B1F4:/mnt/c/Users/Admin/Projects/C/lab24$ gcc lab24.c && ./a.out
Enter the infix expression: 5^(3^2)
Tree:
^
        ^
                2.00
                3.00
        5.00

Task tree:
^
        ^
                2.00
                3.00
        5.00

Infix: (5.00^(3.00^2.00))
Postfix: 5.00 3.00 2.00 ^ ^
Calculated:
1953125.00
kristinab@LAPTOP-SFU9B1F4:/mnt/c/Users/Admin/Projects/C/lab24$ gcc lab24.c && ./a.out
Enter the infix expression: (5^3)^2
Tree:
^
        2.00
        ^
                3.00
                5.00

Task tree:
^
        2.00
        ^
                3.00
                5.00

Infix: ((5.00^3.00)^2.00)
Postfix: 5.00 3.00 ^ 2.00 ^
Calculated:
15625.00
kristinab@LAPTOP-SFU9B1F4:/mnt/c/Users/Admin/Projects/C/lab24$ gcc lab24.c && ./a.out
Enter the infix expression: 5^3^2
Tree:
^
        ^
                2.00
                3.00
        5.00

Task tree:
^
        ^
                2.00
                3.00
        5.00

Infix: (5.00^(3.00^2.00))
Postfix: 5.00 3.00 2.00 ^ ^
Calculated:
1953125.00
```

## 9. Дневник отладки должен содержать дату и время сеансов отладки и основные события (ошибки в сценарии и программе, нестандартные ситуации) и краткие комментарии к ним. В дневнике отладки приводятся сведения об использовании других ЭВМ, существенном участии преподавателя и других лиц в написании и отладке программы.

| № |  Лаб. или дом. | Дата | Время | Событие | Действие по исправлению | Примечание |
| ------ | ------ | ------ | ------ | ------ | ------ | ------ |
| 1 | дом. | 03.06.23 | 13:00 | Выполнение лабораторной работы | - | - |

## 10. Замечания автора по существу работы

<b>div2</b>

- [Задача во время контеста](https://mai2022.contest.codeforces.com/group/Ej1bTQMkro/contest/427394/submission/201953600)
- [Дорешка](https://mai2022.contest.codeforces.com/group/Ej1bTQMkro/contest/427391/submission/206389137)
- [Дорешка](https://codeforces.com/contest/1806/submission/208074248)
- [Дорешка](https://codeforces.com/contest/1806/submission/208074503)


## 11. Выводы
Была составлена программа на языке Си для выполнения заданного преобразования арифметических выражений с применением деревьев. Были приобретены навыки, которые будут полезны для выполнения других лабораторных работ и курсовых проектов.

Недочёты при выполнении задания могут быть устранены следующим образом: —

<b>Подпись студента:</b> _________________


