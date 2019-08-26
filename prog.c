#include <stdio.h>
#include "pilha.h"

int main() {
    int tam = 4;
    Pilha *p = create_stack(tam);
    push(p, 1);
    push(p, 2);
    push(p, 4);
    while (!empty_stack(p)) {
        printf("%d\n", pop(p));
    }
    destroy_stack(p);
    return 0;
}
