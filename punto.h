#ifndef PUNTO_H
#define PUNTO_H

#pragma once
#include <QGraphicsItem>
#include <QColor>
#define ENABLE_TEXTO false

class Punto : public QGraphicsItem {
public:
    Punto(double x, double y,unsigned int _ID, const QColor &color);

    void aCartesiana(int hipotenusa, double angulo);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) override;

private:
    double m_x, m_y;
    unsigned int ID;
    QColor m_color;
};


#endif // PUNTO_H
