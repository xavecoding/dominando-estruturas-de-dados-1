#include "circ_list.h"
#include <stdio.h>


int main() {
    CircList *L = CircList_create();

    puts("empty list");
    CircList_print(L);
    CircList_inverted_print(L);

    puts("remove 99");
    CircList_remove(L, 99);
    CircList_print(L);
    CircList_inverted_print(L);

    puts("adding last 10, 2, 7, 4, 5, 7");
    CircList_add_last(L, 10);
    CircList_add_last(L, 2);
    CircList_add_last(L, 7);
    CircList_add_last(L, 4);
    CircList_add_last(L, 5);
    CircList_add_last(L, 7);
    CircList_print(L);
    CircList_inverted_print(L);

    puts("remove 99");
    CircList_remove(L, 99);
    CircList_print(L);
    CircList_inverted_print(L);

    puts("remove 10");
    CircList_remove(L, 10);
    CircList_print(L);
    CircList_inverted_print(L);

    puts("remove 2");
    CircList_remove(L, 2);
    CircList_print(L);
    CircList_inverted_print(L);

    puts("remove 7");
    CircList_remove(L, 7);
    CircList_print(L);
    CircList_inverted_print(L);

    puts("remove 4");
    CircList_remove(L, 4);
    CircList_print(L);
    CircList_inverted_print(L);

    puts("remove 5");
    CircList_remove(L, 5);
    CircList_print(L);
    CircList_inverted_print(L);

    puts("remove 7");
    CircList_remove(L, 7);
    CircList_print(L);
    CircList_inverted_print(L);

    CircList_destroy(&L);

    return 0;
}
