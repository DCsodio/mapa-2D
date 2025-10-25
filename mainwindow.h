#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QColor>

#include "punto.h"
#include "magnetometro.h"
#include "laser.h"
#include "vehiculo.h"
#include "paquete.h"

#include <vector>
#include <QWebSocketServer>
#include <QWebSocket>

#include <QKeyEvent>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_limpiar_clicked();

    void onNewConnection();
    void onBinaryMessageReceived(const QByteArray &data);



    void on_pushButton_adelante_pressed();

    void on_pushButton_adelante_released();

    void on_pushButton_izquierda_pressed();

    void on_pushButton_izquierda_released();

    void on_pushButton_derecha_pressed();

    void on_pushButton_derecha_released();

    void on_pushButton_atras_pressed();

    void on_pushButton_atras_released();

private:

    void agregarPunto(double x, double y, const QColor &color=Qt::red);
    void agregarPuntoEjemplo();
    void eliminarPunto(unsigned int numeroPunto);

    void enviarMensaje(QString mensaje);

    Ui::MainWindow *ui;
    QGraphicsScene *escena;

    Paquete pkt;

    std::vector<Punto*> puntos; //almacena las direcciones de los puntos para poder tener control

    magnetometro sensAngulo;
    laser sensLaser;
    vehiculo coche;

    bool enableBotones=false;

    QWebSocketServer *m_webSocketServer;
    QList<QWebSocket*> m_clients;
};
#endif // MAINWINDOW_H
