#ifndef LASER_H
#define LASER_H

class laser
{
public:
    laser();

    int getDistanciaMm() const;
    void setDistanciaMm(int newDistanciaMm);

private:
    int distanciaMm;

};

#endif // LASER_H
