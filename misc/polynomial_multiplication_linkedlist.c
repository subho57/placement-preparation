// C program for addition of two polynomials
// using Linked Lists
#include <stdio.h>
#include <stdlib.h>

// Node structure containing power and coefficient of
// variable
typedef struct Node {
    int coeff;
    int exp;
    struct Node* next;
} node;
typedef struct List{
    struct List* nextnode;
}list;

// Display Linked list
void print(node* temp)
{
    while (temp != NULL) {
        if (temp->exp == 0 && temp->coeff != 0)
            printf(" %d", temp->coeff);
        else if (temp->exp == 1 && temp->coeff != 0)
            printf("%dx +", temp->coeff);
        else if (temp->coeff != 0)
            printf("%dx^%d + ", temp->coeff, temp->exp);
        temp = temp->next;
    }
}

// Function to create new node
void append(node** head_ref, int coef, int pow)
{
    node* newnode = (node*)malloc(sizeof(node));
    newnode->coeff = coef;
    newnode->exp = pow;
    newnode->next = NULL;
    if (*head_ref == NULL)
        *head_ref = newnode;
    else {
        node* temp = *head_ref;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newnode;
    }
}

// Function Adding two polynomial numbers
void add(node** head_large, node** head_small, int diff)
{
    node* large = *head_large;
    node* small = *head_small;
    while (diff--) // skipping the excess powers which
                   // doesn't need to be added.
        large = large->next;
    while (small != NULL) {
        large->coeff
            = large->coeff
            + small->coeff; // adding the polynomials
        small = small->next; // moving to the next power of
                             // the smaller polynomial
        large = large->next; // moving to the next power of
                             // the larger polynomial
    }
}

void product(node** head_large, node ** head_small, node** prod_head, int min)
{
    node* large = *head_large;
    node** prod=prod_head;
    while(large!= NULL)
    {
        node* small = *head_small;
        node* temp = *prod;
        while(small!= NULL)
        {
            append(&temp,large->coeff*small->coeff,large->exp+small->exp);
            small=small->next;
            temp= temp->next;
        }
        prod++;
        large = large->next;
    }
    prod=prod_head;
    add()
    {

    }

}

// Driver  program
int main(void)
{
    node* head1 = NULL;
    node* head2 = NULL;
    node** prod_head=NULL;
    int n1, n2, cpy1, cpy2;
    // //user input part
    // scanf("%d", &n1);
    // scanf("%d", &n2);
    // cpy1 = n1;
    // cpy2 = n2;
    // n1++;
    // n2++;
    // int t1 = n1, t2 = n2;
    // while (n1--) // taking the coefficients of the 1st
    //              // polynomial
    // {
    //     int temp;
    //     scanf("%d", &temp);
    //     append(&head1, temp, cpy1--);
    // }
    // while (n2--) // taking the coefficients of the 1st
    //              // polynomial
    // {
    //     int temp;
    //     scanf("%d", &temp);
    //     append(&head2, temp, cpy2--);
    // }
    // if (t1 > t2) {
    //     add(&head1, &head2, t1 - t2);
    //     print(head1);
    // }
    // else {
    //     add(&head2, &head1, t2 - t1);
    //     print(head2);
    // }
    return 0;
}