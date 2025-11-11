#pragma once

#include <QGraphicsItem>
#include <QColor>
#define CTE_RUEDA 11.08695652
class vehiculo : public QGraphicsItem
{
public:
    vehiculo(double x, double y, const QColor &color);


    int getPosMmY() const;
    void setPosMmY(int newPosMmY);
    int getPosMmX() const;
    void setPosMmX(int newPosMmX);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) override;

    void actualizar_posicion(void);
    void nueva_ubicacion(float grados, uint32_t pulsos, bool direccionAdelante);

private:


    double posMmY;
    double posMmX;

    QColor colorVehiculo;

};
