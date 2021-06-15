#include "circ_list.h"
#include <stdio.h>


int main() {
    CircList *L = CircList_create();

    CircList_print(L);
    CircList_print_v2(L);
    CircList_inverted_print(L);
    CircList_inverted_print_v2(L);

    puts("adding");
    CircList_add_first(L, 7);
    CircList_add_first(L, 5);
    CircList_add_first(L, 4);
    CircList_add_first(L, 2);
    CircList_add_first(L, 10);
    CircList_print(L);
    CircList_print_v2(L);
    CircList_inverted_print(L);
    CircList_inverted_print_v2(L);

    CircList_destroy(&L);

    return 0;
}
