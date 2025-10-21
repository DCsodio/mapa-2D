/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGraphicsView *graphicsView;
    QPushButton *limpiar;
    QPushButton *pushButton_adelante;
    QPushButton *pushButton_izquierda;
    QPushButton *pushButton_derecha;
    QPushButton *pushButton_atras;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->setEnabled(true);
        MainWindow->resize(1065, 593);
        MainWindow->setMaximumSize(QSize(1065, 593));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setGeometry(QRect(250, 30, 711, 441));
        limpiar = new QPushButton(centralwidget);
        limpiar->setObjectName("limpiar");
        limpiar->setGeometry(QRect(10, 10, 51, 21));
        pushButton_adelante = new QPushButton(centralwidget);
        pushButton_adelante->setObjectName("pushButton_adelante");
        pushButton_adelante->setGeometry(QRect(70, 100, 111, 51));
        pushButton_izquierda = new QPushButton(centralwidget);
        pushButton_izquierda->setObjectName("pushButton_izquierda");
        pushButton_izquierda->setGeometry(QRect(0, 190, 111, 51));
        pushButton_derecha = new QPushButton(centralwidget);
        pushButton_derecha->setObjectName("pushButton_derecha");
        pushButton_derecha->setGeometry(QRect(130, 190, 111, 51));
        pushButton_atras = new QPushButton(centralwidget);
        pushButton_atras->setObjectName("pushButton_atras");
        pushButton_atras->setGeometry(QRect(70, 280, 111, 51));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1065, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        limpiar->setText(QCoreApplication::translate("MainWindow", "limpiar", nullptr));
        pushButton_adelante->setText(QCoreApplication::translate("MainWindow", "adelante", nullptr));
        pushButton_izquierda->setText(QCoreApplication::translate("MainWindow", "izquierda", nullptr));
        pushButton_derecha->setText(QCoreApplication::translate("MainWindow", "derecha", nullptr));
        pushButton_atras->setText(QCoreApplication::translate("MainWindow", "atras", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
