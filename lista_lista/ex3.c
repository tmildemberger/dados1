#include "../lista/lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

Lista* procurar(Lista *l, int elem);
Lista* separa(Lista *l, int elem);

int main() {
    srand(time(NULL));
    int v = 0;
    Lista *l = cria();
    do {
        v = rand() % 14;
        l = inserir(l, v);
    } while (v != 7);

    printf("Lista antes da quebra:\n");
    imprimir(l);

    int num;
    printf("Digite o elemento na separacao: ");
    scanf("%d", &num);

    Lista *l2 = separa(l, num);

    printf("Lista 1 no final:\n");
    imprimir(l);

    printf("Lista 2 no final:\n");
    imprimir(l2);

    destruir(l);
    destruir(l2);
    return 0;
}
Lista* procurar(Lista *l, int elem) {
    while (l && l->info != elem) {
        l = l->next;
    }
    return l;
}

Lista* separa(Lista *l, int elem) {
    Lista *fim = procurar(l, elem);
    if (fim) { // lista inicial vazia ou elemento não encontrado
        Lista *lista2 = fim->next;
        fim->next = NULL;
        return lista2;
    } else {
        return NULL;
    }
}
