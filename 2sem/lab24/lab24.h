#ifndef LAB24_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define VARIABLE_LENGTH (8U)
#define MAX_SIZE 100

struct Stack {
    int top;
    unsigned capacity;
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
    int value; // числа
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

Stack* stackCreate(unsigned capacity);
int stackEmpty(Stack* stack);
char stackPeek(Stack* stack);
char stackPop(Stack* stack);
void stackPush(Stack* stack, char op);

int isLetter(char ch);
int isDigit(char ch);
int isOperator(char ch);
int opPriority(char ch);
void infixToPostfix(char* infix, char* postfix);


// int abs(int x);
Node* nodeValCreate(int val);
Node* nodeVarCreate(char var[]);
Node* nodeOpCreate(char op, Node* left, Node* right);
void treeDelete(Node* root);
Node* postfixToTree(char *postfix);
Node* infixToTree(char *infix);
void treeInorder(Node* const node);
void treePostorder(Node* const node);
void treePrint(Node* const node, int level);
Node* treeSimplify(Node* node);

#endif