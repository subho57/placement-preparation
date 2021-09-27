#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 100

// #define stack_type(x) (typedef x type)

// typedefs
typedef char * string;
typedef char type;

// setting the top as zero
int top = 0;

// function prototypes
void push(type arr[], type n);
type pop(type arr[]);
int isEmpty(int top);
void print(type arr[]);

int isEmpty(int top) {
    if (top == 0) return 1;
    else return 0;
}

void push(type arr[], type n) {
    arr[top++] = n;
}

type pop(type arr[]) {
    if (isEmpty(top)) {
        printf("error: stack underflow!\n");
        exit(1);
    }
    else
        return arr[--top];
}

void print(type arr[]) {
    if (isEmpty(top)) {
        printf("empty list.\n");
        return;
    }
    printf("Printing the Stack:\n");
    for(int i = 0; i < top; i++) {
        printf("%c ", arr[i]);
    }
    printf("\n");
}