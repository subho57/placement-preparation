// C Program to insert an element before a specific position
// @uthor : Subhankar Pal
// dated : 24-08-2020
#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int data;
    struct Node* next;
}node;
node* head;
void print(){
    node* temp=head;
    while(temp!=NULL){
        if(temp->next==NULL)
            printf("%d", temp->data);
        else
            printf("%d ", temp->data);
        temp=temp->next;
    }
}
void append(int n){
    node* newnode=(node*)malloc(sizeof(node));
    newnode->data=n;
    newnode->next=NULL;
    if(head==NULL)
        head=newnode;
    else{
        node* temp=head;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=newnode;
    }
}
void insert_before_pos(int p, int n, int x){
    if(p>=1 && p<=x){
        node* temp=head;
        while(--p)
            temp=temp->next;
        node* newnode=(node*)malloc(sizeof(node));
        newnode->data=n;
        newnode->next=temp->next;
        temp->next=newnode;
    }
}
int main(void) {
    head=(node*)malloc(sizeof(node));
    head=NULL;
    int n,x,p;
    printf("Enter the no. of node in the linked list: ");
    scanf("%d", &x);
    printf("Enter the no. you want to insert: ");
    scanf("%d", &n);
    printf("Enter the position before which you want to insert: ");
    scanf("%d", &p);
    int cpy=x;
    printf("Enter all the elements: ");
    while(x--){
        int temp;
        scanf("%d", &temp);
        append(temp);
    }
    insert_before_pos(p-1, n, cpy);
    print();
    return 0;
}