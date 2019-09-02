#include "lista.h"
#include <stdlib.h>
#include <stdio.h>

Lista* cria(void) {
    return NULL;
}

Lista* inserir(Lista *l, int elem) {
    No *novo = (No *) malloc(sizeof (No));
    novo->info = elem;
    novo->next = l;
    return novo;
}

Lista* remover(Lista *l, int elem) {
    Lista *prev = NULL;
    Lista *aux = l;
    while (aux && aux->info != elem) {
        prev = aux;
        aux = aux->next;
    }
    if (aux == NULL) {
        return l;
    }
    if (prev == NULL) {
        l = l->next;
    } else {
        prev->next = aux->next;
    }
    free(aux);
    return l;
}

void imprimir(Lista *l) {
    Lista *i;
    for (i = l; i != NULL; i = i->next) {
        printf("%d\n", i->info);
    }
}

void destruir(Lista *l) {
    Lista *aux;
    while (l != NULL) {
        aux = l->next;
        free(l);
        l = aux;
    }
}
