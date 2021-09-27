#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

typedef int type;

typedef struct TREEnode
{
    type data;
    struct TREEnode *left;
    struct TREEnode *right;
    struct TREEnode *parent;
} node;

// create a new node in memory and insert a value at its data ~ O(1)
node *createnode(type value)
{
    node *newnode = (node *)malloc(sizeof(node));
    if (newnode == NULL)
    {
        printf("Memory could not be allocated!");
        return NULL;
    }
    newnode->data = value;
    newnode->left = newnode->right = newnode->parent = NULL;
    return newnode;
}

// insert data in the BST
void insert(node **root, type val)
{
    if ((*root) == NULL)
        *root = createnode(val);
    else if (val <= (*root)->data)
        insert(&(*root)->left, val);
    else
        insert(&(*root)->right, val);
}

// O(n)
void preorder(node *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

int main(void)
{
    node *root = NULL;
    insert(&root, 15);
    insert(&root, 10);
    insert(&root, 20);
    insert(&root, 25);
    insert(&root, 8);
    insert(&root, 12);
    printf("Printing the  Pre-Order  Traversal: ");
    preorder(root);
    printf("\n");
    
    return 0;
}