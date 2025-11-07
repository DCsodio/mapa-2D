#include "magnetometro.h"
#include <cmath>

magnetometro::magnetometro() {
    anguloDeg=0;
    inicializado=false;
}

float magnetometro::getAnguloDeg() const
{
    return anguloDeg;
}

void magnetometro::setAnguloDeg(float _angulo)
{
    anguloDeg=_angulo;
}

bool magnetometro::getInicializado() const
{
    return inicializado;
}

void magnetometro::setInicializado(bool newInicializado)
{
    inicializado = newInicializado;
}

