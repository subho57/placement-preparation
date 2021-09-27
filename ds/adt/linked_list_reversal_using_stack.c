#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack_ll.h"

void print(node *temp){
    while (temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
}
void append(node **head_ref, int n){
    node *newnode = (node*)malloc(sizeof(node));
    newnode->data = n;
    newnode->next = NULL;
    if (*head_ref == NULL)
        *head_ref = newnode;
    else{
        node *temp = *head_ref;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newnode;
    }
}

void Reverse(node **head_ref) {
    Stack *stk = NULL;
    while ((*head_ref)->next != NULL) {
        push(&stk, (*head_ref));
        (*head_ref) = (*head_ref)->next;
    }
    while (!isEmpty(stk)) {
        (*head_ref)->next = pop(&stk);
        head_ref = &(*head_ref)->next;
    }
    (*head_ref)->next = NULL;
}

int main(void){
    node *head = NULL;
    int n;
    printf("Enter the number of elements you want to enter: ");
    scanf("%d", &n);
    while (n--){
        int temp;
        printf("Enter element: ");
        scanf("%d", &temp);
        append(&head, temp);
    }
    printf("Before Reversing: ");
    print(head);
    printf("\n After Reversing: ");
    Reverse(&head);
    print(head);
    return 0;
}