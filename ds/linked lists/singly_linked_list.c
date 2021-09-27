/**
 * TODO: Optimise all the functions using tail pointer where applicable
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <limits.h>

// node structure
typedef struct node{
    int data;
    struct node* next; //structure pointer
}node;

// check for an empty node ~ O(1)
int isEmpty(node **head_ref){
    if((*head_ref)==NULL)
        return 1;
    else
        return 0;
}

// create a new node in memory and insert a value at its data ~ O(1)
node* createnode(int value) {
    node *newnode = (node *)malloc(sizeof(node));
    if (newnode == NULL) {
        printf("Memory could not be allocated!");
        exit(0);
    }
    newnode -> data = value;
    newnode -> next = NULL;
    return newnode;
}

// print the list ~ O(n)
void print_itr(node **head_ref) {
    if(isEmpty(head_ref))
        printf("Empty List. Try inserting elements first.\n");
    else{
        printf("Printing the List...\n");
        while (!isEmpty(head_ref)){
            printf("%d ", (*head_ref)->data);
            head_ref = &(*head_ref)->next;
        }
        printf("\n");
    }
}

// printing using recursion ~ O(n)
void print_rec(node **head_ref) { 
    if(isEmpty(head_ref)) {
        printf("\n");
        return;
    }
    printf("%d ", (*head_ref)->data);
    print_rec(&(*head_ref)->next);
}

// reverse print the list ~ O(n)
void revprint_rec(node **head_ref) {
    if(isEmpty(head_ref)) {
        printf("Printing the List in Reverse Order...\n");
        return;
    }
    revprint_rec(&(*head_ref)->next);
    printf("%d ", (*head_ref)->data);
}

// count the number of nodes in the list ~ O(n)
int count(node **head_ref) {
    int c=0;
    while (!isEmpty(head_ref)){
        c++;
        head_ref = &(*head_ref)->next;
    }
    return c;
}

// insert at the beginning ~ O(1)
void prepend(node **head_ref, node **tail_ref, int n) {
    node *newnode = createnode(n);
    newnode->next = *head_ref;
    *head_ref = newnode;
    if (*tail_ref == NULL)
        (*tail_ref) = newnode;
}

// insert at the end ~ O(1)
void append(node **head_ref, node **tail_ref, int n) {
    node *newnode = createnode(n);
    if (isEmpty(head_ref))
        *head_ref = *tail_ref = newnode;
    else {
        (*tail_ref) -> next = newnode;
        *tail_ref = newnode;
    }
}

// insert at any position ~ O(n)
void insert(node **head_ref, node **tail_ref, int n, int pos) {
    int size=count(head_ref);
    if(pos<1 || pos>size+1)
        printf("ERROR!! Postion %d does not exist.\nInsertion is not Possible.\n", pos);
    else if(isEmpty(head_ref) || pos==size+1)
        append(head_ref, tail_ref, n);
    else if(pos==1)
        prepend(head_ref, tail_ref, n);
    else{
        --pos;
        while(--pos)
            head_ref = &(*head_ref)->next;
        node *newnode = createnode(n);
        newnode->next=(*head_ref)->next;
        (*head_ref)->next=newnode;
    }
}

// insert at before given node ~ O(n)
void insert_before(node **head_ref, int b4node, int new) {
    if(isEmpty(head_ref))
        printf("Empty List!!");
    else{
        while(!isEmpty(head_ref) && (*head_ref)->next->data!=b4node)
            head_ref = &(*head_ref)->next;
        node *newnode = createnode(new);
        newnode->next=(*head_ref)->next;
        (*head_ref)->next=newnode;
    }
}

// delete at the beginning ~ O(1)
void deleteAtBegin(node **head_ref, node **tail_ref) {
    if (isEmpty(head_ref))
        printf("ERROR!! Nothing to Delete!\nList is Empty.\n");
    else {
        node* temp=*head_ref;
        (*head_ref)=(*head_ref)->next;
        printf("%d is deleted!\n", temp->data);
        free(temp);
    }
}

// delete at the end ~ O(n)
void deleteAtEnd(node **head_ref, node **tail_ref) {
    if(isEmpty(head_ref))
        printf("ERROR!! Nothing to Delete!\nList is Empty.\n");
    else{
        node* temp=*head_ref;
        while (temp->next->next!=NULL)
            temp=temp->next;
        printf("%d is deleted!\n", temp->next->data);
        free(temp->next);
        temp->next=NULL;
        *tail_ref = temp;
    }
}

// delete at any position ~ O(n)
void delete(node **head_ref, node **tail_ref, int pos) {
    int size=count(head_ref);
    if(pos<1 || pos>size)
        printf("ERROR!! Postion %d does not exist.\nDeletion is not Possible.\n", pos);
    else if(isEmpty(head_ref))
        printf("ERROR!! Nothing to Delete!\nList is Empty.\n");
    else if(pos==1)
        deleteAtBegin(head_ref, tail_ref);
    else if(pos==size)
        deleteAtEnd(head_ref, tail_ref);
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
void deleteAtOddPos(node **head_ref, node **tail_ref) {
    int limit=(int)ceil(count(head_ref)/(float)2);
    for(int i=1;i<=limit;i++)
        delete(head_ref, tail_ref, i);
}

// delete all even positions
void deleteAtEvenPos(node **head_ref, node **tail_ref) {
    int limit=(int)ceil((count(head_ref)-1)/(float)2);
    head_ref = &(*head_ref)->next;
    for(int i=1;i<=limit;i++)
        delete(head_ref, tail_ref, i);
}

// delete all odd elements from the list ~ O(n)
void deleteAllOddNodes(node **head_ref) {
    while ((*head_ref)->data & 1){
        node * del = ( *head_ref);
        (* head_ref) = ( *head_ref)->next;
        free(del);
    }
    node * trav = ( *head_ref)->next;

    while(trav!=NULL){
        if (trav->data % 2 == 0){
            (*head_ref)->next = trav;
            head_ref = &(*head_ref)->next;
            trav = trav->next;
        }
        else{
            node *del = trav;
            trav = trav->next;
            free(del);
        }
    }
    (*head_ref)->next = NULL;
    printf("All Odd Elements Have been deleted.\n");
}

void del_odd_elements(node *head) {
    if((head->data)%2!=0){
        node* t=head->next;
        free(head);
        head=t;
    }
    node* temp = head;
    while (temp != NULL){
        if (temp->next != NULL && temp->next->data % 2 != 0){
            node* t = temp->next->next;
            free(temp->next);
            temp->next = t;
        }
        else
          temp=temp->next;   
    }
}

// linear search in the linked list ~ O(n)
void searchlist(node **head_ref, int key) {
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
void sum_of_nodes(node **head_ref) {
    int sum=0;
    while (!isEmpty(head_ref)){
        sum+=(*head_ref)->data;
        head_ref = &(*head_ref)->next;
    }
    printf("Sum of all the nodes = %d\n", sum);
}

// to sort the list using bubble sort ~ O(n^2)
void bubble_sort(node **head_ref) {
    if(isEmpty(head_ref)){
        printf("ERROR!! List is Empty.");
        return;
    }
    while(!isEmpty(&(*head_ref)->next)){
        node *temp=*head_ref;
        while(!isEmpty(&temp)){
            if((*head_ref)->data > temp->data){
                int swap=temp->data;
                temp->data=(*head_ref)->data;
                (*head_ref)->data=swap;
            }
            temp=temp->next;
        }
        head_ref = &(*head_ref)->next;
    }
    printf("List is now Sorted!!\n");
}

// reverse a linked list ~ O(n)
void reverse_itr(node **head_ref, node **tail_ref) {
    if(isEmpty(head_ref)){
        printf("The List is Empty.\n");
        return;
    }
    node *curr, *prev;
    prev = NULL;
    *tail_ref = curr = *head_ref;
    while (curr != NULL) {
        node *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    *head_ref = prev;
    printf("The list has been reversed.\n");
}

// reverse a linked list using recursion ~ O(n)
void reverse_recur(node **head_ref, node **tail_ref, node *temp) {
    if(temp->next == NULL) {
        printf("The list has been reversed.\n");
        (*head_ref) = temp;
        return;
    }
    reverse_recur(head_ref, tail_ref, temp->next);
    temp -> next -> next = temp;
    temp -> next = NULL;
    *tail_ref = temp;
}

// driver function
int main(void) {
    node *head = NULL;
    node *tail = NULL;
    printf("********************MENU*********************\n");
    printf("* Press:                                    *\n");
    printf("* 1) To Insert an Element at the beginning. *\n");
    printf("* 2) To Insert an Element at the end.       *\n");
    printf("* 3) To Insert an Element at a position.    *\n");
    printf("* 4) To Delete an Element at the beginning. *\n");
    printf("* 5) To Delete an Element at the end.       *\n");
    printf("* 6) To Delete an Element at a position.    *\n");
    printf("* 7) To Print the Linked List.              *\n");
    printf("* 8) To Print the Linked List in Reverse.   *\n");
    printf("* 9) To Sort the Linked List.               *\n");
    printf("* 10) To Reverse the Linked List.           *\n");
    printf("* 11) To Delete all element at odd postion. *\n");
    printf("* 12) To Delete all element at even postion.*\n");
    printf("* 13) To Delete all odd elements.           *\n");
    printf("* 14) To Search for an element in the list. *\n");
    printf("* 15) To Find the Sum of all elements.      *\n");
    printf("* 16) To Exit the Program.                  *\n");
    printf("*********************************************\n");
    do{
        int ch, n, pos, key;
        printf("Enter your Choice: ");
        scanf("%d", &ch);
        switch(ch){
            case 1: printf("Enter an element: ");
                    scanf("%d", &n);
                    prepend(&head, &tail, n);
                    break;
            case 2: printf("Enter an element: ");
                    scanf("%d", &n);
                    append(&head, &tail, n);
                    break;
            case 3: printf("Enter an element: ");
                    scanf("%d", &n);
                    printf("Enter the position: ");
                    scanf("%d", &pos);
                    insert(&head, &tail, n, pos);
                    break;
            case 4: deleteAtBegin(&head, &tail);
                    break;
            case 5: deleteAtEnd(&head, &tail);
                    break;
            case 6: printf("Enter the position you want to delete: ");
                    scanf("%d", &pos);
                    delete(&head, &tail, pos);
                    break;
            case 7: print_itr(&head);
                    break;
            case 8: revprint_rec(&head);
                    printf("\n");
                    break;
            case 9: bubble_sort(&head);
                    break;
            case 10:reverse_itr(&head, &tail);
                    break;
            case 11:deleteAtOddPos(&head, &tail);
                    break;
            case 12:deleteAtEvenPos(&head, &tail);
                    break;
            case 13:deleteAllOddNodes(&head);
                    break;
            case 14:printf("Enter a search key: ");
                    scanf("%d", &key);
                    searchlist(&head, key);
                    break;
            case 15:sum_of_nodes(&head);
                    break;
            case 16:printf("Exiting Program...");
                    exit(0);
                    break;
            default:printf("Wrong Choice!!");
        }
    }while(1);
    return 0;
}