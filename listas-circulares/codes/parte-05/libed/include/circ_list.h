#ifndef CIRC_LIST_H
#define CIRC_LIST_H

#include <stdbool.h>

typedef struct _circ_node CircNode;
typedef struct _circ_list CircList;

CircNode *CircNode_create(int val);
void CircNode_destroy(CircNode **cnode_ref);

CircList *CircList_create();
void CircList_destroy(CircList **L_ref);
void CircList_destroy_v2(CircList **L_ref);
bool CircList_is_empty(const CircList *L);
void CircList_add_first(CircList *L, int val);
void CircList_add_last(CircList *L, int val);

void CircList_print(const CircList *L);
void CircList_print_v2(const CircList *L);
void CircList_inverted_print(const CircList *L);
void CircList_inverted_print_v2(const CircList *L);

#endif
