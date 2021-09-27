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
    if (top == MAXSIZE) {
        printf("error: stack overflow!\n");
        exit(1);
    }
    else
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

// Driver method
int main(void) {
    type arr[MAXSIZE];
    top = 0;
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
        type n;
        switch (choice) {
            case 1:
                printf("Enter an element: ");
                scanf("\n%c", &n);
                push(arr, n);
                break;
            case 2:
                n = pop(arr);
                printf("%c has been popped!\n", n);
                break;
            case 3:
                print(arr);
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