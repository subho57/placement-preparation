#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "queue.h"

typedef struct BSTnode
{
   struct BSTnode* left;
   int data;
   struct BSTnode* right;
}node;

typedef int type;

node *root=NULL;
void create_tree()
{
    queue q;
    init_queue(&q);
    int x;
    printf("Enter root value: ");
    scanf("%d", &x);
    node *rootnode = (node*)malloc(sizeof(node));
    rootnode -> data = x;
    rootnode -> left = rootnode -> right = NULL;
    root = rootnode;
    enqueue(&q, root);
    while(!empty(&q))
    {
       node *p = dequeue(&q);
       printf("Enter the left child of %d or press -1 to exit: ", p -> data);
       scanf("%d", &x);
       if(x != -1)
       {
           node *t=(node*)malloc(sizeof(node));
           t -> data = x;
           t -> left = t -> right = NULL;
           p -> left = t;
           enqueue(&q, t);
       }
        printf("Enter the right child of %d or press -1 to exit: ", p -> data);
        scanf("%d", &x);
        if(x != -1)
        {
           node *t = (node*)malloc(sizeof(node));
           t -> data = x;
           t -> right = t -> right = NULL;
           p -> right = t;
           enqueue(&q, t);
       }
   }
}

// to print the tree in the level order or breadth first traversal ~ O(n)
void print_level_order() {
    if (root == NULL)
        return;
    queue q; init_queue(&q);
    enqueue(&q, root);
    while (!empty(&q)) {
        node *current = peek(&q);
        printf("%d ", current->data);
        if (current -> left != NULL)
            enqueue(&q, current -> left);
        if (current -> right != NULL)
            enqueue(&q, current -> right);
        dequeue(&q);
    }
    printf("\n");
}

// O(n)
bool is_bst_efficient(node *root,  type minval, type maxval) {
    if (root == NULL) return true;
    if (
        root -> data > minval &&
        root -> data < maxval &&
        is_bst_efficient(root -> left, minval, root -> data) &&
        is_bst_efficient(root -> right, root -> data, maxval)
        )
        return true;
    else
        return false;
}

int main(void) {
    create_tree();
    if(is_bst_efficient(root, INT_MIN, INT_MAX))
        printf("It is a BST!\n");
    else
    {
        printf("It is not a BST\n");
    }
    print_level_order();
    return 0;
}