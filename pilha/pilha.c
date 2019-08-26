#include "pilha.h"
#include <stdlib.h>

Pilha* create_stack(int tam) {
    Pilha *p = (Pilha*) malloc(sizeof (Pilha));
    p->topo = 0;
    p->tam = tam;
    p->vetor = (int*) malloc(sizeof (int) * tam);
    return p;
}

void destroy_stack(Pilha *p) {
    free(p->vetor);
    free(p);
}

void push(Pilha *p, int elem) {
    if (full_stack(p)) {
        printf("Pilha cheia!!\n");
        exit(1);
    }
    p->vetor[p->topo] = elem;
    ++p->topo;
}

int pop(Pilha *p) {
    if (empty_stack(p)) {
        printf("Pilha vazia!!\n");
        exit(1);
    }
    --p->topo;
    return p->vetor[p->topo];
}

int empty_stack(Pilha *p) {
    return p->topo == 0;
}

int full_stack(Pilha *p) {
    return p->topo == p->tam;
}
