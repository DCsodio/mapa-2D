#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsEllipseItem>
#include <QGraphicsTextItem>
#include <qcolordialog.h>
#include <QMouseEvent>

#include "mygraphicsview.h"
#include <QHostInfo>
#include <QNetworkInterface>// obtener la direccion ip local

#include <QJsonDocument>
#include <QJsonObject>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ID=0;

    //adquirir la direccion ip del servidos
    QString ip;
    const auto addresses = QNetworkInterface::allAddresses();
    for (const QHostAddress &address : std::as_const(addresses)) {
        if (address.protocol() == QAbstractSocket::IPv4Protocol && !address.isLoopback()) {
            ip = address.toString();
            break;
        }
    }

    // Crear servidor WebSocket
    m_webSocketServer = new QWebSocketServer(QStringLiteral("Servidor Qt"),
                                             QWebSocketServer::NonSecureMode,
                                             this);

    if(m_webSocketServer->listen(QHostAddress::Any, 12345)){ // puerto 12345

        qDebug() << "Servidor en la ip"<< ip<< "En el puerto 12345";
        ui->plainTextEdit->appendPlainText("IP de servidor: "+ip);
        ui->plainTextEdit->appendPlainText("Puerto: 12345");

        connect(m_webSocketServer, &QWebSocketServer::newConnection,
                this, &MainWindow::onNewConnection);
    } else {
        ui->plainTextEdit->appendPlainText("Error al iniciar servidor WebSocket");
        qDebug() << "Error al iniciar servidor WebSocket";
    }

    escena=new QGraphicsScene(this);

    ui->graphicsView->scale(1, 1);
    escena->setSceneRect(-4000, -4000, 8000, 8000);
    ui->graphicsView->centerOn(0, 0);
    escena->setBackgroundBrush(Qt::gray);
    ui->graphicsView->setScene(escena);

    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setDragMode(QGraphicsView::ScrollHandDrag);
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
    ui->graphicsView->viewport()->setAttribute(Qt::WA_AcceptTouchEvents);
    ui->graphicsView->grabGesture(Qt::PinchGesture);

    ui->label_3->setStyleSheet("color: black; background-color: #e6e6e6;");
    ui->label_3->setAlignment(Qt::AlignCenter);

    connect(ui->graphicsView, &MyGraphicsView::rangoCambiado,
            this, &MainWindow::actualizarLabelRango);

    //agrego el auto
    auto1 = new vehiculo(0, 0, Qt::red);
    escena->addItem(auto1);

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
    ID=0;
    ui->plainTextEdit->appendPlainText("Puntos borrados");
}

/*
 * Este metodo agrega puntos en la escena
 * agrega punto nuevo al vector en el final
 */
void MainWindow::agregarPunto(double x, double y, const QColor &color)
{
    Punto *p = new Punto(x, y, ID, color); // Pasamos el ID al constructor
    puntos.push_back(p);                     // Guardamos el puntero en el vector
    escena->addItem(p);                      // Lo agregamos a la escena
    ID++;
    qDebug() << "Nuevo punto agregado a la escena, ID:" << ID;
    ui->plainTextEdit->appendPlainText("Nuevo punto agregado ID: "+QString::number(ID));
}


//puntos sde prueba
void MainWindow::agregarPuntoEjemplo(){
    agregarPunto(100,100,Qt::red);
    agregarPunto(200,200,Qt::red);
    agregarPunto(300,100,Qt::red);
    agregarPunto(400,500,Qt::red);
    agregarPunto(150,250,Qt::red);
    agregarPunto(4000,4000,Qt::red);
    agregarPunto(145,250,Qt::red);
    agregarPunto(230,150,Qt::red);
    agregarPunto(0,0,Qt::red);
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
    connect(client, &QWebSocket::binaryMessageReceived,
            this, &MainWindow::onBinaryMessageReceived);

    connect(client, &QWebSocket::disconnected, this, [this, client]() {
        m_clients.removeAll(client);
        client->deleteLater();
    });

    ui->plainTextEdit->appendPlainText("Cliente conectado desde: "+client->peerAddress().toString());
    qDebug() << "Cliente conectado desde" << client->peerAddress().toString();
}


//slot de recibir paquete de wifi (EPS32)
void MainWindow::onBinaryMessageReceived(const QByteArray &data)
{
    // 1. Verifico tamaño esperado
    if (data.size() != sizeof(Paquete)){
        qDebug() << "Tamaño incorrecto. Esperado:" << sizeof(Paquete) << "Recibido:" << data.size();
        ui->plainTextEdit->appendPlainText("ERROR TAMAÑO");
        return;
    }
    // 2. Casteo a struct (copio lo que me llego en pkt)
    memcpy(&pkt, data.constData(), sizeof(Paquete));

    // 3. Verifico headers
     if(pkt.header[0] != HEADERONE || pkt.header[1] != HEADERTWO){
        ui->plainTextEdit->appendPlainText("ERROR EN LOS HEADER");
        qDebug() << "ERROR EN LOS HEADER";
        return;
     }else{
         ui->plainTextEdit->appendPlainText("Nuevo paquete recibido ok");
          qDebug()<<"Nuevo paquete recibido ok";
     }

    uint32_t valChecksum= calcularChecksum(&pkt);

    if(valChecksum==pkt.checksum){
        // agregar punto si es correcto
        if(pkt.analizando==true){
            //sensAngulo.setAnguloDeg(pkt.grados);
            sensLaser.setDistanciaMm(pkt.distanciaMm);
            QString datoss=" ANGULO RECIBIDO:"+QString::number(pkt.grados);
             ui->plainTextEdit->appendPlainText(datoss);
            if(sensAngulo.getInicializado()){
                sensAngulo.setAnguloDeg(pkt.grados);
                anguloForz=sensAngulo.getAnguloDeg();
                sensAngulo.setInicializado(true);
            }

            aCartesiano(sensLaser.getDistanciaMm(),anguloForz);

            if(sensLaser.getDistanciaMm()<2500){
                agregarPunto(puntoLeidoX,puntoLeidoY);
                ui->plainTextEdit->appendPlainText("Punto agregado");
                QString datos="distancia:"+QString::number(sensLaser.getDistanciaMm())+", angulo:"+QString::number(anguloForz);
                ui->plainTextEdit->appendPlainText(datos);
            }else{
                ui->plainTextEdit->appendPlainText("Punto no agregado");
            }
            qDebug()<<"pkt ok";
            if(pkt.cantidadPasos!=cantidadPasos){
                cantidadPasos=pkt.cantidadPasos;
                anguloForz=anguloForz+1.8*cantidadPasos;
            }
            if(maquinaEstado==0){
                anguloForz=anguloForz+1.8;
                if (anguloForz>sensAngulo.getAnguloDeg()+180){
                    maquinaEstado=1;
                }
            }else if (maquinaEstado==1){
                anguloForz=anguloForz-1.8;
                if(anguloForz<sensAngulo.getAnguloDeg()){
                    maquinaEstado=2;
                }
            }else if(maquinaEstado==2){
                anguloForz=anguloForz-1.8;
                if(anguloForz<sensAngulo.getAnguloDeg()-180){
                    maquinaEstado=3;
                }
            }else if(maquinaEstado==3){
                anguloForz=anguloForz+1.8;
                if (anguloForz>sensAngulo.getAnguloDeg()){
                    maquinaEstado=0;
                }
            }
            cantidadPasos++;
        }else{
            if(!enableBotones){
                qDebug()<<"movimiento activado";
                ui->plainTextEdit->appendPlainText("Movimiento activado");
                enableBotones=true;
                sensAngulo.setInicializado(false);
                anguloForz=0;
            }else{
                ui->plainTextEdit->appendPlainText(QString::number(pkt.pulsos));
                sensAngulo.setAnguloDeg(pkt.grados);
                auto1->nueva_ubicacion(sensAngulo.getAnguloDeg(),pkt.pulsos,pkt.direccionAdelante);
                auto1->actualizar_posicion();
            }

        }
    }else{
        ui->plainTextEdit->appendPlainText("ERROR EN CHECKSUM");
        qDebug() << "ERROR EN CHECKSUM";
    }

}

void MainWindow::enviarMensaje(QString mensaje)
{
    if (!m_clients.isEmpty() && m_clients.first()->state() == QAbstractSocket::ConnectedState) {
        m_clients.first()->sendTextMessage(mensaje); //el primer cliente es el esp32
    } else {
        ui->plainTextEdit->appendPlainText("No hay clientes conectados o el primero está desconectado");
        qDebug() << "No hay clientes conectados o el primero está desconectado";
    }
}



void MainWindow::on_pushButton_adelante_pressed()
{
    if(enableBotones){
        ui->plainTextEdit->appendPlainText("adelante");
        enviarMensaje(">w<");
    }
}


void MainWindow::on_pushButton_adelante_released()
{
    if(enableBotones){
        ui->plainTextEdit->appendPlainText("detener");
        enviarMensaje(">p<");
    }
}


void MainWindow::on_pushButton_izquierda_pressed()
{
    if(enableBotones){
        ui->plainTextEdit->appendPlainText("izquierda");
        enviarMensaje(">a<");
    }
}


void MainWindow::on_pushButton_izquierda_released()
{
    if(enableBotones){
        ui->plainTextEdit->appendPlainText("detener");
        enviarMensaje(">p<");
    }
}


void MainWindow::on_pushButton_derecha_pressed()
{
    if(enableBotones){
        ui->plainTextEdit->appendPlainText("Derecha");
        enviarMensaje(">d<");
    }
}


void MainWindow::on_pushButton_derecha_released()
{
    if(enableBotones){
        ui->plainTextEdit->appendPlainText("Detener");
        enviarMensaje(">p<");
    }
}


void MainWindow::on_pushButton_atras_pressed()
{
    if(enableBotones){
        ui->plainTextEdit->appendPlainText("Atras");
        enviarMensaje(">s<");
    }
}


void MainWindow::on_pushButton_atras_released()
{
    if(enableBotones){
        ui->plainTextEdit->appendPlainText("Detener");
        enviarMensaje(">p<");
    }
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    ui->progressBar->setValue(value);
}


void MainWindow::on_horizontalSlider_sliderReleased()
{
    int valor=ui->horizontalSlider->value();
    QString nuevoValor= ">motor:"+QString::number(valor)+"<";
    enviarMensaje(nuevoValor);
}




void MainWindow::on_horizontalSlider_2_sliderReleased()
{

    int valor=ui->horizontalSlider_2->value();
    QString nuevoValor= ">periodo:"+QString::number(valor)+"<";
    enviarMensaje(nuevoValor);

}


void MainWindow::on_horizontalSlider_2_valueChanged(int value)
{
    ui->label_3->setText(QString::number(value)+"s");
}


void MainWindow::on_pushButton_2_released()
{
    enviarMensaje(">analizar<");
}


void MainWindow::on_pushButton_released()
{
    enviarMensaje(">reset<");
}


void MainWindow::on_checkBox_2_toggled(bool checked)
{
    if(checked){
        enviarMensaje(">enMov<");
    }else{
        enviarMensaje(">disMov<");
    }
}

void MainWindow::actualizarLabelRango(const QRectF &rango) {
    ui->label_4->setText(
        QString("X: [%1, %2], Y: [%3, %4]")
            .arg(rango.left())
            .arg(rango.right())
            .arg(rango.top())
            .arg(rango.bottom())
        );
}
