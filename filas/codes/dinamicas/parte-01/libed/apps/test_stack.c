#include "stack.h"
#include <stdio.h>

int main() {
    Stack *S = Stack_create();
    int top_val;

    Stack_print(S);

    // puts("\npeeking");
    // top_val = Stack_peek(S);
    // printf("top_val = %d\n", top_val);

    // puts("\npopping");
    // top_val = Stack_pop(S);
    // printf("top_val = %d\n", top_val);

    puts("\npushing 0, 10, 20");
    Stack_push(S, 0);
    Stack_push(S, 10);
    Stack_push(S, 20);
    Stack_print(S);

    puts("\npeeking");
    top_val = Stack_peek(S);
    printf("top_val = %d\n", top_val);
    Stack_print(S);

    puts("\npopping");
    top_val = Stack_pop(S);
    printf("top_val = %d\n", top_val);
    Stack_print(S);

    puts("\npushing 20, 30, 40");
    Stack_push(S, 20);
    Stack_push(S, 30);
    Stack_push(S, 40);
    Stack_print(S);

    puts("\npushing 50");
    Stack_push(S, 50);
    Stack_print(S);

    Stack_destroy(&S);

    return 0;
}

