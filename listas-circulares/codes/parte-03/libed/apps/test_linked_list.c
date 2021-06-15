#include "linked_list.h"
#include <stdio.h>

int main() {
    LinkedList *L = LinkedList_create();

    LinkedList_print(L);
    LinkedList_remove(L, 99);
    LinkedList_print(L);

    LinkedList_add_first(L, 10);
    LinkedList_print(L);
    puts("Removendo 10");
    LinkedList_remove(L, 10);
    LinkedList_print(L);

    LinkedList_add_last(L, 10);
    LinkedList_add_last(L, 2);
    LinkedList_add_last(L, 4);
    LinkedList_print(L);
    puts("Removendo 10");
    LinkedList_remove(L, 10);
    LinkedList_print(L);
    puts("Removendo 2");
    LinkedList_remove(L, 2);
    LinkedList_print(L);
    puts("Removendo 4");
    LinkedList_remove(L, 4);
    LinkedList_print(L);

    LinkedList_add_last(L, 10);
    LinkedList_add_last(L, 2);
    LinkedList_add_last(L, 4);
    LinkedList_add_last(L, 5);
    LinkedList_add_last(L, 7);
    LinkedList_print(L);
    puts("Removendo 2");
    LinkedList_remove(L, 2);
    LinkedList_print(L);
    puts("Removendo 4");
    LinkedList_remove(L, 4);
    LinkedList_print(L);

    puts("Removendo 7");
    LinkedList_remove(L, 7);
    LinkedList_print(L);

    puts("Removendo 99");
    LinkedList_remove(L, 99);
    LinkedList_print(L);

    LinkedList_add_last(L, 4);
    LinkedList_add_last(L, 5);
    LinkedList_add_last(L, 7);
    LinkedList_print(L);
    puts("Removendo 5");
    LinkedList_remove(L, 5);
    LinkedList_print(L);

    LinkedList_destroy(&L);

    return 0;
}
