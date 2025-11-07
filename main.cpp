#include "mainwindow.h"

#include <QApplication>
#include <QGraphicsScale>
#include <QGraphicsView>
#include <QGraphicsEllipseItem>
#include <QVBoxLayout>
#include <QWidget>




int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
