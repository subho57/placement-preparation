// C program for addition of two polynomials
// using Linked Lists
#include <stdio.h>
#include <stdlib.h>

// Node structure containing power and coefficient of
// variable
typedef struct Node {
    int coeff; // to store the coefficient of each degree of
               // the polynomial
    int exp; // to store the degree of x in the polynomial.
    struct Node* next;
} node;

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

// Function to add new nodes in the linked list
void append(node** head_ref, int coef, int pow)
{
    node* newnode = (node*)malloc(sizeof(node));
    newnode->coeff = coef;
  	newnode->exp = pow;
    newnode->next = NULL;
    while (*head_ref != NULL)
        head_ref = &(*head_ref)->next;
    *head_ref = newnode;
}

// Function Adding two polynomial numbers
void add(node** head_large, node** head_small, int diff)
{
    node* large = *head_large; // larger polynomial
    node* small = *head_small; // smaller polynomial
    while (diff--) // skipping the excess powers of the
                   // larger polynomial which doesn't need
                   // to be added.
        large = large->next;
    while (small != NULL) {
        // adding the coefficients of the polynomials
        large->coeff = large->coeff + small->coeff;
        small = small->next; // moving to the next degree of
                             // the smaller polynomial
        large = large->next; // moving to the next degree of
                             // the larger polynomial
    }
}

// Driver  program
int main(void)
{
    node* head1 = NULL;
    node* head2 = NULL;

    // // default input part
    // // ommit this part if you want to take user input
    // // inserting the coefficients with their degrees in the
    // // ascending order
    // int arr[4] = { 2, 0, 4, 5 }; // degree = 3
    // // the polynomial is 5x^3 + 4x^2 + 0x^1 + 2x^0
    // int brr[2] = { 5, 5 }; // degree = 1
    // // the polynomial is 5x^1 + 5x^0

    // // creating the polynomial
    // // here i is acting as the exponent/degree
    // for (int i = 3; i >= 0; i--)
    //     append(&head1, arr[i], i);
    // for (int i = 1; i >= 0; i--)
    //     append(&head2, brr[i], i);
    // printf("1st Polynomial   : ");
    // print(head1);
    // printf("\n2nd Polynomial   : ");
    // print(head2);
    // // passing the larger polynomial, followed by the
    // // smaller polynomial, and the difference in their
    // // highest degree.
    // add(&head1, &head2, 3 - 1);
    // printf("\nAdded Polynomial : ");
    // print(head1);

    //user input part
    int n1, n2, cpy1, cpy2;
    scanf("%d", &n1);
    scanf("%d", &n2);
    cpy1 = n1;
    cpy2 = n2;
    n1++;
    n2++;
    int t1 = n1, t2 = n2;
    while (n1--) // taking the coefficients of the 1st
                 // polynomial
    {
        int temp;
        scanf("%d", &temp);
        append(&head1, temp, cpy1--);
    }
    while (n2--) // taking the coefficients of the 1st
                 // polynomial
    {
        int temp;
        scanf("%d", &temp);
        append(&head2, temp, cpy2--);
    }
    if (t1 > t2) {
        add(&head1, &head2, t1 - t2);
        print(head1);
    }
    else {
        add(&head2, &head1, t2 - t1);
        print(head2);
    }

    return 0;
}