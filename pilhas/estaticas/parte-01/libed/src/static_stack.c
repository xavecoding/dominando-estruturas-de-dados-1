#include "static_stack.h"

#include <stdlib.h>
#include <stdio.h>


typedef struct _static_stack {
    int *data;
    size_t capacity;
    int top;
} StaticStack;


StaticStack *StaticStack_create(size_t capacity) {
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
