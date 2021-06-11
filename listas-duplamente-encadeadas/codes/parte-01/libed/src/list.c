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
