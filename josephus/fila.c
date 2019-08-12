#include "fila.h"

#include <stdio.h>
#include <stdlib.h>

Fila* create_queue(int tam) {
    Fila *f = (Fila *) malloc(sizeof (Fila));
    f->ini = 0;
    f->fim = 0;
    f->tam = tam;
    f->vetor = (int *) malloc(sizeof (int) * tam);
    return f;
}

void destroy_queue(Fila *f) {
    free(f->vetor);
    free(f);
}

void enqueue(Fila *f, int elem) {
    if (full_queue(f)) {
        printf("Fila cheia!!!\n");
        exit(1);
    }
    f->vetor[f->fim] = elem;
    f->fim = (f->fim + 1) % f->tam;
}

int dequeue(Fila *f) {
    if (empty_queue(f)) {
        printf("Fila vazia!!!\n");
        exit(1);
    }
    int elem = f->vetor[f->ini];
    f->ini = (f->ini + 1) % f->tam;
    return elem;
}

int empty_queue(Fila *f) {
    return f->ini == f->fim;
}

int full_queue(Fila *f) {
    return ((f->fim + 1) % f->tam) == f->ini;
}
