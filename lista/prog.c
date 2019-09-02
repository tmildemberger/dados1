#include "lista.h"
#include <stdio.h>

int main() {
    Lista *l = cria();
    l = inserir(l, 1);
    l = inserir(l, 2);
    l = inserir(l, 4);
    l = inserir(l, 8);

    imprimir(l);

    l = remover(l, 2);
    imprimir(l);

    l = remover(l, 8);
    imprimir(l);

    l = remover(l, 1);
    imprimir(l);

    l = remover(l, 10);
    imprimir(l);

    destruir(l);
    return 0;
}
