#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Node{
    int data;
    struct Node *prev;
    struct Node *next;
}node;

// check for an empty node ~ O(1)
int isEmpty(node **head_ref){
    if((*head_ref)==NULL)
        return 1;
    else
        return 0;
}

// create a new node in memory and insert a value at its data ~ O(1)
node* createnode(int value){
    node *newnode = (node *)malloc(sizeof(node));
    if(newnode==NULL){
        printf("Memory could not be allocated!");
        return NULL;
    }
    newnode->data=value;
    newnode->next=NULL;
    newnode->prev=NULL;
    return newnode;
}

void print(node **temp){
    while (*temp != NULL){
        printf("%d ", (*temp)->data);
        temp = &(*temp)->next;
    }
    printf("\n");
}

void reverse_print(node **temp){
    while(*temp != NULL){
        printf("%d ", (*temp)->data);
        temp=&(*temp)->prev;
    }
    printf("\n");
}

// count the number of nodes in the list ~ O(n)
int count(node **head_ref){
    int c=0;
    while (!isEmpty(head_ref)){
        c++;
        head_ref = &(*head_ref)->next;
    }
    return c;
}

void prepend(node **head_ref, node **tail_ref, int n){
    node *newnode = createnode(n);
    if(*head_ref == NULL)
        *head_ref = *tail_ref = newnode;
    else{
        (*head_ref)->prev = newnode;
        newnode->next=(*head_ref);
        (*head_ref)=newnode;
    }
}

void append(node **head_ref, node **tail_ref, int n){
    node *newnode = createnode(n);
    if (*head_ref == NULL)
        *head_ref=*tail_ref = newnode;
    else{
        (*tail_ref)->next = newnode;
        newnode->prev=(*tail_ref);
        (*tail_ref)=newnode;
    }
}

// insert at any position ~ O(n)
void insert(node **head_ref, node **tail_ref, int n, int pos){
    int size=count(head_ref);
    if(pos<1 || pos>size+1)
        printf("ERROR!! Postion %d does not exist.\nInsertion is not Possible.\n", pos);
    else if(isEmpty(head_ref) || pos==size+1)
        append(head_ref, tail_ref, n);
    else if(pos==1)
        prepend(head_ref, tail_ref, n);
    else{
        while(--pos)
            head_ref = &(*head_ref)->next;
        node *newnode = createnode(n);
        newnode->next=*head_ref;
        newnode->prev=(*head_ref)->prev;
        (*head_ref)->prev= newnode;
    }
}

// insert at before given node ~ O(n)
void insert_before(node **head_ref, node **tail_ref, int bn, int new){
    if(isEmpty(head_ref))
        printf("Empty List!!");
    else{
        while(!isEmpty(head_ref) && (*head_ref)->next->data!=bn)
            head_ref = &(*head_ref)->next;
        node *newnode = createnode(new);
        newnode->next=*head_ref;
        newnode->prev=(*head_ref)->prev;
        (*head_ref)->prev= newnode;
    }
}

// delete at the beginning ~ O(1)
void deleteAtBegin(node **head_ref){
    if(isEmpty(head_ref))
        printf("ERROR!! Nothing to Delete!\nList is Empty.\n");
    else{
        *head_ref=(*head_ref)->next;
        printf("%d deleted!\n", (*head_ref)->prev->data);
        free((*head_ref)->prev);
        (*head_ref)->prev=NULL;
    }
}

// delete at the end ~ O(1)
void deleteAtEnd(node **head_ref, node **tail_ref){
    if(isEmpty(head_ref))
        printf("ERROR!! Nothing to Delete!\nList is Empty.\n");
    else{
        *tail_ref = (*tail_ref)->prev;
        printf("%d deleted!\n", (*tail_ref)->next->data);
        free((*tail_ref)->next);
        (*tail_ref)->next=NULL;
    }
} 

void delete(node **head_ref, node **tail_ref, int pos){
    int size=count(head_ref);
    if(pos<1 || pos>size)
        printf("ERROR!! Postion %d does not exist.\nDeletion is not Possible.\n", pos);
    else if(isEmpty(head_ref))
        printf("ERROR!! Nothing to Delete!\nList is Empty.\n");
    else if(pos==1)
        deleteAtBegin(head_ref);
    else if(pos==size)
        deleteAtEnd(head_ref, tail_ref);
    else{
        while(--pos)
            head_ref = &(*head_ref)->next;
        (*head_ref)->prev->next=(*head_ref)->next;
        (*head_ref)->next->prev=(*head_ref)->prev;
        printf("%d deleted!\n", (*head_ref)->data);
        free(*head_ref);
    }
}

// delete all odd positions
void deleteAtOddPos(node **head_ref, node **tail_ref){
    int limit=(int)ceil(count(head_ref)/(float)2);
    for(int i=1;i<=limit;i++)
        delete(head_ref, tail_ref, i);
}

// delete all even positions
void deleteAtEvenPos(node **head_ref, node **tail_ref){
    int limit=(int)ceil((count(head_ref)-1)/(float)2);
    head_ref = &(*head_ref)->next;
    for(int i=1;i<=limit;i++)
        delete(head_ref, tail_ref, i);
}

// linear search in the linked list ~ O(n)
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

// returns the sum of all the nodes present ~ O(n)
void sum_of_nodes(node **head_ref){
    int sum=0;
    while (!isEmpty(head_ref)){
        sum+=(*head_ref)->data;
        head_ref = &(*head_ref)->next;
    }
    printf("Sum of all the nodes = %d\n", sum);
}
// // todo
// // to sort the list using bubble sort ~ O(n^2)
// void bubble_sort(node **head_ref){
//     if(isEmpty(head_ref)){
//         printf("ERROR!! List is Empty.");
//         return;
//     }
//     while(!isEmpty(&(*head_ref)->next)){
//         node *temp=*head_ref;
//         while(!isEmpty(&temp)){
//             if((*head_ref)->data > temp->data){
//                 int swap=temp->data;
//                 temp->data=(*head_ref)->data;
//                 (*head_ref)->data=swap;
//             }
//             temp=temp->next;
//         }
//         head_ref = &(*head_ref)->next;
//     }
//     printf("List is now Sorted!!\n");
// }

// reverse a doubly linked list ~ O(n)
void reverse_itr(node **head_ref, node **tail_ref){
    if(isEmpty(head_ref)){
        printf("The List is Empty.\n");
        return;
    }
    *tail_ref = *head_ref;
    node *curr = *head_ref;
    while (!isEmpty(&curr)) {
        node *temp = curr -> next;
        if (temp == NULL)
            *head_ref = curr;
        curr -> next = curr -> prev;
        curr -> prev = temp;
        curr = temp;
    }
    printf("The list has been reversed.\n");
}

int main(void){
    node *head = NULL;
    node *tail = NULL;
    // int n;
    // scanf("%d", &n);
    // while (n--){
    //     int temp;
    //     scanf("%d", &temp);
    //     append(&tail, temp);
    // }
    append(&head, &tail, 5);
    append(&head, &tail, 6);
    append(&head, &tail, 7);
    append(&head, &tail, 8);
    append(&head, &tail, 9);
    prepend(&head, &tail, 10);
    prepend(&head, &tail, 11);
    prepend(&head, &tail, 12);
    
    printf("Printing  Forward: ");
    print(&head);
    printf("Printing Backward: ");
    reverse_print(&tail);
    reverse_itr(&head, &tail);
    printf("Printing Forward:");
    print(&head);
    printf("Printing Backward:");
    reverse_print(&tail);

    return 0;
}