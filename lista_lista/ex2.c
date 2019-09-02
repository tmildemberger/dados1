#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

Lista* procurar(Lista *l, int elem);

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

    int num;
    printf("Digite um numero: ");
    scanf("%d", &num);

    Lista *achei = procurar(l, num);
    if (achei) {
        printf("O %d aparece na lista\n", num);
    } else {
        printf("O %d NAO aparece na lista\n", num);
    }

    destruir(l);
    return 0;
}

Lista* procurar(Lista *l, int elem) {
    while (l && l->info != elem) {
        l = l->next;
    }
    return l;
}
