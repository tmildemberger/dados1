#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../pilha/pilha.h"

/*Desculpe a bagunça*/

/* Exercício 2
int bem_formada(const char *seq);
*/

void posfixa(const char *expr);

int main() {
    /* Exercício 1
    int tam = 10;
    Pilha *p = create_stack(tam);
    push(p, 'P');
    push(p, 'E');
    push(p, 'R');
    push(p, 'T');
    push(p, 'O');
    printf("%c ", pop(p));
    printf("%c ", pop(p));
    push(p, 'S');
    push(p, 'O');
    push(p, 'L');
    printf("%c ", pop(p));
    printf("%c ", pop(p));
    printf("%c\n", pop(p));
    printf("Letra d\n");*/

    /* Exercício 2
    char seq[80];
    scanf("%s", seq);
    if (bem_formada(seq)) printf("Bem formada\n");
    else printf("Mal formada\n");*/

    /* Exercício 3*/
    char seq[80];
    scanf("%s", seq);
    posfixa(seq);

    return 0;
}
/* Exercício 2
int bem_formada(const char *seq) {
    int tam = strlen(seq);
    Pilha *p = create_stack(tam);
    while (*seq) {
        if (*seq == '(' || *seq == '[') {
            push(p, *seq);
        } else if (*seq == ')') {
            if (empty_stack(p) || pop(p) != '(') {
                destroy_stack(p);
                return 0;
            }
        } else if (*seq == ']') {
            if (empty_stack(p) || pop(p) != '[') {
                destroy_stack(p);
                return 0;
            }
        }
        ++seq;
    }
    return empty_stack(p);
}
*/

/* Exercício 3*/
void posfixa(const char *expr) {
    int tam = strlen(expr); //espaço de sobra
    Pilha *p = create_stack(tam);
    while (*expr) {
        if (*expr >= '0' && *expr <= '9') {
            while (*expr && *expr >= '0' && *expr <= '9') {
                printf("%c", *expr++);
            }
            printf(" ");
        } else if (*expr == '+' || *expr == '-' || *expr == '*' || *expr == '/') {
            push(p, *expr++);
        } else if (*expr == ')') {
            printf("%c ", pop(p));
            expr++;
        } else {
            expr++;
        }
    }
    printf("\n");
}
