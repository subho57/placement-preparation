// C program to insert a node in AVL tree
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
// A utility function to get maximum of two integers
#define max(a, b) (((a) > (b)) ? (a) : (b))
// An AVL tree node
typedef struct TREEnode
{
    int key;
    struct TREEnode *left;
    struct TREEnode *right;
    int height;
} node;

// A utility function to get the height of the tree
int height(struct TREEnode *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

/* Helper function that allocates a new node with the given key and 
	NULL left and right pointers. */
struct TREEnode *newNode(int key)
{
    struct TREEnode *new = (struct TREEnode *)malloc(sizeof(struct TREEnode));
    new->key = key;
    new->left = new->right = NULL;
    new->height = 1; // new node is initially added at leaf
    return (new);
}

// A utility function to right rotate subtree rooted with y
// See the diagram given above.
struct TREEnode *rightRotate(struct TREEnode *y)
{
    struct TREEnode *x = y->left;
    struct TREEnode *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    // Return new root
    return x;
}

// A utility function to left rotate subtree rooted with x
// See the diagram given above.
struct TREEnode *leftRotate(struct TREEnode *x)
{
    struct TREEnode *y = x->right;
    struct TREEnode *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    // Return new root
    return y;
}

// Get Balance factor of node N
int getBalance(struct TREEnode *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

// Recursive function to insert a key in the subtree rooted
// with node and returns the new root of the subtree.
struct TREEnode *insert(struct TREEnode *node, int key)
{
    /* 1. Perform the normal BST insertion */
    if (node == NULL)
        return (newNode(key));
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else // Equal keys are not allowed in BST
        return node;

    /* 2. Update height of this ancestor node */
    node->height = 1 + max(height(node->left), height(node->right));

    /* 3. Get the balance factor of this ancestor 
		node to check whether this node became 
		unbalanced */
    int balance = getBalance(node);

    // If this node becomes unbalanced, then
    // there are 4 cases

    // Left Left Case
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    /* return the (unchanged) node pointer */
    return node;
}

// A utility function to print preorder traversal
// of the tree.
// The function also prints height of every node
void preOrder(struct TREEnode *root)
{
    if (root != NULL)
    {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}
void inorder(struct TREEnode *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->key);
    inorder(root->right);
}

void print_level_order(struct TREEnode *root)
{
    if (root == NULL)
        return;
    queue q;
    new_queue(&q);
    q.enqueue(&q, root);
    while (!q.empty(&q))
    {
        struct TREEnode *current = q.peek(&q);
        printf("%d ", current->key);
        if (current->left != NULL)
            q.enqueue(&q, current->left);
        if (current->right != NULL)
            q.enqueue(&q, current->right);
        q.dequeue(&q);
    }
    printf("\n");
}

/* Driver program to test above function*/
int main()
{
    struct TREEnode *root = NULL;
    int arr[] = {1, 3, 5, 9, 4, 2, 6, 8, 7, 10, 23, 25, 20};
    /* Constructing tree given in the above figure */
    for (int i = 0; i < (sizeof(arr) / sizeof(arr[0])); i++)
        root = insert(root, i);

    printf("Preorder traversal of the constructed AVL tree is \n");
    preOrder(root);

    printf("\nPrinting the  In-Order   Traversal: ");
    inorder(root);
    printf("\n");
    printf("Printing the level Order Traversal: ");
    print_level_order(root);
    return 0;
}
