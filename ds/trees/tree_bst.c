#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include "queue.h"

// to find the maximum element out of two
#define max(a, b) (((a) > (b)) ? (a) : (b))

typedef int type;

typedef struct TREEnode
{
    type data;
    struct TREEnode *left;
    struct TREEnode *right;
    struct TREEnode *parent;
} node;

// to binary search data in the tree
node *search(node *tree, type number)
{
    if (tree == NULL || number == tree->data)
        return tree;
    if (number < tree->data)
        return search(tree->left, number);
    else
        return search(tree->right, number);
}

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

node *insert_rec(node *root, type val)
{
    if (root == NULL)
    {
        root = createnode(val);
        return root;
    }
    else if (val <= root->data)
        root->left = insert_rec(root->left, val);
    else
        root->right = insert_rec(root->right, val);
    return root;
}

// to find the maximum element iteratively
type find_max_itr(node *root)
{
    if (root == NULL)
    {
        printf("The Tree is Empty.\n");
        return 0;
    }
    while (root->right != NULL)
        root = root->right;
    return root->data;
}

// to find the maximum element iteratively
type find_min_itr(node *root)
{
    if (root == NULL)
    {
        printf("The Tree is Empty.\n");
        return 0;
    }
    while (root->left != NULL)
        root = root->left;
    return root->data;
}

// to find the maximum element recursively
node *find_max_rec(node *root)
{
    if (root->right == NULL)
        return root;
    return find_max_rec(root->right);
}

// to find the minimum element recursively
node *find_min_rec(node *root)
{
    if (root->left == NULL)
        return root;
    return find_min_rec(root->left);
}

// to find the height of the bst
int find_height(node *root)
{
    if (root == NULL)
        return -1;
    return max(find_height(root->left), find_height(root->right)) + 1;
}

// to print the tree in the level order or breadth first traversal ~ O(n)
void print_level_order(node *root)
{
    if (root == NULL)
        return;
    queue q;
    new_queue(&q);
    q.enqueue(&q, root);
    while (!q.empty(&q))
    {
        node *current = q.peek(&q);
        printf("%d ", current->data);
        if (current->left != NULL)
            q.enqueue(&q, current->left);
        if (current->right != NULL)
            q.enqueue(&q, current->right);
        q.dequeue(&q);
    }
    printf("\n");
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

// O(n)
void postorder(node *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

// O(n)
void inorder(node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

bool isSubTreeLesser(node *root, type val)
{
    if (root == NULL)
        return true;
    if (
        root->data <= val &&
        isSubTreeLesser(root->left, val) &&
        isSubTreeLesser(root->right, val))
        return true;
    else
        return false;
}

bool isSubTreeGreater(node *root, type val)
{
    if (root == NULL)
        return true;
    if (
        root->data > val &&
        isSubTreeGreater(root->left, val) &&
        isSubTreeGreater(root->right, val))
        return true;
    else
        return false;
}

// O(n^2)
bool is_bst(node *root)
{
    if (root == NULL)
        return true;
    if (
        isSubTreeLesser(root->left, root->data) &&
        isSubTreeGreater(root->right, root->data) &&
        is_bst(root->left) &&
        is_bst(root->right))
        return true;
    else
        return false;
}

// O(n)
bool is_bst_efficient(node *root, type minval, type maxval)
{
    if (root == NULL)
        return true;
    if (
        root->data > minval &&
        root->data < maxval &&
        is_bst_efficient(root->left, minval, root->data) &&
        is_bst_efficient(root->right, root->data, maxval))
        return true;
    else
        return false;
}

void delete (node **root, type data)
{
    if ((*root) == NULL)
        return;
    else if (data < (*root)->data)
        delete (&(*root)->left, data);
    else if (data > (*root)->data)
        delete (&(*root)->right, data);
    else
    {
        // case 1 : no child nodes
        if ((*root)->left == NULL && (*root)->right == NULL)
        {
            free(*root);
            *root = NULL;
        }
        // case 2 : one child node
        // 2a     : no left child
        else if ((*root)->left == NULL)
        {
            node *temp = *root;
            (*root) = (*root)->right;
            free(temp);
        }
        // 2b     : no right child
        else if ((*root)->right == NULL)
        {
            node *temp = *root;
            (*root) = (*root)->left;
            free(temp);
        }
        // case 3 : there's both left and right child
        else
        {
            type min = find_min_itr((*root)->right);
            (*root)->data = min;
            delete (&(*root)->right, min);
        }
        return;
    }
}

node *inorder_successor(node *root, int data)
{
    // Step 1 : search the given node ~ O(h)
    node *current = search(root, data);
    if (current == NULL)
        return current;
    // Step 2: Case 1 :: if the given node has a right subtree ~ O(h)
    if (current->right != NULL)
        return find_min_rec(current->right);
    // Step 2: Case 2 :: if the given node no right subtree ~ O(h)
    else
    {
        node *successor = NULL;
        node *ancestor = root;
        while (ancestor != current)
        {
            if (current->data < ancestor->data)
            {
                successor = ancestor;
                ancestor = ancestor->left;
            }
            else
                ancestor = ancestor->right;
        }
        return successor;
    }
}

node *inorder_predecessor(node *root, int data)
{
    // Step 1 : search the given node ~ O(h)
    node *current = search(root, data);
    if (current == NULL)
        return current;
    // Step 2: Case 1 :: if the given node has a left subtree ~ O(h)
    if (current->left != NULL)
        return find_max_rec(current->left);
    // Step 2: Case 2 :: if the given node no left subtree ~ O(h)
    else
    {
        node *predecessor = NULL;
        node *ancestor = root;
        while (ancestor != current)
        {
            if (current->data > ancestor->data)
            {
                predecessor = ancestor;
                ancestor = ancestor->right;
            }
            else
                ancestor = ancestor->left;
        }
        return predecessor;
    }
}

node *InPre(node *p)
{
    while (p && p->right != NULL)
        p = p->right;
    return p;
}
node *InSucc(node *p)
{
    while (p && p->left != NULL)
        p = p->left;
    return p;
}

int main(void)
{
    node *root = NULL;
    root = insert_rec(root, 15);
    root = insert_rec(root, 10);
    root = insert_rec(root, 20);
    root = insert_rec(root, 25);
    root = insert_rec(root, 8);
    root = insert_rec(root, 12);

    node *temp = search(root, 20);
    if (temp != NULL)
        printf("Found!\n");
    else
        printf("Not Found!\n");

    printf("Max Element = %d\n", find_max_itr(root));
    printf("Min Element = %d\n", find_min_itr(root));
    printf("Height of the tree = %d\n", find_height(root));

    // printf("Printing the level Order Traversal: ");
    // print_level_order(root);

    printf("Printing the  Pre-Order  Traversal: ");
    preorder(root);
    printf("\n");

    printf("Printing the Post-Order  Traversal: ");
    postorder(root);
    printf("\n");

    printf("Printing the  In-Order   Traversal: ");
    inorder(root);
    printf("\n");

    if (is_bst_efficient(root, INT_MIN, INT_MAX))
        printf("It is a BST!\n");
    else
        printf("It is not a BST\n");

    delete (&root, 12);
    // printf("Printing the level Order Traversal: ");
    // print_level_order(root);
    printf("Printing the  In-Order   Traversal: ");
    inorder(root);
    printf("\n");

    delete (&root, 15);
    // printf("Printing the level Order Traversal: ");
    // print_level_order(root);
    printf("Printing the  In-Order   Traversal: ");
    inorder(root);
    printf("\n");

    node *successor = inorder_successor(root, 20);
    if (successor != NULL)
        printf("Inorder successor of 20 is %d\n", successor->data);
    else
        printf("The given node doesn't have an inorder successor.\n");

    node *predecessor = inorder_predecessor(root, 20);
    if (predecessor != NULL)
        printf("Inorder predecessor of 20 is %d\n", predecessor->data);
    else
        printf("The given node doesn't have an inorder predecessor.\n");

    return 0;
}