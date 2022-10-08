#include <stdio.h>
#include "fic_wave.h"

FILE *abre_wave(const char *ficWave, float *fm) {
    FILE *fpWave;
    unsigned int fmHeader; //no puede ser negativa

    if ((fpWave = fopen(ficWave, "r")) == NULL) return NULL;
    if (fseek(fpWave, 44, SEEK_SET) < 0) return NULL;

    fseek(fpWave, 24, SEEK_SET); //desde el principio del fichero, fm corresponde a un offset de 24
    fread(&fmHeader, 4, 1, fpWave); //fm tiene un tamaño de 4 bytes
    *fm = fmHeader;
    fseek(fpWave, 44, SEEK_SET);

    return fpWave;
}

size_t lee_wave(void *x, size_t size, size_t nmemb, FILE *fpWave) {
    return fread(x, size, nmemb, fpWave);
}

void cierra_wave(FILE *fpWave) {
    fclose(fpWave);
}