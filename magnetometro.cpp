#include "magnetometro.h"
#include <cmath>

magnetometro::magnetometro() {}

bool magnetometro::calcularAngulo()
{
    anguloRad=atan2((double)valOp,(double)valAd);

    return true;
}

int magnetometro::getValOp() const
{
    return valOp;
}

void magnetometro::setValOp(int newValOp)
{
    valOp = newValOp;
}

int magnetometro::getValAd() const
{
    return valAd;
}

void magnetometro::setValAd(int newValAd)
{
    valAd = newValAd;
}

double magnetometro::getAnguloRad() const
{
    return anguloRad;
}


