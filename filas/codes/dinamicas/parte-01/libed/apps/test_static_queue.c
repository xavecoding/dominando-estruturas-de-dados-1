#include "static_queue.h"
#include <stdio.h>


int main() {
    StaticQueue *Q = StaticQueue_create(5);
    int val;

    StaticQueue_print(Q);

    // val = StaticQueue_peek(Q);
    // val = StaticQueue_dequeue(Q);

    puts("enqueue: 10, 20, 30");
    StaticQueue_enqueue(Q, 10);
    StaticQueue_enqueue(Q, 20);
    StaticQueue_enqueue(Q, 30);
    StaticQueue_print(Q);

    puts("\npeek");
    val = StaticQueue_peek(Q);
    printf("val = %d\n", val);
    StaticQueue_print(Q);

    puts("\ndequeue");
    val = StaticQueue_dequeue(Q);
    printf("val = %d\n", val);
    StaticQueue_print(Q);

    puts("\nenqueue: 40, 50");
    StaticQueue_enqueue(Q, 40);
    StaticQueue_enqueue(Q, 50);
    StaticQueue_print(Q);

    puts("\ndequeue");
    val = StaticQueue_dequeue(Q);
    printf("val = %d\n", val);
    StaticQueue_print(Q);

    puts("\nenqueue: 100, 200");
    StaticQueue_enqueue(Q, 100);
    StaticQueue_enqueue(Q, 200);
    StaticQueue_print(Q);

    // puts("\nenqueue: 99");
    // StaticQueue_enqueue(Q, 99);
    // StaticQueue_print(Q);

    StaticQueue_destroy(&Q);

    return 0;
}
