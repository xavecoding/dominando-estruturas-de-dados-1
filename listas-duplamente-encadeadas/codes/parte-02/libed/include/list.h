#ifndef LIST_H
#define LIST_H

typedef struct _doubly_node DoublyNode, Node;
typedef struct _doubly_linked_list DoublyLinkedList, List;

Node *Node_create(int val);

List *List_create();
void List_destroy(List **L_ref);

#endif
