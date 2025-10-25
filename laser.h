#ifndef LASER_H
#define LASER_H

#include <stdint.h>
class laser
{
public:
    laser();

    uint16_t getDistanciaMm() const;
    void setDistanciaMm(uint16_t newDistanciaMm);

private:
    uint16_t distanciaMm;

};

#endif // LASER_H
