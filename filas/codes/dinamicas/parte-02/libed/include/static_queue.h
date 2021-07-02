#ifndef STATIC_QUEUE_H
#define STATIC_QUEUE_H

#include <stdbool.h>

typedef struct _static_queue StaticQueue;

StaticQueue *StaticQueue_create(long capacity);
void StaticQueue_destroy(StaticQueue **Q_ref);

bool StaticQueue_is_empty(const StaticQueue *Q);
bool StaticQueue_is_full(const StaticQueue *Q);
long StaticQueue_size(const StaticQueue *Q);

void StaticQueue_enqueue(StaticQueue *Q, int val);
int StaticQueue_peek(const StaticQueue *Q);
int StaticQueue_dequeue(StaticQueue *Q);

void StaticQueue_print(const StaticQueue *Q);

#endif
