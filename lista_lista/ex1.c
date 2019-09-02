#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int conta_nos(Lista *l);

int main() {
    srand(time(NULL));
    int v = 0;
    Lista *l = cria();
    do {
        v = rand() % 14;
        l = inserir(l, v);
    } while (v != 7);

    printf("O numero de nos e %d\n", conta_nos(l));

    printf("\nLista para conferir:\n");
    imprimir(l);

    destruir(l);
    return 0;
}

int conta_nos(Lista *l) {
    int tam = 0;
    while (l) {
        ++tam;
        l = l->next;
    }
    return tam;
}
