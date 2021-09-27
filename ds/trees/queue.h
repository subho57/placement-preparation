#ifndef QUEUE_H
#define QUEUE_H

typedef const char *string;
typedef struct TREEnode *data_type; // only change this line according to your program

typedef struct __node
{
    data_type data;
    struct __node *next;
} __node;

typedef struct queue
{
    __node *front;
    __node *rear;
    data_type (*peek)(struct queue *);
    int (*empty)(struct queue *);
    void (*enqueue)(struct queue *, data_type);
    data_type (*dequeue)(struct queue *);
} queue;

// function prototypes
void new_queue(queue *q);
__node *__create_node(data_type val);
data_type peek(queue *q);
int empty(queue *q);
void enqueue(queue *q, data_type val);
data_type dequeue(queue *q);

void new_queue(queue *q)
{
    q->front = q->rear = NULL;
    q->peek = peek;
    q->empty = empty;
    q->enqueue = enqueue;
    q->dequeue = dequeue;
}

__node *__create_node(data_type val)
{
    __node *__new_node = (__node *)malloc(sizeof(__node));
    if (__new_node == NULL)
    {
        printf("ERROR: Memory Could Not be Allocated.\n");
        exit(1);
    }
    __new_node->data = val;
    __new_node->next = NULL;
    return __new_node;
}

data_type peek(queue *q)
{
    return q->front->data;
}

int empty(queue *q)
{
    if (q->rear == NULL)
        return 1;
    else
        return 0;
}

// insert at the end
void enqueue(queue *q, data_type val)
{
    __node *new__node = __create_node(val);
    if (!empty(q))
        q->rear->next = new__node;
    q->rear = new__node;
    if (q->front == NULL)
        q->front = new__node;
}

// delete from beginning
data_type dequeue(queue *q)
{
    if (q->front == NULL)
        return 0;
    __node *del = q->front;
    data_type ret = del->data;
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    free(del);
    return ret;
}
#endif