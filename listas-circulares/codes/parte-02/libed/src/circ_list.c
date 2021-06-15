#include "circ_list.h"

#include <stdio.h>
#include <stdlib.h>
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


CircNode *CircNode_create(int val) {
    CircNode *cnode = (CircNode*) calloc(1, sizeof(CircNode)); 
    cnode->val = val;
    cnode->prev = cnode;
    cnode->next = cnode;

    return cnode;
}

void CircNode_destroy(CircNode **cnode_ref) {
    CircNode *cnode = *cnode_ref;
    free(cnode);
    *cnode_ref = NULL;
}


CircList *CircList_create() {
    CircList *L = (CircList*) calloc(1, sizeof(CircList));
    L->begin = NULL;
    L->end = NULL;
    L->size = 0;

    return L;
}


void CircList_destroy(CircList **L_ref) {
    CircList *L = *L_ref;

    CircNode *p = L->begin;
    CircNode *aux = NULL;

    while (p != L->end) {
        aux = p;
        p = p->next;
        CircNode_destroy(&aux);
    }
    CircNode_destroy(&p);

    free(L);
    *L_ref = NULL;
}

void CircList_destroy_v2(CircList **L_ref) {
    CircList *L = *L_ref;

    CircNode *p = L->begin;
    CircNode *aux = NULL;

    for (int i = 0; i < L->size; i++) {
        aux = p;
        p = p->next;
        CircNode_destroy(&aux);
    }

    free(L);
    *L_ref = NULL;
}

bool CircList_is_empty(const CircList *L) {
    return L->size == 0;
}
