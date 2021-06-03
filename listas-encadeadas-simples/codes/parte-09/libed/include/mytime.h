#ifndef MY_TIME_H
#define MY_TIME_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

// medindo tempo em C (Linux/Mac)
// para windows, veja http://professor.ufabc.edu.br/~daniel.martin/ED/tempo.html
typedef struct timeval timer; // adicionando um novo nome para o tipo struct timeval (apenas para facilitar)


/* funcão que marca o tempo atual ("tic" do relógio)
   deve ser usada para marcar o início do trecho que queremos medir de tempo */
timer tic();

/* faz a mesma coisa que a função tic, mas que deve ser usada
   para marcar o final do trecho que queremos medir o tempo.
   Apenas uma forma semântica de sabermos que faz o "tac" do relógio */
timer tac();


/**
 * Computa o tempo entre um tic tac (em ms);
 */
float comptime(timer tic, timer tac);

#endif
