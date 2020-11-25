#include <stdio.h>
#include <stdlib.h>

typedef struct Stack{
    int data;
    struct Stack* next;
}Stack;

Stack* createStack(int val) {
    Stack* newStack = (Stack*)malloc(sizeof(Stack));
    if (newStack == NULL) {
        printf("ERROR: Memory Could Not be Allocated.");
        exit(1);
    }
    newStack->data = val;
    newStack->next = NULL;
    return newStack;
}

int isEmpty(Stack** top_ref) {
    if((*top_ref) == NULL)
        return 1;
    else
        return 0;
}

void verti_print(Stack *top){
    if (isEmpty(&top))
        printf("Empty Stack!!\n");
    else {
        printf("|%d| <- TOP\n", top->data);
        top = top->next;
        while (top != NULL){
            printf("|%d|\n", top->data);
            top = top->next;
        }
    }
}

void hori_print(Stack *top){
    if (isEmpty(&top))
        printf("Empty Stack!!\n");
    else {
        while (top != NULL){
            printf("|%d| ", top->data);
            top = top->next;
        }
        printf("\n %c\nTOP\n", 24);
    }
}

void push(Stack** top_ref, int val) { // insert at beginning
    Stack* newStack = createStack(val);
    if (isEmpty(top_ref))
        *top_ref = newStack;
    else {
        newStack->next = (*top_ref);
        *top_ref = newStack;
    }
}

int pop(Stack** top_ref) { // delete from beginning
    if (isEmpty(top_ref)) {
        printf("ERROR: STACK UNDERFLOW\n");
        exit(1);
    }
    else {
        int del = (*top_ref)->data;
        Stack *temp = *top_ref;
        (*top_ref) = (*top_ref)->next;
        free(temp);
        return del;
    }
}

int main(void) {
    Stack *top = NULL;
    while (1) {
        printf("\n********************MENU*********************\n");
        printf("* Press:                                    *\n");
        printf("* 1) To Push an Element in the Stack.       *\n");
        printf("* 2) To Pop an Element from the Stack.      *\n");
        printf("* 3) To Display the Stack.                  *\n");
        printf("* 4) To Exit the Program.                   *\n");
        printf("*********************************************\n");
        int choice;
        printf("Enter your Choice: ");
        scanf("%d", &choice);
        int n;
        switch (choice) {
            case 1:
                printf("Enter an element: ");
                scanf("%d", &n);
                push(&top, n);
                break;
            case 2:
                n = pop(&top);
                printf("%d has been popped!\n", n);
                break;
            case 3:
                printf("Printing the Stack...\n");
                verti_print(top);
                break;
            case 4:
                printf("Exiting Program...");
                exit(0);
                break;
            default:
                printf("Wrong Choice!! Try Again.");
        }
    }
    return 0;
}