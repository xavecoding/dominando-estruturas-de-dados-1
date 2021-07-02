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
