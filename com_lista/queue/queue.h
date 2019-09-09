#ifndef QUEUE_H
#define QUEUE_H

typedef struct queue {
    int data;
    struct queue *next;
} Queue;

Queue* create_queue(void);
void free_queue(Queue *q);
Queue* enqueue(Queue *q, int elem);
Queue* dequeue(Queue *q);
int front(Queue *q);
int empty_queue(Queue *q);

#endif // QUEUE_H
