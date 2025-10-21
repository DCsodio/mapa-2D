#include "punto.h"
#include <QPainter>
/*color toma los valores
 *Qt::red
 *Qt::blue
 *Qt::green
 *Qt::black
 *Qt::white
 *Qt::yellow
 *Qt::cyan
 *Qt::magenta
 *Qt::gray
*/

Punto::Punto(double x, double y, unsigned int _ID, const QColor &color)
    : m_x(x), m_y(y), m_color(color)
{
    this->ID=_ID;
    setPos(x, y);
    //setFlag(QGraphicsItem::ItemIsSelectable);
}

QRectF Punto::boundingRect() const {
    return QRectF(-5, -5, 80, 80); // área de dibujo
}

void Punto::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) {
    /*
     * aca solo se dibuja
     */
    // círculo
    painter->setBrush(m_color);
    painter->setPen(Qt::black);
    painter->drawEllipse(0, 0, 2, 2);

    // texto
    if(ENABLE_TEXTO){
        painter->setPen(m_color);
        painter->drawText(10, 10, QString("(%1,%2)").arg(m_x).arg(m_y));
    }
}
