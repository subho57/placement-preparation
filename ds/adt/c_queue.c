#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

#define MAXSIZE 100
typedef int type;

typedef struct {
    int front;
    int rear;
    type Q[MAXSIZE];
}queue;

int isEmpty(queue *q) {
   return (q -> front == -1);
}

void enqueue(queue *q, type x) {
    if ((q -> front == q -> rear + 1) || (q -> front == 0 && q -> rear == MAXSIZE - 1))
        printf("Queue Overflows");
    else {
        if (q -> front == -1)
            q -> front = 0;
        q -> rear = (q -> rear + 1) % MAXSIZE;
        q -> Q[q -> rear] = x;
    }
}

type dequeue(queue *q) {
    type x = NULL;
    if (isEmpty(q)) {
        printf("Queue underflows");
        return NULL;
    }
    else {
        x = q -> Q[q -> front]; 
        if(q -> front == q -> rear)
            q -> rear = q -> front = -1;
        else
            q -> front = (q -> front + 1) % MAXSIZE; 
        return x;
    }
}

void init_queue(queue *q) {
    q -> front = -1;
    q -> rear = -1;
}

int main(void) {
    queue q;
    init_queue(&q);

    return 0;
}