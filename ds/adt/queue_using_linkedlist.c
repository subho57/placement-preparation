#include <stdio.h>
#include <stdlib.h>

typedef struct Queue {
    int data;
    struct Queue* next;
    struct Queue* prev;
}Queue;

Queue* createQueue(int val) {
    Queue* newQueue = (Queue*)malloc(sizeof(Queue));
    if (newQueue == NULL) {
        printf("ERROR: Memory Could Not be Allocated.");
        exit(1);
    }
    newQueue->data = val;
    newQueue->next = NULL;
    newQueue->prev = NULL;
    return newQueue;
}

int isEmpty(Queue** front_ref) {
    if((*front_ref) == NULL)
        return 1;
    else
        return 0;
}

void print(Queue *front){
    if (isEmpty(&front))
        printf("Empty Queue!!\n");
    else {
        printf("|%d| <- FRONT", front->data);
        front = front->next;
        if(front == NULL)
            printf(" <- REAR\n");
        else {
            printf("\n");
            while (front->next != NULL){
                printf("|%d|\n", front->data);
                front = front->next;
            }
            printf("|%d| <- REAR\n", front->data);
        }
    }
}

void enqueue(Queue** front_ref, Queue** rear_ref, int val) { // insert at beginning
    Queue* newQueue = createQueue(val);
    if (isEmpty(front_ref))
        *front_ref = *rear_ref = newQueue;
    else {
        newQueue->next = (*front_ref);
        (*front_ref)->prev = newQueue;
        *front_ref = newQueue;
    }
}

int dequeue(Queue **front_ref, Queue** rear_ref) { // delete from end
    if (isEmpty(rear_ref)) {
        printf("ERROR: Queue UNDERFLOW!!\n");
        exit(1);
    }
    else {
        int del = (*rear_ref) -> data;
        if ((*rear_ref)->prev != NULL) {
            (*rear_ref) = (*rear_ref) -> prev;
            free((*rear_ref)->next);
            (*rear_ref)->next = NULL;
        }
        else {
            free((*rear_ref));
            *front_ref = *rear_ref = NULL;
        }
        return del;
    }
}

//Driver Method
int main(void) {
    Queue *front = NULL, *rear = NULL;
    while (1) {
        printf("\n********************MENU*********************\n");
        printf("* Press:                                    *\n");
        printf("* 1) To Enqueue an Element in the Queue.    *\n");
        printf("* 2) To Dequeue an Element from the Queue.  *\n");
        printf("* 3) To Display the Queue.                  *\n");
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
                enqueue(&front, &rear, n);
                break;
            case 2:
                n = dequeue(&front, &rear);
                printf("%d has been popped!\n", n);
                break;
            case 3:
                printf("Printing the Queue...\n");
                print(front);
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