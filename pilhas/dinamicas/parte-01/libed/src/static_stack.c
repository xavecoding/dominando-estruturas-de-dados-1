#include "static_stack.h"

#include <stdlib.h>
#include <stdio.h>


typedef struct _static_stack {
    int *data;
    long capacity;
    long top;
} StaticStack;


StaticStack *StaticStack_create(long capacity) {
    StaticStack *S = (StaticStack*) calloc(1, sizeof(StaticStack));

    S->capacity = capacity;
    S->top = -1;
    S->data = (int*) calloc(S->capacity, sizeof(int));

    return S;
}

void StaticStack_destroy(StaticStack **S_ref) {
    StaticStack *S = *S_ref;

    free(S->data);
    free(S);

    *S_ref = NULL;
}


bool StaticStack_is_empty(const StaticStack *S) {
    return S->top == -1;
}


bool StaticStack_is_full(const StaticStack *S) {
    return S->top == (S->capacity - 1);
}

long StaticStack_size(const StaticStack *S) {
    return S->top + 1;
}


void StaticStack_push(StaticStack *S, int val) {
    if (StaticStack_is_full(S)) {
        fprintf(stderr, "ERROR in 'StaticStack_push'\n");
        fprintf(stderr, "A pilha está cheia\n");
        exit(EXIT_FAILURE); // termina o programa com um código de erro
        // EXIT_FAILURE ==> stdlib.h
    }

    S->top++;
    S->data[S->top] = val;
}

int StaticStack_peek(const StaticStack *S) {
    if (StaticStack_is_empty(S)) {
        fprintf(stderr, "ERROR in 'StaticStack_peek'\n");
        fprintf(stderr, "A pilha está vazia\n");
        exit(EXIT_FAILURE); // termina o programa com um código de erro
        // EXIT_FAILURE ==> stdlib.h
    }

    return S->data[S->top];
}


int StaticStack_pop(StaticStack *S) {
    if (StaticStack_is_empty(S)) {
        fprintf(stderr, "ERROR in 'StaticStack_pop'\n");
        fprintf(stderr, "A pilha está vazia\n");
        exit(EXIT_FAILURE); // termina o programa com um código de erro
        // EXIT_FAILURE ==> stdlib.h
    }

    int val = S->data[S->top];
    S->top--;

    return val;
}


void StaticStack_print(const StaticStack *S) {
    printf("capacity: %ld\n", S->capacity);
    printf("top: %ld\n", S->top);

    for (long i = 0; i <= S->top; i++) {
        printf("%d, ", S->data[i]);
    }
    puts("");
}
