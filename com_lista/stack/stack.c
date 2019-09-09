#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

Stack* create_stack(void) {
    return NULL;
}

void free_stack(Stack *s) {
    Stack *aux = NULL;
    while (s != NULL) {
        aux = s->next;
        free(s);
        s = aux;
    }
}

Stack* push(Stack *s, int elem) {
    Stack *new_s = (Stack*) malloc(sizeof (Stack));
    new_s->next = s;
    new_s->data = elem;
    return new_s;
}

Stack* pop(Stack *s) {
    if (empty_stack(s)) {
        printf("Pilha vazia!\n");
        exit(1);
    }
    Stack *ret = s->next;
    free(s);
    return ret;
}

int top(Stack *s) {
    if (empty_stack(s)) {
        printf("Pilha vazia!\n");
        exit(1);
    }
    return s->data;
}

int empty_stack(Stack *s) {
    return s == NULL;
}
