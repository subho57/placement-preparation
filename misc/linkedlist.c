// Linked lIst sample
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
typedef struct Node{
    int data;
    struct Node* next;
}node;
void print(node **temp){
    while (*temp != NULL){
        printf("%d ", (*temp)->data);
        temp = (*temp)->next;
    }
}
void prepend(node **head_ref, int n){
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = n;
    newnode->next = *head_ref;
    *head_ref = newnode;
}
void append(node **head_ref, int n){
    node *newnode = (node *)malloc(sizeof(node));
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
int main(void){
    struct node *head = NULL;
    int n;
    scanf("%d", &n);
    while (n--){
        int temp;
        scanf("%d", &temp);
        append(&head, temp);
    }
    prepend(&head, 5);
    prepend(&head, 56);
    
    print(&head);
    return 0;
}