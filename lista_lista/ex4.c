#include "../lista/lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

Lista* cria_circular(Lista *l);

int main() {
    srand(time(NULL));
    int v = 0;
    Lista *l = cria();
    do {
        v = rand() % 14;
        l = inserir(l, v);
    } while (v != 7);

    printf("Lista para conferir:\n");
    imprimir(l);

    l = cria_circular(l);
    imprimir(l);

    destruir(l);
    return 0;
}


Lista* cria_circular(Lista *l) {
    Lista *aux;
    for (aux = l; aux->next; aux = aux->next)
        ;
    aux->next = l;
    return l;
}
