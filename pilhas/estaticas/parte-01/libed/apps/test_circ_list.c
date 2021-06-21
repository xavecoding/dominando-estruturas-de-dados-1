#include "circ_list.h"
#include <stdio.h>


int main() {
    CircList *L = CircList_create();

    CircList_print(L);
    CircList_inverted_print(L);

    puts("Remove 99");
    CircList_remove(L, 99);
    CircList_print(L);
    CircList_inverted_print(L);

    puts("add_last 10, 7, 2, 4, 7");
    CircList_add_last(L, 10);
    CircList_add_last(L, 7);
    CircList_add_last(L, 2);
    CircList_add_last(L, 4);
    CircList_add_last(L, 7);
    CircList_print(L);
    CircList_inverted_print(L);

    puts("Remove 99");
    CircList_remove(L, 99);
    CircList_print(L);
    CircList_inverted_print(L);

    puts("Remove 7");
    CircList_remove(L, 7);
    CircList_print(L);
    CircList_inverted_print(L);

    puts("Remove 10");
    CircList_remove(L, 10);
    CircList_print(L);
    CircList_inverted_print(L);

    puts("Remove 4");
    CircList_remove(L, 4);
    CircList_print(L);
    CircList_inverted_print(L);

    puts("Remove 7");
    CircList_remove(L, 7);
    CircList_print(L);
    CircList_inverted_print(L);

    puts("Remove 2");
    CircList_remove(L, 2);
    CircList_print(L);
    CircList_inverted_print(L);

    CircList_destroy(&L);

    return 0;
}
