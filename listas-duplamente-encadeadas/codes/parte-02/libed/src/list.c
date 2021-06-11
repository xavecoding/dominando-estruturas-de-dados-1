#include "list.h"

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>


typedef struct _doubly_node {
    int val;
    struct _doubly_node *prev;
    struct _doubly_node *next;
} DoublyNode, Node;

typedef struct _doubly_linked_list {
    Node *begin;
    Node *end;
    size_t size;
} DoublyLinkedList, List;


Node *Node_create(int val) {
    Node *node = (Node*) calloc(1, sizeof(Node));
    node->prev = NULL;
    node->next = NULL;
    node->val = val;

    return node;
}

List *List_create() {
    List *L = (List*) calloc(1, sizeof(List));
    L->begin = NULL;
    L->end = NULL;
    L->size = 0;

    return L;
}


void List_destroy(List **L_ref) {
    List *L = *L_ref;

    Node *p = L->begin;
    Node *aux = NULL;

    while (p != NULL) {
        aux = p;
        p = p->next;
        free(aux);
    }
    free(L);

    *L_ref = NULL;
}
