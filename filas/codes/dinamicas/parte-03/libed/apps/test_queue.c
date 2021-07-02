#include "queue.h"
#include <stdio.h>


int main() {
    Queue *Q = Queue_create();
    int val;

    Queue_print(Q);

    puts("enqueue: 10");
    Queue_enqueue(Q, 10);
    Queue_print(Q);

    puts("\ndequeue");
    val = Queue_dequeue(Q);
    printf("val = %d\n", val);
    Queue_print(Q);

    // val = Queue_peek(Q);
    // val = Queue_dequeue(Q);

    puts("enqueue: 10, 20, 30");
    Queue_enqueue(Q, 10);
    Queue_enqueue(Q, 20);
    Queue_enqueue(Q, 30);
    Queue_print(Q);

    puts("\npeek");
    val = Queue_peek(Q);
    printf("val = %d\n", val);
    Queue_print(Q);

    puts("\ndequeue");
    val = Queue_dequeue(Q);
    printf("val = %d\n", val);
    Queue_print(Q);

    puts("\nenqueue: 40, 50");
    Queue_enqueue(Q, 40);
    Queue_enqueue(Q, 50);
    Queue_print(Q);

    puts("\ndequeue");
    val = Queue_dequeue(Q);
    printf("val = %d\n", val);
    Queue_print(Q);

    puts("\nenqueue: 100, 200");
    Queue_enqueue(Q, 100);
    Queue_enqueue(Q, 200);
    Queue_print(Q);

    Queue_destroy(&Q);

    return 0;
}
