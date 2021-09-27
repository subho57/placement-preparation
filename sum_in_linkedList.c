// C program for addition of two polynomials
// using Linked Lists
#include <stdio.h>
#include <stdlib.h>

// Node structure containing power and coefficient of
// variable
typedef struct Node {
    int data;
    struct Node* next;
} node;

// Function to create new node
void append(node** head_ref, int val)
{
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = val;
    newnode->next = NULL;
    while (*head_ref != NULL)
        head_ref = &(*head_ref)->next;
    *head_ref = newnode;
}

//Function to calculate the sum of the 
//elemets of the LinkedInList
int sum(node** head_ref)
{
    int sum=0;
    while(*head_ref!= NULL)
    {
        sum+=(*head_ref)->data;
        head_ref=&(*head_ref)->next;
    }
    return sum;
}
// Driver  program
int main(void)
{
    node* head = NULL;
    int n;
    //user input part
    scanf("%d", &n);
    while (n--) // taking the coefficients of the 1st
                 // polynomial
    {
        int temp;
        scanf("%d", &temp);
        append(&head, temp);
    }
    printf("%d", sum(&head));
    return 0;
}