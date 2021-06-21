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

    printf("First: %d\n", LinkedList_first_val(L));
    printf("Last: %d\n", LinkedList_last_val(L));
    printf("Get [0]: %d\n", LinkedList_get_val(L, 0));
    printf("Get [3]: %d\n", LinkedList_get_val(L, 3));

    LinkedList_destroy(&L);

    return 0;
}
