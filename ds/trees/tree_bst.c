#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include "queue.h"

// to find the maximum element out of two
#define max(a,b) (((a) > (b)) ? (a) : (b))

typedef int type;

typedef struct BSTnode{
    type data;
    struct BSTnode *left;
    struct BSTnode *right;
    struct BSTnode *parent;
}node;

// to binary search data in the tree
type search(node *tree, type number) {
    if (tree == NULL)
        return 0;
    else if (number < tree->data)
        return search(tree->left, number);
    else if (number > tree->data)
        return search(tree->right, number);
    else
        return 1;
}

// create a new node in memory and insert a value at its data ~ O(1)
node* createnode(type value){
    node *newnode = (node *)malloc(sizeof(node));
    if(newnode == NULL){
        printf("Memory could not be allocated!");
        return NULL;
    }
    newnode->data = value;
    newnode->left = newnode->right = newnode->parent = NULL;
    return newnode;
}

// insert data in the BST
void insert(node **root, type val) {
    if ((*root) == NULL)
        *root = createnode(val);
    else if (val <= (*root)->data)
        insert(&(*root)->left, val);
    else
        insert(&(*root)->right, val);
}

// to find the maximum element iteratively
type find_max_itr(node *root) {
    if (root == NULL) {
        printf("The Tree is Empty.\n");
        return 0;
    }
    while (root->right != NULL)
        root = root -> right;
    return root->data;
}

// to find the maximum element iteratively
type find_min_itr(node *root) {
    if (root == NULL) {
        printf("The Tree is Empty.\n");
        return 0;
    }
    while (root->left != NULL)
        root = root -> left;
    return root->data;
}

// to find the maximum element recursively
type find_max_rec(node *root) {
    if (root->right == NULL)
        return root->data;
    return find_max_rec(root->right);
}

// to find the minimum element recursively
type find_min_rec(node *root) {
    if (root->left == NULL)
        return root->data;
    return find_min_rec(root->left);
}

// to find the height of the bst
int find_height(node *root) {
    if (root == NULL)
        return -1;
    return max(find_height(root->left), find_height(root->right)) + 1;
}

// to print the tree in the level order or breadth first traversal ~ O(n)
void print_level_order(node *root) {
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
void preorder(node *root) {
    if (root == NULL)
        return;
    printf("%d ", root -> data);
    preorder(root -> left);
    preorder(root -> right);
}

// O(n)
void postorder(node *root) {
    if (root == NULL)
        return;
    postorder(root -> left);
    postorder(root -> right);
    printf("%d ", root -> data);
}

// O(n)
void inorder(node *root) {
    if (root == NULL)
        return;
    inorder(root -> left);
    printf("%d ", root -> data);
    inorder(root -> right);
}

bool isSubTreeLesser(node *root, type val) {
    if (root == NULL) return true;
    if (
        root -> data <= val &&
        isSubTreeLesser(root -> left, val) &&
        isSubTreeLesser(root -> right, val)
        ) return true;
    else return false;
}

bool isSubTreeGreater(node *root,  type val) {
    if (root == NULL) return true;
    if (
        root -> data > val &&
        isSubTreeGreater(root -> left, val) &&
        isSubTreeGreater(root -> right, val)
        ) return true;
    else return false;
}

// O(n^2)
bool is_bst(node *root) {
    if (root == NULL) return true;
    if (
        isSubTreeLesser(root -> left, root -> data) &&
        isSubTreeGreater(root -> right, root -> data) &&
        is_bst(root -> left) &&
        is_bst(root -> right)
        ) return true;
    else return false;
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

void delete(node **root, type data) {
    if ((*root) == NULL)
        return;
    else if (data < (*root) -> data)
        delete(&(*root) -> left, data);
    else if (data > (*root) -> data)
        delete(&(*root) -> right, data);
    else {
        // case 1 : no child nodes
        if ((*root) -> left == NULL && (*root) -> right == NULL) {
            free(*root);
            *root = NULL;
        }
        // case 2 : one child node
        // 2a     : no left child
        else if ((*root) -> left == NULL) {
            node *temp = *root;
            (*root) = (*root) -> right;
            free(temp);
        }
        // 2b     : no right child
        else if ((*root) -> right == NULL) {
            node *temp = *root;
            (*root) = (*root) -> left;
            free(temp);
        }
        // case 3 : there's both left and right child
        else {
            type min = find_min_rec((*root) -> right);
            (*root) -> data = min;
            delete(&(*root)-> right, min);
        }
        return;
    }
}


type inorder_successor(node *root, int data) {

}
int main(void) {
    node *root = NULL;
    insert(&root, 15);
    insert(&root, 10);
    insert(&root, 20);
    insert(&root, 25);
    insert(&root, 8);
    insert(&root, 12);
    if (search(root, 15)) printf("Found!\n");
    else printf("Not Found!\n");
    printf("Max Element = %d\n", find_max_rec(root));
    printf("Min Element = %d\n", find_min_rec(root));
    printf("Height of the tree = %d\n", find_height(root));
    printf("Printing the level Order Traversal: ");
    print_level_order(root);

    printf("Printing the  Pre-Order  Traversal: ");
    preorder(root);
    printf("\n");

    printf("Printing the Post-Order  Traversal: ");
    postorder(root);
    printf("\n");

    printf("Printing the  In-Order   Traversal: ");
    inorder(root);
    printf("\n");

    if(is_bst_efficient(root, INT_MIN, INT_MAX))
        printf("It is a BST!\n");
    else
    {
        printf("It is not a BST\n");
    }
    delete(&root, 12);
    printf("Printing the level Order Traversal: ");
    print_level_order(root);
    printf("Printing the  In-Order   Traversal: ");
    inorder(root);
    printf("\n");
    delete(&root, 15);
    printf("Printing the level Order Traversal: ");
    print_level_order(root);
    printf("Printing the  In-Order   Traversal: ");
    inorder(root);
    printf("\n");
    return 0;
}