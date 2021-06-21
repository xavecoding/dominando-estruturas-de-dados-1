#include "stack.h"
#include "list.h"

#include <stdlib.h>
#include <stdio.h>


typedef struct _stack {
    List *data;
} Stack;



Stack *Stack_create() {
    Stack *S = (Stack*) calloc(1, sizeof(Stack));
    S->data = List_create();

    return S;
}


void Stack_destroy(Stack **S_ref) {
    Stack *S = *S_ref;

    List_destroy(&S->data);
    free(S);

    *S_ref = NULL;
}
