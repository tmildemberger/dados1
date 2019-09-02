#ifndef LISTA_H
#define LISTA_H

typedef struct no {
    int info;
    struct no *next;
} No, Lista;

Lista* cria(void);
Lista* inserir(Lista *l, int elem);
Lista* remover(Lista *l, int elem);
void imprimir(Lista *l);
void destruir(Lista *l);

#endif // LISTA_H
