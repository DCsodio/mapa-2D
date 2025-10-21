#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsEllipseItem>
#include <QGraphicsTextItem>
#include <qcolordialog.h>
#include <QMouseEvent>

#include <QJsonDocument>
#include <QJsonObject>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Crear servidor WebSocket
    m_webSocketServer = new QWebSocketServer(QStringLiteral("Servidor Qt"),
                                             QWebSocketServer::NonSecureMode,
                                             this);

    if(m_webSocketServer->listen(QHostAddress::Any, 12345)){ // puerto 12345
        qDebug() << "Servidor WebSocket escuchando en puerto 12345";
        connect(m_webSocketServer, &QWebSocketServer::newConnection,
                this, &MainWindow::onNewConnection);
    } else {
        qDebug() << "Error al iniciar servidor WebSocket";
    }

    escena=new QGraphicsScene(this);

    ui->graphicsView->scale(1, -1);
    escena->setSceneRect(-1000,-1000,2000,2000);
    escena->setBackgroundBrush(Qt::gray);
    ui->graphicsView->setScene(escena);

    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setDragMode(QGraphicsView::ScrollHandDrag);


    agregarPuntoEjemplo();


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_limpiar_clicked()
{
    qDebug()<<puntos.size();
    for (auto item : puntos) {
        escena->removeItem(item);
        delete item;
    }
    puntos.clear();  // borra todos los punteros del vector de una sola vez
    escena->update();   //actualizamos la pantalla
}
/*
 * Este metodo agrega puntos en la escena
 * agrega punto nuevo al vector en el final
 */
void MainWindow::agregarPunto(double x, double y, const QColor &color)
{
    static unsigned int ID = 1; // ID único autoincremental


    Punto *p = new Punto(x, y, ID, color); // Pasamos el ID al constructor
    puntos.push_back(p);                     // Guardamos el puntero en el vector
    escena->addItem(p);                      // Lo agregamos a la escena
    ID++;
    qDebug() << "Nuevo punto agregado a la escena, ID:" << ID;
}


//puntos sde prueba
void MainWindow::agregarPuntoEjemplo(){
    agregarPunto(100,100,Qt::red);
    agregarPunto(200,200,Qt::red);
    agregarPunto(300,100,Qt::red);
    agregarPunto(400,500,Qt::red);
    agregarPunto(150,250,Qt::red);
    agregarPunto(0,0,Qt::red);
    agregarPunto(145,250,Qt::red);
    agregarPunto(230,150,Qt::red);
    agregarPunto(40,450,Qt::red);
    agregarPunto(100,230,Qt::red);
    agregarPunto(180,270,Qt::red);
    agregarPunto(950,250,Qt::red);
}

/*
 * Este metodo elimina puntos de la escena
 * elimina del vector puntos
 * reoordena el vector puntos
 */
void MainWindow::eliminarPunto(unsigned int numeroPunto){
    /*
     * aca se deberia plantear _ID de cada punto buscarlo en el vector y luego eliminarlo
     */
}


//impliementacion de websocket
void MainWindow::onNewConnection()
{
    QWebSocket *client = m_webSocketServer->nextPendingConnection();
    m_clients.append(client);

    connect(client, &QWebSocket::textMessageReceived,
            this, &MainWindow::onTextMessageReceived);
    connect(client, &QWebSocket::disconnected, [this, client]() {
        m_clients.removeAll(client);
        client->deleteLater();
    });

    qDebug() << "Cliente conectado desde" << client->peerAddress().toString();
}


//slot de recibir mensaje
void MainWindow::onTextMessageReceived(QString message)
{
    QJsonDocument doc = QJsonDocument::fromJson(message.toUtf8());
    if (!doc.isObject()) return;
    QJsonObject obj = doc.object();

    if(obj["accion"].toString()=="sensando"){
        qDebug()<<"Sensando....";
        enBotones=false;
        sensLaser.setDistanciaMm(obj["hipo"].toInt());
        sensAngulo.setValOp(obj["catop"].toInt());
        sensAngulo.setValAd(obj["catad"].toInt());

        coche.setPosMmX(obj["posx"].toInt());
        coche.setPosMmY(obj["posy"].toInt());

        sensAngulo.calcularAngulo();
        qDebug()<<sensAngulo.getValAd();
        qDebug()<<sensAngulo.getAnguloRad();
        //sohcahtoa
        double posX=cos(sensAngulo.getAnguloRad())*sensLaser.getDistanciaMm();
        double posY=sin(sensAngulo.getAnguloRad())*sensLaser.getDistanciaMm();

        posX+=coche.getPosMmX();
        posY+=coche.getPosMmY();

        agregarPunto(posX,posY,1);
    }else{
        enBotones=true;
        qDebug()<<"Moviendo el vehiculo...";
    }
}

void MainWindow::enviarMensaje(QString mensaje)
{
    if (!m_clients.isEmpty() && m_clients.first()->state() == QAbstractSocket::ConnectedState) {
        m_clients.first()->sendTextMessage(mensaje); //el primer cliente es el esp32
    } else {
        qDebug() << "No hay clientes conectados o el primero está desconectado";
    }
}



void MainWindow::on_pushButton_adelante_pressed()
{
    if(enBotones)
    enviarMensaje("adelante");
}


void MainWindow::on_pushButton_adelante_released()
{
    if(enBotones)
    enviarMensaje("detener");
}


void MainWindow::on_pushButton_izquierda_pressed()
{
    if(enBotones)
        enviarMensaje("izquierda");
}


void MainWindow::on_pushButton_izquierda_released()
{
    if(enBotones)
    enviarMensaje("detener");
}


void MainWindow::on_pushButton_derecha_pressed()
{
    if(enBotones)
    enviarMensaje("derecha");
}


void MainWindow::on_pushButton_derecha_released()
{
    if(enBotones)
    enviarMensaje("detener");
}


void MainWindow::on_pushButton_atras_pressed()
{
    if(enBotones)
    enviarMensaje("atras");
}


void MainWindow::on_pushButton_atras_released()
{
    if(enBotones)
    enviarMensaje("detener");
}

