#ifndef LIST_H
#define LIST_H

#include <stdbool.h>

typedef struct _doubly_node DoublyNode, Node;
typedef struct _doubly_linked_list DoublyLinkedList, List;

Node *Node_create(int val);

List *List_create();
void List_destroy(List **L_ref);
bool List_is_empty(const List *L);
void List_add_first(List *L, int val);
void List_add_last(List *L, int val);
void List_print(const List *L);
void List_inverted_print(const List *L);

// remove o primeiro nó encontrado que possua o valor val
// essa funcao tem um teor mais 'didático', tratando cada
// caso separadamente
void List_remove_v1(List *L, int val);

// essa função é uma alternativa à anterior,
// funcionando para o mesmo propósito, mas
// sem tratar cada caso separadamente
void List_remove(List *L, int val);

#endif
