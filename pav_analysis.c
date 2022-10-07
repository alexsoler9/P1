#include <math.h>
#include <stdio.h>
#include "pav_analysis.h"

float compute_power(const float *x, unsigned int N) {
    float aux = 1e-12; //Debemos evitar inicializar a 0, saldra infinito a la salida
    float potencia;
    for (unsigned int i=0; i<(N-1); i++) {
        aux += x[i]*x[i];
    }

    potencia = (10*log10(aux/N));
    //printf("Potencia: %f\n", potencia);
    return potencia;
}

float compute_am(const float *x, unsigned int N) {
    float aux;
    float media;
    for (unsigned int i=0; i<N-1; i++) {
        aux += fabs(x[i]);
    }

    media = aux/N;
    //printf("Media: %f\n", media);
    return media;
}

float compute_zcr(const float *x, unsigned int N, float fm) {
    int contador = 0;

    for (unsigned int i=1; i<N; i++) {
        if (x[i]*x[i-1] < 0) {
            contador++;
        }
    }

    return (fm/2.0)*(1/(N-1.0))*contador;
}