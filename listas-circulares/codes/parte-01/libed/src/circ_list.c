#include "circ_list.h"

#include <stddef.h>

typedef struct _circ_node {
    int val;
    struct _circ_node *prev;
    struct _circ_node *next;
} CircNode;


typedef struct _circ_list {
    CircNode *begin;
    CircNode *end;
    size_t size;
} CircList;
