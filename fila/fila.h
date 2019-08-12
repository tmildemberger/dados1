#ifndef FILA_H
#define FILA_H

typedef struct fila {
    int ini;
    int fim;
    int tam;
    int *vetor;
} Fila;

Fila* create_queue(int tam);
void destroy_queue(Fila *f);
void enqueue(Fila *f, int elem);
int dequeue(Fila *f);
int empty_queue(Fila *f);
int full_queue(Fila *f);

#endif // FILA_H
