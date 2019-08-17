#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Uso: %s m n\n", argv[0]);
        return 1;
    }
    int m = atoi(argv[1]);
    int n = atoi(argv[2]);

    Fila *f = create_queue(n + 1);
    int i;
    for (i = 1; i <= n; ++i) {
        enqueue(f, i);
    }
    while (!empty_queue(f)) {
        int j;
        for (j = 1; j < m; ++j) {
            enqueue(f, dequeue(f));
        }
        printf("%d ", dequeue(f));
    }
    printf("\n");
    destroy_queue(f);
    return 0;
}
