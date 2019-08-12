#include <stdio.h>
#include "fila.h"

int main() {
    int tam = 5;
    Fila *f1 = create_queue(tam + 1);
    int i, pot2 = 1;
    for (i = 0; i < tam; ++i) {
        enqueue(f1, pot2);
        pot2 *= 2;
    }
    while (!empty_queue(f1)) {
        printf("%d ", dequeue(f1));
    }
    printf("\n");
    destroy_queue(f1);
    return 0;
}
