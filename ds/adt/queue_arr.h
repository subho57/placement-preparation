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