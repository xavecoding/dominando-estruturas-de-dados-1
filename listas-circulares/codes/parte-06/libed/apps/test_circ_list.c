#include "circ_list.h"
#include <stdio.h>


int main() {
    CircList *L = CircList_create();

    CircList_print(L);
    CircList_inverted_print(L);

    puts("adding last");
    CircList_add_last(L, 10);
    CircList_add_last(L, 2);
    CircList_add_last(L, 4);
    CircList_add_last(L, 5);
    CircList_add_last(L, 7);
    CircList_print(L);
    CircList_inverted_print(L);

    puts("adding first");
    CircList_add_first(L, 99);
    CircList_print(L);
    CircList_inverted_print(L);

    CircList_destroy(&L);

    return 0;
}
