#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 10000

// typedefs
typedef char * string;
typedef char type;

// setting the rear as zero
int rear = 0;
int front = 0;
type queue[MAXSIZE];

// function prototypes
void enqueue(type n);
type dequeue();
int isEmpty();
void print();
type peek();

int isEmpty() {
    if (rear == front) return 1;
    else return 0;
}

void enqueue(type n) {
    if (rear == MAXSIZE) {
        printf("error: queue overflow!\n");
        exit(1);
    }
    else
        queue[rear++] = n;
}

type dequeue() {
    if (isEmpty()) {
        printf("error: queue underflow!\n");
        exit(1);
    }
    else
        return queue[front++];
}

type peek() {
    if (isEmpty()) {
        printf("empty list.\n");
        return -1;
    }
    return queue[front];
}

void print() {
    if (isEmpty()) {
        printf("empty list.\n");
        return;
    }
    printf("Printing the Queue:\n");
    for(int i = front; i < rear; i++) {
        printf("%c ", queue[i]);
    }
    printf("\n");
}

// Driver method
int main(void) {
    while (1) {
        printf("\n********************MENU*********************\n");
        printf("* Press:                                    *\n");
        printf("* 1) To Enqueue an Element in the Queue.    *\n");
        printf("* 2) To Dequeue an Element from the Queue.  *\n");
        printf("* 3) To Peek the front element in the Queue.*\n");
        printf("* 4) To Display the Queue.                  *\n");
        printf("* 5) To Exit the Program.                   *\n");
        printf("*********************************************\n");
        int choice;
        printf("Enter your Choice: ");
        scanf("%d", &choice);
        type n;
        switch (choice) {
            case 1:
                printf("Enter an element: ");
                scanf("\n%c", &n);
                enqueue(n);
                break;
            case 2:
                n = dequeue();
                printf("%c has been dequeued!\n", n);
                break;
            case 3:
                n = peek();
                if (n != -1)
                    printf("%c is at the front.\n", n);
                break;
            case 4:
                print();
                break;
            case 5:
                printf("Exiting Program...");
                exit(0);
                break;
            default:
                printf("Wrong Choice!! Try Again.");
        }
    }
    return 0;
}