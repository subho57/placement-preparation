#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

typedef struct TreeNode
{
    struct TreeNode *leftchild;
    struct TreeNode *rightchild;
    int data;
} node;

typedef struct NODE
{
    node *halua;
    struct NODE *link;
} stack;

void push(stack **top, node *key)
{
    stack *new = (stack *)malloc(sizeof(stack));
    new->halua = key;
    if (*top == NULL)
    {
        *top = new;
    }
    else
    {
        new->link = *top;
        *top = new;
    }
}
node *pop(stack **top)
{
    node *k = NULL;
    if (*top == NULL)
        printf("\nStack underflows!!\n");
    else
    {
        stack *t = (*top)->link;
        k = (*top)->halua;
        free(*top);
        *top = t;
    }
    return k;
}

node *root = NULL;
void create_bst_from_preorder(int b[], int l)
{
    node *p;
    int i = 0;
    stack *s = NULL;
    if (root == NULL)
    {
        node *new = (node *)malloc(sizeof(node));
        new->data = b[i++];
        new->leftchild = new->rightchild = NULL;
        push(&s, new);
        root = new;
    }
    p = root;
    while (i < l)
    {
        if (b[i] < p->data)
        {
            node *new = (node *)malloc(sizeof(node));
            new->data = b[i++];
            new->leftchild = new->rightchild = NULL;
            push(&s, new);
            p->leftchild = new;
            p = new;
        }
        else
        {
            if (b[i] > p->data && (b[i] < s->halua->data || s == NULL))
            {
                node *new = (node *)malloc(sizeof(node));
                new->data = b[i++];
                new->leftchild = new->rightchild = NULL;
                p->rightchild = new;
                p = new;
            }
            else
            {
                p = pop(&s);
            }
        }
    }
}

void inorder(node *r)
{
    if (r == NULL)
        return;
    inorder(r->leftchild);
    printf("%d ", r->data);
    inorder(r->rightchild);
}
int main()
{
    char a[100];
    int p[50], c = 0;
    printf("Enter the preorder:\n");
    scanf("%[^\n]%*c", a);
    int len = strlen(a);
    int i;
    for (i = 0; i < len; i++)
    {
        if (a[i] >= 48 && a[i] <= 57)
        {
            int temp = a[i] - 48;
            int j = i + 1;
            while (a[j] != ' ' && j < len)
            {
                temp = temp * 10 + a[j] - 48;
                j++;
            }
            i = j;
            p[c++] = temp;
        }
    }
    create_bst_from_preorder(p, c);
    printf("The inorder Tree:\t");
    inorder(root);
    return 0;
}