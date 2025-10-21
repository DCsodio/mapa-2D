#include "magnetometro.h"
#include <cmath>

magnetometro::magnetometro() {}

float magnetometro::getAnguloDeg() const
{
    return anguloDeg;
}

void magnetometro::setAnguloDeg(float _angulo)
{
    anguloDeg=_angulo;
}


