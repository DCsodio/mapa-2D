#ifndef MYGRAPHICSVIEW_H
#define MYGRAPHICSVIEW_H
#include <QGraphicsView>
#include <QWheelEvent>
#include <QScrollBar>
#include <QGraphicsItem>

class MyGraphicsView : public QGraphicsView {
    Q_OBJECT
public:
    explicit MyGraphicsView(QWidget *parent = nullptr);

signals:
    void rangoCambiado(QRectF rectVisible);

protected:
    void wheelEvent(QWheelEvent *event) override;
    void scrollContentsBy(int dx, int dy) override;
    void keyPressEvent(QKeyEvent *event) override;

private:
    void actualizarRango();
};

#endif // MYGRAPHICSVIEW_H
