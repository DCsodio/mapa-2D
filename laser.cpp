#include "laser.h"

laser::laser() {}

int laser::getDistanciaMm() const
{
    return distanciaMm;
}

void laser::setDistanciaMm(int newDistanciaMm)
{
    distanciaMm = newDistanciaMm;
}
