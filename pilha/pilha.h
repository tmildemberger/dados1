#ifndef PILHA_C
#define PILHA_C

typedef struct pilha {
    int topo;
    int tam;
    int *vetor;
} Pilha;

Pilha* create_stack(int tam);
void destroy_stack(Pilha *p);
void push(Pilha *p, int elem);
int pop(Pilha *p);
int empty_stack(Pilha *p);
int full_stack(Pilha *p);

#endif // PILHA_C
