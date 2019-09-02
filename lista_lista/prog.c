#include "../lista/lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int conta_nos(Lista *l);
Lista* procurar(Lista *l, int elem);
Lista* separa(Lista *l, int elem);
Lista* cria_circular(Lista *l);

int main() {
    srand(time(NULL));
    int v = 0;
    Lista *l = cria();
    do {
        v = rand() % 14;
        l = inserir(l, v);
    } while (v != 7);
    // printf("O n de nos e %d\n\n", conta_nos(l));

    // printf("Lista antes da quebra:\n");
    // imprimir(l);

    // int num;
    // printf("Digite o elemento na separacao: ");
    // scanf("%d", &num);

    // Lista *l2 = separa(l, num);

    // printf("Lista 1 no final:\n");
    // imprimir(l);

    // printf("Lista 2 no final:\n");
    // imprimir(l2);

    // Lista *coiso = procurar(l, 22);
    // if (coiso) {
    //     printf("\nO 22 aparece na lista\n");
    // } else {
    //     printf("\nO 22 NAO aparece na lista\n");
    // }

    l = cria_circular(l);
    imprimir(l);

    destruir(l);
    // destruir(l2);
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

Lista* procurar(Lista *l, int elem) {
    while (l && l->info != elem) {
        l = l->next;
    }
    return l;
}

Lista* separa(Lista *l, int elem) {
    Lista *fim = procurar(l, elem);
    Lista *lista2 = fim->next;
    fim->next = NULL;
    return lista2;
}

Lista* cria_circular(Lista *l) {
    Lista *aux;
    for (aux = l; aux->next; aux = aux->next)
        ;
    aux->next = l;
    return l;
}
