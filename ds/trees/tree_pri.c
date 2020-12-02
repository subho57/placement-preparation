#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

typedef struct Treecreate {
    struct Treecreate * leftchild;
    int data;
    struct Treecreate * rightchild;
}node;
    node *root = NULL;

node *insert(node *r, int key) {
    if (r == NULL) {
        node *temp = (node *)malloc(sizeof(node));
        if(temp == NULL){
            printf("Memory could not be allocated!");
            return NULL;
        }
        temp -> data = key;
        temp -> leftchild = r -> rightchild = NULL;
        r = temp;
        return r;
    } else if (key <= r -> data)
        r -> leftchild = insert(r -> leftchild, key);
    else
        r -> rightchild = insert(r -> rightchild, key);
    return r;
}
void inorder(node * r) {
    if (r == NULL)
        return;
    inorder(r -> leftchild);
    printf("%d ", r -> data);
    inorder(r -> rightchild);
}
bool search(node *root, int key) {
    node * t = root;
    while (t != NULL) {
        if (t -> data == key)
            return true;
        else if (key < t -> data)
            t = t -> leftchild;
        else
            t = t -> rightchild;
    }
    return false;
}

node* create(int value)
{
    node *newnode = (node *)malloc(sizeof(node));
    if(newnode == NULL){
        printf("Memory could not be allocated!");
        return NULL;
    }
    newnode->data = value;
    newnode->leftchild = newnode->rightchild= NULL;
    return newnode;
}
void Rinsert(node *r, int key)
{
    if(root == NULL) {
        printf("eta chollo");
        root = create(key);
        printf("eta chollo");
    }
    if(r == NULL) {
        printf("eta chollo");

        r = create(key);
        printf("eta chollo");
    }
    else if(key <= r -> data){
        printf("ekhanei dhuklo else if e\n");
        Rinsert(r -> leftchild, key); 
    }
    else{
        printf("else e gelo\n");
        Rinsert(r -> rightchild, key);
    }     
}
int main() {
    while (1) {
        int n, k;
        printf("\nEnter\n 1.To insert node in the tree\n 2.To display inorder\n 3.To Search a node\n4.To exit\n");
        scanf("%d", &n);
        switch (n) {
            int x;
        case 1:
            printf("\nEnter the tree Node value:");
            scanf("%d", &x);
            // root = insert(root, x);
            Rinsert(root, x);
            printf("Inserted\n");
            break;
        case 2:
            inorder(root);
            break;
        case 3:
            printf("\nEnter key to be searched:");
            scanf("%d", & k);
            if (search(root, k))
                printf("The key %d is present in the tree\n", k);
            else
                printf("The key %d is not present in the tree\n", k);
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Wrong Choice!!");
        }
    }
    return 0;
}