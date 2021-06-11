#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdbool.h>
#include <stddef.h>

typedef struct _snode SNode;
typedef struct _linked_list LinkedList;

SNode *SNode_create(int val);

LinkedList *LinkedList_create();
void LinkedList_destroy(LinkedList **L_ref);
bool LinkedList_is_empty(const LinkedList *L);
void LinkedList_add_first(LinkedList *L, int val);
void LinkedList_add_last_slow(LinkedList *L, int val);
void LinkedList_add_last(LinkedList *L, int val);
void LinkedList_print(const LinkedList *L);

// remove o primeiro nó encontrado que possua o valor val
// essa funcao tem um teor mais 'didático', tratando cada
// caso separadamente
void LinkedList_remove_v1(LinkedList *L, int val);

// essa função é uma alternativa à anterior,
// funcionando para o mesmo propósito, mas
// sem tratar cada caso separadamente
void LinkedList_remove(LinkedList *L, int val);
size_t LinkedList_size_slow(const LinkedList *L);
size_t LinkedList_size(const LinkedList *L);

int LinkedList_first_val(const LinkedList *L);
int LinkedList_last_val(const LinkedList *L);
int LinkedList_get_val(const LinkedList *L, int index);


#endif
