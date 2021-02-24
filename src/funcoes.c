#include <stdio.h>

#include "calc_math.h"
#include "funcoes.h"
#include "threads.h"

#define PI 3.1415


float calc_area(int numero_threads, int numero_trapezios) {
    float v[numero_trapezios];
    float h, area_total;
    float a = 0.0;
    float b = 10;

    h = (b - a) / numero_trapezios;
    area_total = (f2(a) + f2(b))/2;

    calc_trapezios_via_threads(
        numero_threads,
        numero_trapezios,
        a,
        h,
        v);

    for (int i = 1; i < numero_trapezios; ++i) {
        area_total += v[i];
    }

    area_total = h * area_total;

    return area_total;
}