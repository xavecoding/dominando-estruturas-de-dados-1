#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


typedef struct _livro {
    char titulo[100];
    unsigned int num_paginas;
    float preco;
} Livro;



typedef struct _aluno {
    char nome[100];
    int idade;
    Livro *livro_fav;
} Aluno;



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



Aluno *create_aluno(const char *nome, int idade,
                    const Livro *livro_fav) {
    Aluno *aluno = (Aluno *) calloc(1, sizeof(Aluno));

    strcpy(aluno->nome, nome);
    aluno->idade = idade;
    aluno->livro_fav = copy_livro(livro_fav);

    return aluno;
}


void destroy_aluno(Aluno **aluno_ref) {
    Aluno *aluno = *aluno_ref;

    destroy_livro(&aluno->livro_fav);
    free(aluno);
    *aluno_ref = NULL;
}


void print_aluno(const Aluno *aluno) {
    printf("Nome: %s\n", aluno->nome);
    printf("Idade: %d\n", aluno->idade);
    puts("Livro Favorito");
    puts("-----");
    print_livro(aluno->livro_fav);
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
    Livro *livro_harry = create_livro("Harry Potter 1",
                                200, 25);

    print_livro(livro_harry);
    livro_harry->preco = 10;
    print_livro(livro_harry);

    Aluno *ted = create_aluno("Ted", 20, livro_harry);
    print_aluno(ted);

    // os exemplares sao iguais?
    // os exemplares sao iguais?
    puts("\nted->livro_fav == livro_harry");
    puts("os exemplares sao iguais?");
    if (ted->livro_fav == livro_harry) {
        puts("TRUE");
    }
    else {
        puts("FALSE");
    }
    puts("\n");


    // a obra é a mesmar
    puts("\nlivros_sao_iguais");
    puts("a obra é a mesma ?");
    if (livros_sao_iguais(ted->livro_fav, livro_harry)) {
        puts("TRUE");
    }
    else {
        puts("FALSE");
    }
    puts("\n");

    destroy_livro(&livro_harry);

    print_aluno(ted);

    destroy_aluno(&ted);

    return 0;
}