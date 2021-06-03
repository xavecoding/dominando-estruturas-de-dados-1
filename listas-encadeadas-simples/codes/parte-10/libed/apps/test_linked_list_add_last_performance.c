#include "linked_list.h"
#include "mytime.h"


int main() {
    LinkedList *L_slow = LinkedList_create();
    timer t1, t2;

    t1 = tic();
    for (int i = 0; i < 200000; i++) {
        LinkedList_add_last_slow(L_slow, i);
    }
    t2 = tac();
    printf("Performance add_last_slow: %f ms\n", comptime(t1, t2));

    LinkedList *L_fast = LinkedList_create();

    t1 = tic();
    for (int i = 0; i < 200000; i++) {
        LinkedList_add_last(L_fast, i);
    }
    t2 = tac();
    printf("Performance add_last: %f ms\n", comptime(t1, t2));

    return 0;
}
