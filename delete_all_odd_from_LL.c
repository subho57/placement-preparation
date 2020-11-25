#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// node structure
typedef struct Node{
    int data;
    struct Node* next;
}node;

// check for an empty node
int isEmpty(node **head_ref){
    if((*head_ref)==NULL)
        return 1;
    else
        return 0;
}

// create a new node in memory and insert a value at its data
node* createnode(int value){
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data=value;
    newnode->next=NULL;
    return newnode;
}

// print the list
void print(node **head_ref){
    while (!isEmpty(head_ref)){
        printf("%d ", (*head_ref)->data);
        head_ref = &(*head_ref)->next;
    }
}

// count the number of nodes in the list
int count(node **head_ref){
    int c=0;
    while (!isEmpty(head_ref)){
        c++;
        head_ref = &(*head_ref)->next;
    }
    return c;
}

// insert at the beginning
void prepend(node **head_ref, int n){
    node *newnode = createnode(n);
    newnode->next = *head_ref;
    *head_ref = newnode;
}

// insert at the end
void append(node **head_ref, int n){
    node *newnode = createnode(n);
    if (isEmpty(head_ref))
        *head_ref = newnode;
    else{
        while (!isEmpty(&(*head_ref)->next))
            head_ref = &(*head_ref)->next;
        (*head_ref)->next = newnode;
    }
}

// insert at any position
void insert(node **head_ref, int n, int pos){
    int size=count(head_ref);
    if(pos<1 || pos>size+1)
        printf("ERROR!! Postion %d does not exist.\nInsertion is not Possible.\n", pos);
    else if(isEmpty(head_ref) || pos==size+1)
        append(head_ref, n);
    else if(pos==1)
        prepend(head_ref, n);
    else{
        --pos;
        while(--pos)
            head_ref = &(*head_ref)->next;
        node *newnode = createnode(n);
        newnode->next=(*head_ref)->next;
        (*head_ref)->next=newnode;
    }
}

// delete at the beginning
void deleteAtBegin(node **head_ref){
    if(isEmpty(head_ref))
        printf("ERROR!! Nothing to Delete!\nList is Empty.\n");
    else{
        node* temp=*head_ref;
        (*head_ref)=(*head_ref)->next;
        free(temp);
    }
}

// delete at the end
void deleteAtEnd(node **head_ref){
    if(isEmpty(head_ref))
        printf("ERROR!! Nothing to Delete!\nList is Empty.\n");
    else{
        node* temp=*head_ref;
        while (temp->next->next!=NULL)
            temp=temp->next;
        free(temp->next->next);
        temp->next=NULL;
    }
}

// delete at any position
void delete(node **head_ref, int pos){
    int size=count(head_ref);
    if(pos<1 || pos>size)
        printf("ERROR!! Postion %d does not exist.\nDeletion is not Possible.\n", pos);
    else if(isEmpty(head_ref))
        printf("ERROR!! Nothing to Delete!\nList is Empty.\n");
    else if(pos==1)
        deleteAtBegin(head_ref);
    else if(pos==size)
        deleteAtEnd(head_ref);
    else{
        --pos;
        while(--pos)
            head_ref = &(*head_ref)->next;
        node *temp=(*head_ref)->next;
        (*head_ref)->next = (*head_ref)->next->next;
        free(temp);
    }
}

// delete all odd positions
void deleteAtOddPos(node **head_ref){
    int limit=(int)ceil(count(head_ref)/(float)2);
    for(int i=1;i<=limit;i++)
        delete(head_ref, i);
}

// delete all even positions
void deleteAtEvenPos(node **head_ref){
    int limit=(int)ceil((count(head_ref)-1)/(float)2);
    head_ref = &(*head_ref)->next;
    for(int i=1;i<=limit;i++)
        delete(head_ref, i);
}

// linear search in the linked list
void searchlist(node **head_ref, int key){
    int pos=1;
    if(isEmpty(head_ref)){
        printf("ERROR!! List is Empty.\n");
        return;
    }
    while (!isEmpty(head_ref)){
        if((*head_ref)->data==key){
            printf("%d is found at Position %d\n", key, pos);
            return;
        }
        head_ref = &(*head_ref)->next;
        pos++;
    }
    printf("%d was not found in the List.\n", key);
}

// driver function
int main(void){
    node *head = NULL;
    int size;
    printf("Enter the number of nodes: ");
    scanf("%d", &size);
    printf("Enter the elements: ");
    while (size--){
        int temp;
        scanf("%d", &temp);
        append(&head, temp);
    }
    printf("Before Deletion\t: ");
    print(&head);
    deleteAtOddPos(&head);
    printf("\nAfter Deletion\t: ");
    print(&head);
    return 0;
}