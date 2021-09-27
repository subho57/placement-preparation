#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// typedefs
typedef struct Node{
    int data;
    struct Node* next;
}node;

typedef struct Stack{
    node* data;
    struct Stack* next;
}Stack;

// function prototypes
Stack* createStack(node* val);
int isEmpty(Stack *top_ref);
void verti_print(Stack *top);
void hori_print(Stack *top);
void push(Stack **top_ref, node *val);
node *pop(Stack **top_ref);

// function definitions
Stack* createStack(node* val) {
    Stack* newStack = (Stack*)malloc(sizeof(Stack));
    if (newStack == NULL) {
        printf("ERROR: Memory Could Not be Allocated.");
        exit(1);
    }
    newStack->data = val;
    newStack->next = NULL;
    return newStack;
}

int isEmpty(Stack *top_ref) {
    if(top_ref == NULL)
        return 1;
    else
        return 0;
}

void verti_print(Stack *top){
    if (isEmpty(top))
        printf("Empty Stack!!\n");
    else {
        printf("|%d| <- TOP\n", top->data->data);
        top = top->next;
        while (top != NULL){
            printf("|%d|\n", top->data->data);
            top = top->next;
        }
    }
}

void hori_print(Stack *top){
    if (isEmpty(top))
        printf("Empty Stack!!\n");
    else {
        while (top != NULL){
            printf("|%d| ", top->data);
            top = top->next;
        }
        printf("\n %c\nTOP\n", 24);
    }
}

void push(Stack **top_ref, node *val) { // insert at beginning
    Stack* newStack = createStack(val);
    if (isEmpty(*top_ref))
        *top_ref = newStack;
    else {
        newStack->next = *top_ref;
        *top_ref = newStack;
    }
}

node *pop(Stack **top_ref) { // delete from beginning
    if (isEmpty(*top_ref)) {
        printf("ERROR: STACK UNDERFLOW\n");
        exit(1);
    }
    else {
        node *del = (*top_ref)->data;
        Stack *temp = *top_ref;
        (*top_ref) = (*top_ref)->next;
        free(temp);
        return del;
    }
}