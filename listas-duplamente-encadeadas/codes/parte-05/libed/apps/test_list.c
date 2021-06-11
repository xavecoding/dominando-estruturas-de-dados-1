#include "list.h"
#include <stdio.h>


int main() {
    List *L = List_create();

    // List_add_first(L, 7);
    // List_add_first(L, 4);
    // List_add_first(L, 2);
    // List_add_first(L, 10);
    // List_print(L);
    // List_inverted_print(L);

    // puts("List_add_last");
    // List_add_last(L, 10);
    // List_add_last(L, 2);
    // List_add_last(L, 4);
    // List_add_last(L, 7);
    // List_print(L);
    // List_inverted_print(L);

    puts("testing add_last and add_first");
    List_add_last(L, 4);
    List_add_last(L, 7);
    List_add_first(L, 2);
    List_add_first(L, 10);
    List_print(L);
    List_inverted_print(L);


    List_destroy(&L);

    return 0;
}
