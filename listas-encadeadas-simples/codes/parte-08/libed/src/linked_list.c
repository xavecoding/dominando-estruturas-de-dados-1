#include "linked_list.h"
#include <stdlib.h>
#include <stdio.h>


typedef struct _snode {
    int val;
    struct _snode *next;
} SNode;


typedef struct _linked_list {
    SNode *begin;
    SNode *end;
} LinkedList;



SNode *SNode_create(int val) {
    SNode *snode = (SNode*) calloc(1, sizeof(SNode));
    snode->val = val;
    snode->next = NULL;

    return snode;
}



LinkedList *LinkedList_create() {
    LinkedList *L = (LinkedList *) calloc(1, sizeof(LinkedList));
    L->begin = NULL;
    L->end = NULL;

    return L;
}

bool LinkedList_is_empty(const LinkedList *L) {
    return (L->begin == NULL && L->end == NULL);
}


// void LinkedList_add_first(LinkedList *L, int val) {
//     SNode *p = SNode_create(val);
//     p->next = L->begin;
//     L->begin = p;
// }

void LinkedList_add_first(LinkedList *L, int val) {
    SNode *p = SNode_create(val);
    p->next = L->begin;
    
    if (LinkedList_is_empty(L)) {
        L->end = p;
    }
    
    L->begin = p;
}

void LinkedList_add_last_slow(LinkedList *L, int val) {
    SNode *q = SNode_create(val);
    
    // se a lista estiver vazia
    if (LinkedList_is_empty(L)) {
        L->begin = q;
    }
    else {
        SNode *p = L->begin;

        // enquanto o p não é o último nó, ou seja,
        // enquanto houver um próximo nó
        while (p->next != NULL) {
            p = p->next;
        }
        // neste momento, o ponteiro p aponta para
        // o nó final da Lista

        // corrige o encadeamento, ou seja,
        // faz com que o próximo elemento do atual
        // último nó aponte para o novo último nó
        p->next = q;
    }
}

void LinkedList_add_last(LinkedList *L, int val) {
    SNode *q = SNode_create(val);

    // se a lista estiver vazia
    if (LinkedList_is_empty(L)) {
        L->begin = q;
        L->end = q;
    }
    else {
        L->end->next = q;
        L->end = L->end->next;
    }
}

void LinkedList_print(const LinkedList *L) {
    SNode *p = L->begin;

    printf("L -> ");

    // enquanto p não chegou ao fim da lista, isto é,
    // enquanto p estiver apontando para um nó da lista
    while (p != NULL) {
        printf("%d -> ", p->val);
        p = p->next;
    }
    printf("NULL\n");
}
