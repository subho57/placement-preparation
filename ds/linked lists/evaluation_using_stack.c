#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#define string char *

typedef struct Stack {
    float value;
    char operator;
    struct Stack* next;
}Stack;

Stack* createStack(char op, float val) {
    Stack* newStack = (Stack*)malloc(sizeof(Stack));
    if (newStack == NULL) {
        printf("ERROR: Memory Could Not be Allocated.");
        exit(1);
    }
    if (op == '\0')
        newStack->value = val;
    else
        newStack->operator = op;
    newStack->next = NULL;
    return newStack;
}

int isEmpty(Stack** head_ref) {
    if((*head_ref) == NULL)
        return 1;
    else
        return 0;
}

void push(Stack** head_ref, char op, float val) { // insert at beginning
    Stack* newStack = createStack(op, val);
    if (isEmpty(head_ref))
        *head_ref = newStack;
    else {
        newStack->next = (*head_ref);
        *head_ref = newStack;
    }
}

char pop_oper(Stack** head_ref) { // delete from beginning
    if (isEmpty(head_ref)) {
        printf("ERROR: STACK UNDERFLOW");
        exit(1);
    }
    else {
        char ch = (*head_ref)->operator;
        Stack *temp = *head_ref;
        *head_ref = (*head_ref)->next;
        free(temp);
        return ch;
    }
}

float pop_val(Stack** head_ref) { // delete from beginning
    if (isEmpty(head_ref)) {
        printf("ERROR: STACK UNDERFLOW");
        exit(1);
    }
    else {
        float ch = (*head_ref)->value;
        Stack *temp = *head_ref;
        *head_ref = (*head_ref)->next;
        free(temp);
        return ch;
    }
}

void print_opr(Stack** head_ref) {
    while (! isEmpty(head_ref)) {
        printf("%c -> ", (*head_ref)->operator);
        head_ref = &(*head_ref)->next;
    }
    printf("\n");
}

void print_val(Stack** head_ref) {
    while (! isEmpty(head_ref)) {
        printf("%f -> ", (*head_ref)->value);
        head_ref = &(*head_ref)->next;
    }
    printf("\n");
}

int main(void) {
    Stack *operators = NULL, *values = NULL;
    string exp = (string)malloc(sizeof(char));
    printf("Enter the expression: ");
    scanf("%[^\n]%*c", exp);
    for (int i = 0; i < strlen(exp); i++)
    {
        char ch = exp[i];
        if (ch == ')') {
            float last = pop_val(&values);
            float sec_last = pop_val(&values);
            char opr = pop_oper(&operators);
            if (opr == '+')
                push(&values, '\0', last + sec_last);
            else if (opr == '*')
                push(&values, '\0', last * sec_last);
            else if (opr == '-')
                push(&values, '\0', sec_last - last);
            else if (opr == '/')
                push(&values, '\0', sec_last / last);
        }
        else if (isdigit(ch)) {
            int val = (int)ch - 48;
            int j = i+1;
            while (isdigit(exp[j]) && j < strlen(exp))
                val = val * 10 + (int)exp[j++] - 48;
            i=j-1;
            push(&values, '\0', val);
        }
        else if (ch != ' ' && ch != '(')
            push(&operators, ch, 0);
    }
    printf("Result = %.2f\n", pop_val(&values));
    return 0;
}