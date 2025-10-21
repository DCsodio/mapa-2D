#ifndef VEHICULO_H
#define VEHICULO_H

class vehiculo
{
public:
    vehiculo();


    int getPosMmY() const;
    void setPosMmY(int newPosMmY);
    int getPosMmX() const;
    void setPosMmX(int newPosMmX);

    void adelante(int distanciaMm);
    void atras(int distanciaMm);
    void girar(int grados);

private:
    int posMmY;
    int posMmX;
};

#endif // VEHICULO_H
