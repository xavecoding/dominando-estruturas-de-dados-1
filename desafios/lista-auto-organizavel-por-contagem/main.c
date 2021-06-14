#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


typedef struct _product {
    int serial;
    char name[64];
    float price;
} Product;


typedef struct _node {
    struct _node *prev;
    struct _node *next;
    int count;
    Product *product;
} Node;


typedef struct _list {
    Node *begin;
    Node *end;
    size_t size;
    int total_cost;
} List;






Product *Product_create(int serial, const char *name, float price) {
    Product *product = (Product*) calloc(1, sizeof(Product));

    product->serial = serial;
    strcpy(product->name, name);
    product->price = price;

    return product;
}


void Product_destroy(Product **product_ref) {
    Product *product = *product_ref;
    free(product);
    *product_ref = NULL;
}

Node *Node_create(int serial, const char *name, float price) {
    Node *node = (Node*) calloc(1, sizeof(Node));
    node->prev = node->next = NULL;
    node->count = 0;
    node->product = Product_create(serial, name, price);

    return node;
}


void Node_destroy(Node **node_ref) {
    Node *node = *node_ref;
    Product_destroy(&node->product);
    free(node);
    *node_ref = NULL;
}


List *List_create() {
    List *L = (List*) calloc(1, sizeof(List));
    L->begin = L->end = NULL;
    L->size = 0;
    L->total_cost = 0;

    return L;
}


void List_destroy(List **L_ref) {
    List *L = *L_ref;

    Node *p = L->begin;
    Node *aux = NULL;

    while (p != NULL) {
        aux = p;
        p = p->next;
        Node_destroy(&aux);
    }
    free(L);

    *L_ref = NULL;
}

bool List_is_empty(const List *L) {
    return L->size == 0;
}


void List_add_last(List *L, int serial,
                   const char *name, float price) {
    Node *p = Node_create(serial, name, price);
    p->prev = L->end;

    if (List_is_empty(L)) {
        L->begin = p;
    }
    else {
        L->end->next = p;
    }
    
    L->end = p;
    L->size++;
}

void List_print(const List *L) {
    Node *p = L->begin;

    printf("L -> ");

    // enquanto p não chegou ao fim da lista, isto é,
    // enquanto p estiver apontando para um nó da lista
    while (p != NULL) {
        printf("%d (%d) -> ", p->product->serial, p->count);
        p = p->next;
    }
    printf("NULL\n");

    if (L->end == NULL) {
        printf("L->end = NULL\n");
    }
    else {
        printf("L->end = %d (%d)\n", L->end->product->serial, L->end->count);
    }
    
    printf("Size: %lu\n", L->size);
    puts("");
}

void List_inverted_print(const List *L) {
    Node *p = L->end;

    printf("L->end -> ");

    // enquanto p não chegou ao fim da lista, isto é,
    // enquanto p estiver apontando para um nó da lista
    while (p != NULL) {
        printf("%d (%d) -> ", p->product->serial, p->count);
        p = p->prev;
    }
    printf("NULL\n");

    if (L->end == NULL) {
        printf("L->begin = NULL\n");
    }
    else {
        printf("L->begin = %d (%d)\n", L->begin->product->serial, L->begin->count);
    }
    
    printf("Size: %lu\n", L->size);
    puts("");
}


// retorna um ponteiro read-only para o produto encontrado,
// ou retorna NULL caso contrário
const Product *List_acessa(List *L, int serial) {
    Product *product = NULL;

    if (!List_is_empty(L)) {
        Node *p = L->begin;
        int cost = 1;

        while (p != NULL && p->product->serial != serial) {
            cost++;
            p = p->next;
        }

        // achamos o produto com o número de série serial
        if (p != NULL) {
            L->total_cost += cost;
            p->count++;  // aumenta a frequência de acessos do produto/nó
            product = p->product;

            // reorganizar a lista
            if (L->begin != p) {
                Node *q = p->prev;

                // enquanto há um nó q antecessor a p
                // e enquanto a frequência de acessos
                // de q é menor ou igual a p, troque
                // p por q
                while (q != NULL && q->count <= p->count) {
                    p->prev = q->prev;
                    q->prev = p;
                    q->next = p->next;
                    p->next = q;
                    
                    // o nó p virou a cabeça da lista
                    if (p->prev == NULL) {
                        L->begin = p;
                    }
                    else {
                        p->prev->next = p;
                    }

                    // o nó q virou a cauda da lista
                    if (q->next == NULL) {
                        L->end = q;
                    }
                    else {
                        q->next->prev = q;
                    }

                    q = p->prev;
                }
            }
        }
    }

    return product;
}


void List_print_serial(const List *L) {
    Node *p = L->begin;

    printf("L = (");

    while (p != NULL) {
        printf("%d", p->product->serial);

        if (p != L->end) {
            printf(", ");
        }

        p = p->next;
    }

    printf(")\n");
    printf("Custo total = %d\n", L->total_cost);
}



int main() {
    List *L = List_create();

    char cmd[12];

    scanf("%s", cmd);

    // a função strcmp retorna zero se as strings forem IGUAIS
    // caso contrário, ela retorna um número diferente de zero
    while (strcmp(cmd, "para") != 0) {
        // se o comando for "add"
        if (strcmp(cmd, "add") == 0) {
            int serial;
            char name[64];
            float price;
            scanf("%d %s %f", &serial, name, &price);
            List_add_last(L, serial, name, price);
            // List_print(L);
            // List_inverted_print(L);
        }
        // se o comando for "acessa"
        else if (strcmp(cmd, "acessa") == 0) {
            int serial;
            scanf("%d", &serial);

            // impressão do produto acessado
            const Product *product = List_acessa(L, serial);

            if (product == NULL) {
                printf("Produto %d inexistente\n", serial);
            }
            else {
                printf("%d, %s, %.2f\n", product->serial,
                                         product->name,
                                         product->price);
            }
            // List_print(L);
            // List_inverted_print(L);
        }

        scanf("%s", cmd);
    }

    // impressao final da lista
    printf("\n");
    List_print_serial(L);

    List_destroy(&L);

    return 0;
}
