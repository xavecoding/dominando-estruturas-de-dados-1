#include "linked_list.h"
#include <stdio.h>

int main() {
    LinkedList *L = LinkedList_create();

    LinkedList_add_last(L, 10);
    LinkedList_add_last(L, 2);
    LinkedList_add_last(L, 4);
    LinkedList_add_last(L, 5);
    LinkedList_add_last(L, 7);
    LinkedList_print(L);

    printf("==> Size: %lu\n", LinkedList_size(L));

    LinkedList_destroy(&L);

    return 0;
}
