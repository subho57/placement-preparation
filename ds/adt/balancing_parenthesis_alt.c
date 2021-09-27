// Program for Balancing Parenthesis using stack 

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAXSIZE 50

// typdefs
typedef char * string; // to use string in the program

// creating a Stack type structure to facilitate the use of multiple stacks in the program
typedef struct Stack {
    char ar[MAXSIZE];
    int top;
}stack;

// inserts an element at the top of the stack
void push(stack* s, int n, char c) {
    if(s -> top == (MAXSIZE - 1))
        printf("Stack overflow!!\n");
    else {
        s -> top++;
        int t = s -> top;
        s -> ar[t] = c;
    }
}

// checks whether there is a mismatch or not
// returns true if mismatch found
bool check_pair(char a, char b) {
    if (a == '(' && b == ')')
        return false;
    else if (a == '[' && b == ']')
        return false;
    else if (a == '{' && b == '}')
        return false;
    else
        return true;
}

// deletes an element from the top of the stack
void pop(stack* s) {
    if(s -> top == -1)
        printf("Stack underflow!!\n");
    else
        s -> top--;
}

// driver function
int main(void) {
    stack s1;
    s1.top = -1;

    // takes the bracket expression as user input
    string exp = (string)malloc(sizeof(char));
    printf("Enter the parenthesis expression: ");
    scanf("%[^\n]%*c", exp);

    int n = strlen(exp); // stores the length of the string

    for(int i = 0; i < n; i++)
    {        
        char c = exp[i]; // parses each character from the already inserted string
        if (c == '(' || c == '{' || c == '[')
            push(&s1, n, c);
        else if (c == ')' || c == '}' || c == ']')
        {
            if (s1.top == -1 || check_pair(s1.ar[s1.top], c))
            {
                printf("Unbalanced parenthesis!!\n");
                free(exp); // freeing the string
                return 0; // terminating the program here only, no need of flag variable
            }
            else
                pop(&s1);
        }
    }
    // checks if stack is empty or not
    if (s1.top == -1) // if empty then balanced else not
        printf("Balanced parenthesis!!\n");
    else
        printf("Unbalanced parenthesis!!\n");
    free(exp); // freeing the string
    return 0;
}