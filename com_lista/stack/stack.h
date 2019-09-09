#ifndef STACK_H
#define STACK_H

typedef struct stack {
    int data;
    struct stack *next;
} Stack;

Stack* create_stack(void);
void free_stack(Stack *s);
Stack* push(Stack *s, int elem);
Stack* pop(Stack *s);
int top(Stack *s);
int empty_stack(Stack *s);

#endif // STACK_H
