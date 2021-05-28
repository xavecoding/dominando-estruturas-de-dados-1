#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _livro
{
    char titulo[100];
    float preco;
    int n_paginas;
} Livro;

Livro *CriaLivro(const char *titulo, float preco, int n_paginas)
{
    Livro *livro = (Livro *)calloc(1, sizeof(Livro));

    strcpy(livro->titulo, titulo);
    livro->preco = preco;
    livro->n_paginas = n_paginas;

    return livro;
}

int main() {
    Livro livro1 = {.titulo = "Harry Potter 1", 30.0, 250};
    Livro *livro2 = CriaLivro("O Segredis de Cacilds", 10.0, 100);

    // printf("titulo1: %s\n", livro1.titulo);
    // printf("titulo1: %s\n", livro1->titulo);
    // printf("titulo1: %s\n", &livro1->titulo);
    // printf("titulo1: %s\n", (&livro1)->titulo);

    // printf("titulo2: %s\n", livro2.titulo);
    // printf("titulo2: %s\n", livro2->titulo);
    // printf("titulo2: %s\n", *livro2->titulo);
    // printf("titulo2: %s\n", (*livro2)->titulo);

    // printf("titulo2: %s\n", livro2[0].titulo);

    return 0;
}
