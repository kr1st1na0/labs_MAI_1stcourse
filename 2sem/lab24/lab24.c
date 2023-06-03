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

