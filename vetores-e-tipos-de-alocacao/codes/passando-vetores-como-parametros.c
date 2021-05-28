#include <stdio.h>
#include <stdlib.h> // contém o NULL, calloc, malloc, free


void soma_vetor_com_escalar(int v[], int n, int escalar) {
    for (int i = 0; i < n; i++) {
        v[i] += escalar;
    }
}


void print_vetor(const int *v, int n) {
    for (int i = 0; i < n; i++) {
        printf("&v[%d] = %p, v[%d] = %d\n", i, &v[i], i, v[i]);
        // v[i]++; // v[i] + 1 == *(v + i) + 1
    }
    puts("");
}


void desaloca_vetor(int **v) {
    int *aux = *v;
    free(aux);
    *v = NULL;
}


int main() {
    // alocacao de um vetor estático (memória Stack)
    puts("### VETOR ESTATICO");
    int vs[5] = {0, 10, 20, 30, 40};

    print_vetor(vs, 5);
    soma_vetor_com_escalar(vs, 5, 9);
    print_vetor(vs, 5);

    puts("### VETOR DINAMICO COM CALLOC");
    int *vh = (int *) calloc(5, sizeof(int));
    for (int i = 0; i < 5; i++) {
        vh[i] = i * 100;
    }

    print_vetor(vh, 5);
    soma_vetor_com_escalar(vh, 5, 9);
    print_vetor(vh, 5);


    // desalocando o vetor dinâmico
    // free(vh);
    // vh = NULL;
    puts("==> ANTES DA FUNCAO DE DESALOCAR VETOR DINAMICO");
    printf("&vh = %p, vh = %p\n", &vh, vh);
    desaloca_vetor(&vh);
    puts("==> DEPOIS DA FUNCAO DE DESALOCAR VETOR DINAMICO");
    printf("&vh = %p, vh = %p\n", &vh, vh);

    return 0;
}

