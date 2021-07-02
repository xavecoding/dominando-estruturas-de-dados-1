#include "static_queue.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct _static_queue {
    int *data;
    long capacity;
    long size;
    long begin;
    long end;
} StaticQueue;


StaticQueue *StaticQueue_create(long capacity) {
    StaticQueue *Q = (StaticQueue*) calloc(1, sizeof(StaticQueue));

    Q->data = (int*) calloc(capacity, sizeof(int));
    Q->capacity = capacity;
    Q->size = 0;
    Q->begin = 0;
    Q->end = 0;

    return Q;
}


void StaticQueue_destroy(StaticQueue **Q_ref) {
    StaticQueue *Q = *Q_ref;

    free(Q->data);
    free(Q);

    *Q_ref = NULL;
}

bool StaticQueue_is_empty(const StaticQueue *Q) {
    return Q->size == 0;
}


bool StaticQueue_is_full(const StaticQueue *Q) {
    return Q->size == Q->capacity;
}

long StaticQueue_size(const StaticQueue *Q) {
    return Q->size;
}

