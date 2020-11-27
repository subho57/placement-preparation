#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
// #include "queue.h"
#define MAXSIZE 100

typedef int type;

typedef struct TREEnode
{
   type data;
   struct TREEnode* right;
   struct TREEnode* left;
}node;

typedef struct QUEUE
{
    int front;
    int rear;
    node *Q[MAXSIZE];
}queue;

int isEmpty(queue *q)
{
   return (q -> front == -1);
}

void enqueue(queue *q, node *x)
{
    if ((q -> front == q -> rear + 1) || (q -> front == 0 && q -> rear == MAXSIZE - 1))
    {
        printf("Queue Overflows");
    }
    else
    {    
        if (q -> front == -1)
            q -> front = 0;
        q -> rear = (q -> rear + 1) % MAXSIZE;
        q -> Q[q -> rear] = x;
    }
}
node* dequeue(queue *q)
{   
    node* x = NULL;
    if (isEmpty(q))
    {
        printf("Queue underflows");
        return NULL;
    }
    else
    {
        x = q -> Q[q -> front]; 
        if(q -> front == q -> rear)
            q -> rear = q -> front = -1;
        else
            q -> front = (q -> front + 1) % MAXSIZE; 
        return x;
    }
}

node *root=NULL;
void create_tree()
{
    queue q;
    q.front = -1;
    q.rear = -1;
    int x;
    printf("Enter root value: ");
    scanf("%d", &x);
    node *rootnode = (node*)malloc(sizeof(node));
    rootnode -> data = x;
    rootnode -> left = rootnode -> right = NULL;
    root = rootnode;
    enqueue(&q, root);
    while(!isEmpty(&q))
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
// O(n)

void inorder(node *root) {
    if (root == NULL)
        return;
    inorder(root -> left);
    printf("%d ", root -> data);
    inorder(root -> right);
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
    printf("Printing the  In-Order   Traversal: ");
    inorder(root);
    printf("\n");
    return 0;
}