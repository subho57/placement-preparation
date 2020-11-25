#include<stdio.h>
typedef struct Node{
int data;
struct Node* next;
}node;
node* head;
void print(){
if(head==NULL)
	printf("Empty List");
else{
	node* temp=(node*)malloc(sizeof(node));
	temp=head;
	while(temp!=NULL){
		printf("%d", temp->data);
		temp=temp->next;
	}
	}
}
int main(void){
head=(node*)malloc(sizeof(node));
node* temp=(node*)malloc(sizeof(node));
