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


bool Stack_is_empty(const Stack *S) {
    return List_is_empty(S->data);
}


size_t Stack_size(const Stack *S) {
    return List_size(S->data);
}


void Stack_push(Stack *S, int val) {
    List_add_last(S->data, val);
}


int Stack_peek(const Stack *S) {
    if (Stack_is_empty(S)) {
        fprintf(stderr, "ERROR in 'Stack_peek'\n");
        fprintf(stderr, "A pilha está vazia\n");
        exit(EXIT_FAILURE); // termina o programa com um código de erro
        // EXIT_FAILURE ==> stdlib.h
    }

    return List_get_last_val(S->data);
}
