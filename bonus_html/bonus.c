#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

int html_ok(const char *html_filename);

int main(int argc, char *argv[]) {
    if (argc == 2) {
        printf("%s\n", html_ok(argv[1]) ? "LEGAL" : "NAOLEGAL");
    } else {
        printf("%s\n", html_ok("amostras/boatA.html") ? "LEGAL" : "NAOLEGAL");
    }
    return 0;
}

int html_ok(const char *html_filename) {
    Stack *stack = create_stack();
    FILE *f = fopen(html_filename, "r");
    char str[128];
    while (fgets(str, sizeof str, f)) {
        // printf("%s", str);
        const char *s = str;
        while (*s) {
            if (*s == '<') {
                if (1[s] != '/') {
                    const char *fim = s;
                    while (*fim != '>') ++fim;
                    char *tag = malloc(sizeof (char) * (fim - s++));
                    char *tag_i = tag;
                    while (s != fim) {
                        *(tag_i++) = *(s++);
                    }
                    *tag_i = '\0';
                    stack = push(stack, tag);
                    printf("pushed %s\n", tag);
                    s = fim;
                } else {
                    ++s;
                    ++s;
                    const char *fim = s;
                    while (*fim != '>') ++fim;
                    // char *tag = malloc(sizeof (char) * (fim - s++));
                    // char *tag_i;
                    char *start = top(stack);
                    while (s != fim) {
                        if (*(start++) != *(s++)) {
                            return 0;
                        }
                    }
                    free(top(stack));
                    stack = pop(stack);
                    s = fim;
                    // *tag_i = '\0';

                }
            }
            ++s;
        }
    }
    return empty_stack(stack);
    // if (feof(f)) printf("OK\n");
    // return 1;
}
