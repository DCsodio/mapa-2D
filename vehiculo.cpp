#include "vehiculo.h"
#include <QPainter>

vehiculo::vehiculo(double x, double y, const QColor &color){

    posMmX=0;
    posMmY=0;
    posMmX=x;
    posMmY=y;
    colorVehiculo=color;
}

QRectF vehiculo::boundingRect() const {
    return QRectF(-5, -5, 500, 500); // área de dibujo
}

void vehiculo::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) {
    /*
     * aca solo se dibuja
     */
    // círculo
    painter->setBrush(colorVehiculo);
    painter->setPen(Qt::blue);
    painter->drawEllipse(0, 0, 100, 100);

}

int vehiculo::getPosMmY() const
{
    return posMmY;
}

void vehiculo::setPosMmY(int newPosMmY)
{
    posMmY = newPosMmY;
}

int vehiculo::getPosMmX() const
{
    return posMmX;
}

void vehiculo::setPosMmX(int newPosMmX)
{
    posMmX = newPosMmX;
}

void vehiculo::actualizar_posicion(void){
    setPos(posMmX, posMmY); // mueve el ítem en la escena
    update();               // fuerza redibujado
}

void vehiculo::nueva_ubicacion(float grados, uint32_t pulsos, bool direccionAdelante){

    double x=0;
    double y=0;

    double rad = qDegreesToRadians(grados);

        if(direccionAdelante){
            x= posMmX+cos(rad)*pulsos*CTE_RUEDA;
            y= posMmY+sin(rad)*pulsos*CTE_RUEDA;
        }else{
            x= posMmX-cos(rad)*pulsos*CTE_RUEDA;
            y= posMmY-sin(rad)*pulsos*CTE_RUEDA;
        }

    posMmX=x;
    posMmY=y;
}

