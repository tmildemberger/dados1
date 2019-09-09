#ifndef STACK_H
#define STACK_H

typedef struct stack {
    char* data;
    struct stack *next;
} Stack;

Stack* create_stack(void);
void free_stack(Stack *s);
Stack* push(Stack *s, char* elem);
Stack* pop(Stack *s);
char* top(Stack *s);
int empty_stack(Stack *s);

#endif // STACK_H
