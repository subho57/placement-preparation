#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

typedef struct Stack{
    char ar[50];
    int top;
}stack;

void push(stack **s, char c) {
    if((**s).top == 50-1)
        printf("Stack overflows!!");
    else {
        (**s).top++;
        int t=(**s).top;
        (**s).ar[t]=c;
    }
}

char pop(stack** s)
{
    if((**s).top==-1)
    printf("\nStack underflows!!");
    else { 
        char p=(*s)->ar[(*s)->top];
        (**s).top--;
        return(p);
            
    }
}

int is_Operand(char c) {
    if(c=='+' || c=='-' || c=='/' || c=='*')
        return 0;
    else
        return 1;
     
}

int precedence(char c) {
    if(c=='+' || c=='-') 
        return 1;
    else if(c=='*' || c=='/')
        return 2;
    return 0;      
}

char *convert(char *infix, stack* s) {
    int l=strlen(infix);
    char* postfix=(char *)malloc((l+1)*sizeof(char));
    int i=0,j=0;
    while(infix[i]!='\0') {
        if (is_Operand(infix[i]))
            postfix[j++]=infix[i++];
        else {
            if(precedence(infix[i])>precedence(s->ar[s->top]))
                push(&s,infix[i++]);
            else
                postfix[j++]=pop(&s);
        }
    }
    while(s->top != 0)
        postfix[j++]=pop(&s);
    postfix[j]='\0';
    return postfix;
}

int main() {
    char infix[50];char *postfix;
    stack s1;
    s1.top=0;
    s1.ar[s1.top]='#';
    printf("Enter the string:\n");
    scanf("%s", infix);
    postfix = convert(infix, &s1);
    printf("\nThe postfix expression:%s", postfix);
    return 0;
}