#include "mygraphicsview.h"

MyGraphicsView::MyGraphicsView(QWidget *parent)
    : QGraphicsView(parent) {
    setTransformationAnchor(QGraphicsView::AnchorViewCenter); // rota y hace zoom sobre el centro
    setResizeAnchor(QGraphicsView::AnchorViewCenter);         // mantiene el centro al redimensionar
    setFocusPolicy(Qt::StrongFocus);                          // permite recibir teclas
    //setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);     // opcional: evita mover barras
    //setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);       // opcional: evita mover barras
}

void MyGraphicsView::wheelEvent(QWheelEvent *event) {
    const double scaleFactor = 1.15;

    // Si se mantiene Ctrl → Zoom
    if (event->modifiers() & Qt::ControlModifier) {
        if (event->angleDelta().y() > 0)
            scale(scaleFactor, scaleFactor);
        else
            scale(1.0 / scaleFactor, 1.0 / scaleFactor);
    } else {
        // Si no hay Ctrl → comportamiento normal (scroll)
        QGraphicsView::wheelEvent(event);
    }
    actualizarRango();
}

void MyGraphicsView::scrollContentsBy(int dx, int dy) {
    QGraphicsView::scrollContentsBy(dx, dy);
    actualizarRango(); // ✅ actualiza también al mover la vista
}

void MyGraphicsView::actualizarRango() {
    QRectF visible = mapToScene(viewport()->rect()).boundingRect();
    emit rangoCambiado(visible); // ✅ emite la señal
}


void MyGraphicsView::keyPressEvent(QKeyEvent *event)
{
    const double paso = 5.0;
    QTransform t = transform();

    if (event->key() == Qt::Key_Left) {
        centerOn(0, 0);
        t.rotate(-paso);
        setTransform(t);
    }
    else if (event->key() == Qt::Key_Right) {
        centerOn(0, 0);
        t.rotate(paso);
        setTransform(t);
    }
    else if (event->key() == Qt::Key_Up) {
        // Espejo respecto al eje X (invierte Y)
        t.scale(1, -1);
        setTransform(t);
    }
    else if (event->key() == Qt::Key_Down) {
        // Espejo respecto al eje Y (invierte X)
        t.scale(-1, 1);
        setTransform(t);
    }
    else {
        QGraphicsView::keyPressEvent(event);
    }
}


