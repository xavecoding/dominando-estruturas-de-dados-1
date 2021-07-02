#include "queue.h"
#include "list.h"

#include <stdio.h>
#include <stdlib.h>


typedef struct _queue {
    List *data;
} Queue;


Queue *Queue_create() {
    Queue *Q = (Queue*) calloc(1, sizeof(Queue));
    Q->data = List_create();
    return Q;
}

void Queue_destroy(Queue **Q_ref) {
    Queue *Q = *Q_ref;
    List_destroy(&Q->data);
    free(Q);
    *Q_ref = NULL;
}


bool Queue_is_empty(const Queue *Q) {
    return List_is_empty(Q->data);
}


long Queue_size(const Queue *Q) {
    return List_size(Q->data);
}


void Queue_enqueue(Queue *Q, int val) {
    List_add_last(Q->data, val);
}

int Queue_peek(const Queue *Q) {
    if (Queue_is_empty(Q)) {
        fprintf(stderr, "ERROR in 'Queue_peek'\n");
        fprintf(stderr, "A fila está vazia\n");
        exit(EXIT_FAILURE); // termina o programa com um código de erro
        // EXIT_FAILURE ==> stdlib.h
    }

    return List_get_first_val(Q->data);
}


int Queue_dequeue(Queue *Q) {
    if (Queue_is_empty(Q)) {
        fprintf(stderr, "ERROR in 'Queue_dequeue'\n");
        fprintf(stderr, "A fila está vazia\n");
        exit(EXIT_FAILURE); // termina o programa com um código de erro
        // EXIT_FAILURE ==> stdlib.h
    }

    int val = List_get_first_val(Q->data);
    List_remove_first(Q->data);
    
    return val;
}


void Queue_print(const Queue *Q) {
    List_print(Q->data);
}
