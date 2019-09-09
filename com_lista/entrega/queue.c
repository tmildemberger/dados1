#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

Queue* create_queue(void) {
    return NULL;
}

void free_queue(Queue *q) {
    Queue *aux = NULL;
    while (q != NULL) {
        aux = q->next;
        free(q);
        q = aux;
    }
}

Queue* enqueue(Queue *q, int elem) {
    Queue *new_q = (Queue*) malloc(sizeof (Queue));
    new_q->next = NULL;
    new_q->data = elem;
    Queue *head = q;
    if (q == NULL) {
        return new_q;
    }
    while (q->next != NULL) {
        q = q->next;
    }
    q->next = new_q;
    return head;
}

Queue* dequeue(Queue *q) {
    if (empty_queue(q)) {
        printf("Fila vazia!\n");
        exit(1);
    }
    Queue *ret = q->next;
    free(q);
    return ret;
}

int front(Queue *q) {
    if (empty_queue(q)) {
        printf("Fila vazia!\n");
        exit(1);
    }
    return q->data;
}

int empty_queue(Queue *q) {
    return q == NULL;
}
