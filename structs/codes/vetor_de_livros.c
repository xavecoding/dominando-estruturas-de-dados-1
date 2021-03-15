#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


typedef struct _livro {
    char titulo[100];
    unsigned int num_paginas;
    float preco;
} Livro;


typedef struct _vetor_livros {
    Livro **vet;
    int n_elems;  // numero de elementos
} VetorLivros;


// "construtor" para livros
Livro *create_livro(const char *titulo, unsigned int num_paginas,
                    float preco) {
    Livro *livro = (Livro *) calloc(1, sizeof(Livro));

    strcpy(livro->titulo, titulo);
    livro->num_paginas = num_paginas;
    livro->preco = preco;

    return livro;
}


void destroy_livro(Livro **livro_ref) {
    Livro *livro = *livro_ref;
    free(livro);
    *livro_ref = NULL;
}


Livro *copy_livro(const Livro *livro) {
    return create_livro(livro->titulo, livro->num_paginas,
                        livro->preco);
}



void print_livro(const Livro *livro) {
    printf("Titulo: %s\n", livro->titulo);
    printf("Num Paginas: %d\n", livro->num_paginas);
    printf("Preco: R$ %.2f\n\n", livro->preco);
}


bool livros_sao_iguais(const Livro *livro_1,
                       const Livro *livro_2) {
    if (strcmp(livro_1->titulo, livro_2->titulo) == 0) {
        return true;
    }
    else {
        return false;
    }
}



int main() {
    Livro **vet = (Livro **) calloc(3, sizeof(Livro *));
    vet[0] = create_livro("Harry Potter 1", 200, 25);
    vet[1] = create_livro("A Batalha do Apocalipse", 600, 40);
    vet[2] = create_livro("O Senhor dos Anéis", 500, 15);

    for (int i = 0; i < 3; i++) {
        print_livro(vet[i]);
    }
  

    // destroy vetor
    for (int i = 0; i < 3; i++) {
        destroy_livro(&vet[i]);
    }
    free(vet);
    vet = NULL;

    return 0;
}