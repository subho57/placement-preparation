#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include "stack_arr.h"

#define new(type) (type*)malloc(strlen(exp)*sizeof(type));

double pre_eval(string exp) {
    double *stack = new(double);
    for (int i = strlen(exp)-1; i >= 0; i--) {
        char ch = exp[i];
        if (isdigit(ch)) {
            int j;
            for (j = i - 1; isdigit(exp[j]) && j >= 0; j--);
            char number[100];
            for (int k = j; k <= i; k++)
                number[k-j] = exp[k];
            long op = atol(number);
            push(stack, op);
            i = j + 1; 
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {
            double op1 = pop(stack);
            double op2 = pop(stack);
            switch (ch)
            {
            case '+':
                op1 += op2;
                break;
            case '-':
                op1 -= op2;
                break;
            case '*':
                op1 *= op2;
                break;
            case '/':
                op1 /= op2;
                break;
            case '^':
                op1 = pow(op1, op2);
                break;
            }
            push(stack, op1);
        }
        else if (ch == ' ')
            continue;
        else {
            printf("Invalid PREFIX Expression.\n");
            exit(1);
        }
    }
    double res = pop(stack);
    if (isEmpty(top))
        return res;
    else {
        printf("Invalid PREFIX Expression.\n");
        exit(1);
    }
}

double post_eval(string exp) {
    double *stack = new(double);
    for (int i = 0; i < strlen(exp); i++) {
        char ch = exp[i];
        if (isdigit(ch)) {
            double op = ch - 48;
            int j;
            for (j = i + 1; isdigit(exp[j]) && j < strlen(exp); j++)
                op = op*10 + exp[j] - 48;
            i = j - 1;
            push(stack, op);
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {
            double op1 = pop(stack);
            double op2 = pop(stack);
            switch (ch)
            {
            case '+':
                op2 += op1;
                break;
            case '-':
                op2 -= op1;
                break;
            case '*':
                op2 *= op1;
                break;
            case '/':
                op2 /= op1;
                break;
            case '^':
                op2 = pow(op1, op2);
                break;
            }
            push(stack, op2);
        }
        else if (ch == ' ')
            continue;
        else {
            printf("Invalid POSTFIX Expression.\n");
            exit(1);
        }
    }
    double res = pop(stack);
    if (isEmpty(top))
        return res;
    else {
        printf("Invalid POSTFIX Expression.\n");
        exit(1);
    }
}

int main(void) {
    string exp = (string)malloc(sizeof(char));
    printf("Enter the Expression: ");
    scanf("%[^\n]%*c", exp);
    double res;
    if (isdigit(exp[0])) {
        printf("POSTFIX Expression Detected!\n");
        res = post_eval(exp);
    }
    else {
        printf("PREFIX Expression Detected!\n");
        res = pre_eval(exp);
    }
    printf("Result = %.2f\n", res);
    return 0;
}