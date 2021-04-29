#include "mytime.h"


/* funcão que marca o tempo atual ("tic" do relógio)
   deve ser usada para marcar o início do trecho que queremos medir de tempo */
timer tic() {
    timer tic_;
    gettimeofday(&tic_, NULL); // "marca" o tempo atual
    return tic_;
}

/* faz a mesma coisa que a função tic, mas que deve ser usada
   para marcar o final do trecho que queremos medir o tempo.
   Apenas uma forma semântica de sabermos que faz o "tac" do relógio */
timer tac() {
    return tic();
}

/**
 * Computa o tempo entre um tic tac;
 */
float comptime(timer tic, timer tac) {
  float t = ((tac.tv_sec  - tic.tv_sec) * 1000.0) +
            ((tac.tv_usec - tic.tv_usec) * 0.001);
  
  return t;
}