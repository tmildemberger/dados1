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
    for (i = 0; i < n - 1; ++i) {
        int j;
        for (j = 0; j < m; ++j) {
            enqueue(f, dequeue(f));
        }
    }
    return 0;
}
