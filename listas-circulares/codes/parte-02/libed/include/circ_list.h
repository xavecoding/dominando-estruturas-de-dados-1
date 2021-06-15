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

#endif
