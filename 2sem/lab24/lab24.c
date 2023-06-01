#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#include "lab24.h"

Stack* stackCreate(unsigned capacity) {
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
        } else {
            while (!stackEmpty(stack) && opPriority(infix[i]) <= opPriority(stackPeek(stack))) {
                if (postfix[j] != ' ') postfix[j++] = ' ';
                postfix[j++] = stackPop(stack);
                postfix[j++] = ' ';
            }
            stackPush(stack, infix[i]);
        }
        i++;
    }
    while (!stackEmpty(stack)) {
        postfix[j++] = stackPop(stack);
    }
    postfix[j] = '\0';
}

// int abs(int x) {
//     return (x > 0 ? x : 0 - x);
// }

Node* nodeValCreate(int val) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->nodeType = VALUE;
    node->nodeUnion.value = val;
    return node;
}

Node* nodeVarCreate(char var[]) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->nodeType = VARIABLE;
    for (int i = 0; i < strlen(var); ++i) {
        node->nodeUnion.variable[i] = var[i];
    }
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
        printf("%d", node->nodeUnion.value);
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
        printf("%d ", node->nodeUnion.value);
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
        printf("%d\n", node->nodeUnion.value);
    }
    else if (node->nodeType == VARIABLE) {
        for (int i = 0; i < strlen(node->nodeUnion.variable); ++i) {
            printf("%c", node->nodeUnion.variable[i]);
        }
        printf("\n");
    }
}

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
                    free(node);
                    return nodeValCreate(result);
                }
                //else if (node->nodeUnion.op.left->nodeType == VALUE || node->nodeUnion.op.right->nodeType == VALUE)
                // (12+4)-(5+6) - в таком примере мне придется упрощать все операции до вычитания...
            }
        }
        // else if(node->nodeUnion.op.op == '+'){
        //     if (node->nodeUnion.op.left->nodeType == VALUE && node->nodeUnion.op.left->nodeUnion.value < 0){
        //         node->nodeUnion.op.op = '-';
        //         node->nodeUnion.op.left->nodeUnion.value = abs(node->nodeUnion.op.left->nodeUnion.value);
        //     }
        //     if (node->nodeUnion.op.right->nodeType == VALUE && node->nodeUnion.op.right->nodeUnion.value < 0){
        //         node->nodeUnion.op.op = '-';
        //         node->nodeUnion.op.right->nodeUnion.value = abs(node->nodeUnion.op.right->nodeUnion.value);
        //     }
        // }
        // (5-112)+(9+3)+(5-4) - получится ((107-(9+3))+1), а должно быть ((-107+(9+3))+1), ну или вообще ((9+3)-106)
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
    treeSimplify(root);
    treePrint(root, 0);
    printf("\n");

    printf("Infix: ");
    treeInorder(root);
    printf("\n");
    printf("Postfix: ");
    treePostorder(root);
    printf("\n");

    treeDelete(root);
    return 0;
}
