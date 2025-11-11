#include "mainwindow.h"

#include <QApplication>
#include <QGraphicsScale>
#include <QGraphicsView>
#include <QGraphicsEllipseItem>
#include <QVBoxLayout>
#include <QWidget>
#include <QIcon>




int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/logo.png"));
    MainWindow w;
    w.show();
    return a.exec();
}
