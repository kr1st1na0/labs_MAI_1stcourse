#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <errno.h>
#include <assert.h>
#include <limits.h>

struct TreeNode {
    float value;
    struct TreeNode *left;
    struct TreeNode *right;
    struct TreeNode *parent;
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