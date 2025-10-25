#include "laser.h"

laser::laser() {}

uint16_t laser::getDistanciaMm() const
{
    return distanciaMm;
}

void laser::setDistanciaMm(uint16_t newDistanciaMm)
{
    distanciaMm = newDistanciaMm;
}
