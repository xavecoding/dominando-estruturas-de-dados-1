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

    if (L->end == NULL) {
        printf("L->end = NULL\n");
    }
    else {
        printf("L->end = %d\n", L->end->val);
    }
    puts("");
}

void LinkedList_remove_v1(LinkedList *L, int val) {
    if (!LinkedList_is_empty(L)) {
        // caso 1 - o elemento está na cabeça da lista
        if (L->begin->val == val) {
            SNode *pos = L->begin;

            // a lista possui apenas um nó,
            // e este nó será removido
            if (L->begin == L->end) {
                L->end = NULL;
            }

            L->begin = L->begin->next;
            free(pos);
        }
        // caso 2 - o elemento está no meio da lista
        // caso 3 - o elemento está no final da lista
        else {
            SNode *prev = L->begin;
            SNode *pos = L->begin->next;

            // enquanto a lista ainda tiver elementos
            // para percorrer/checar e
            // o valor do nó apontado pelo ponteiro pos
            // for diferente do valor desejado,
            // avance os ponteiros auxiliares (prev e pos)
            // para os próximos nós da lista
            while (pos != NULL && pos->val != val) {
                prev = prev->next;
                pos = pos->next;
            }

            // um nó de valor val foi encontrado e
            // é apontado pelo ponteiro pos
            if (pos != NULL) {
                prev->next = pos->next;

                // se o elemento a ser removido é
                // o último nó da lista
                //
                // caso 3 - removendo o último nó da lista
                if (pos->next == NULL) {
                    L->end = prev;
                }
                
                free(pos);
            }
        }
    }
}


void LinkedList_remove(LinkedList *L, int val) {
    if (!LinkedList_is_empty(L)) {
        SNode *prev = NULL;
        SNode *pos = L->begin;

        while (pos != NULL && pos->val != val) {
            prev = pos;
            pos = pos->next;
        }

        // se achou um nó com valor val
        if (pos != NULL) {
            if (L->end == pos) {
                L->end = prev;
            }
            if (L->begin == pos) {
                L->begin = L->begin->next;
            }
            else {
                prev->next = pos->next;
            }

            free(pos);
        }
    }
}
