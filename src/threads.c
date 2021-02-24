#include <math.h>
#include <pthread.h>
#include "threads.h"
#include "calc_math.h"
#include <stdio.h>


typedef struct {
   float a;
   float h;
   float* v;
   int inicio;
   int fim;
} InfoParaCalc;


void* calc_trapezios_t(void* struct_info) {
    InfoParaCalc info = *((InfoParaCalc*) struct_info);

    for (int i = info.inicio; i < info.fim; ++i) {
        float x_i = info.a + i * info.h;
        info.v[i] = f2(x_i);
    }

    pthread_exit(NULL);
}


void calc_trapezios_via_threads(int numero_threads, int numero_trapezios, float a, float h, float* v) {
    int qtd_trapezios_por_thead = ceil((float) numero_trapezios/numero_threads);
    int qtd_trapezios_calculados = 0;
    int i = 0;
    pthread_t ids[numero_threads];
    InfoParaCalc infos[numero_threads + 1];


    while (qtd_trapezios_calculados < numero_trapezios) {
        // printf("%d %d\n", i, numero_threads + 1);
        int qtd_trapezios_vez_anterior = qtd_trapezios_calculados;
        qtd_trapezios_calculados += qtd_trapezios_por_thead;

        infos[i].a = a;
        infos[i].h = h;
        infos[i].v = v;
        infos[i].inicio = qtd_trapezios_vez_anterior;
        infos[i].fim = (qtd_trapezios_calculados > numero_trapezios) ?
                       qtd_trapezios_calculados - (qtd_trapezios_calculados - numero_trapezios) :
                       qtd_trapezios_calculados;

        printf("%d %d\n", infos[i].inicio, infos[i].fim);
        pthread_create(&ids[i], NULL, calc_trapezios_t, (void*)&infos[i]);

        ++i;
    }

    for (int j = 0; j < numero_threads; ++j) {
        pthread_join(ids[j], NULL);
    }
}