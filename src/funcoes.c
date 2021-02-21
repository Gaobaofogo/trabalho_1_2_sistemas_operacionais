#include <math.h>

#include "funcoes.h"


float f1(float x) {
    return 5.0;
}


float f2(float x) {
    return sin(2.0 * x) + cos(5.0 * x);
}


float calc_area(int numero_threads, int numero_trapezios) {
    float h, area_total;
    float a = 0.0;
    float b = 10.0;

    h = (b - a) / numero_trapezios;
    area_total = (f1(a) + f1(b))/2;

    for (int i = 1; i < numero_trapezios; ++i) {
        float x_i = a + i * h;
        area_total += f1(x_i);
    }

    area_total = h * area_total;

    return area_total;
}