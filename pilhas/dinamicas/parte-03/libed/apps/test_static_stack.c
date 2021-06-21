#include "static_stack.h"
#include <stdio.h>

int main() {
    StaticStack *S = StaticStack_create(5);
    int top_val;

    StaticStack_print(S);

    // puts("\npeeking");
    // top_val = StaticStack_peek(S);
    // printf("top_val = %d\n", top_val);

    // puts("\npopping");
    // top_val = StaticStack_pop(S);
    // printf("top_val = %d\n", top_val);

    puts("\npushing 0, 10, 20");
    StaticStack_push(S, 0);
    StaticStack_push(S, 10);
    StaticStack_push(S, 20);
    StaticStack_print(S);

    puts("\npeeking");
    top_val = StaticStack_peek(S);
    printf("top_val = %d\n", top_val);
    StaticStack_print(S);

    puts("\npopping");
    top_val = StaticStack_pop(S);
    printf("top_val = %d\n", top_val);
    StaticStack_print(S);

    puts("\npushing 20, 30, 40");
    StaticStack_push(S, 20);
    StaticStack_push(S, 30);
    StaticStack_push(S, 40);
    StaticStack_print(S);

    // puts("\npushing 50");
    // StaticStack_push(S, 50);
    // StaticStack_print(S);

    StaticStack_destroy(&S);

    return 0;
}

