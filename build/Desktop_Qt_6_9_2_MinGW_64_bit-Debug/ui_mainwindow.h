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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "mygraphicsview.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_4;
    QPushButton *limpiar;
    QHBoxLayout *horizontalLayout_7;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_2;
    QSlider *horizontalSlider;
    QProgressBar *progressBar;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_5;
    QLabel *label;
    QSlider *horizontalSlider_2;
    QLabel *label_3;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButton_adelante;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_izquierda;
    QPushButton *pushButton_derecha;
    QVBoxLayout *verticalLayout_3;
    QPushButton *pushButton_atras;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_11;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer_2;
    QCheckBox *checkBox_2;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_6;
    QPlainTextEdit *plainTextEdit;
    QVBoxLayout *verticalLayout_9;
    MyGraphicsView *graphicsView;
    QLabel *label_4;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->setEnabled(true);
        MainWindow->resize(778, 590);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: #c4dfa4;"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout_2 = new QHBoxLayout(centralwidget);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName("verticalLayout_4");
        limpiar = new QPushButton(centralwidget);
        limpiar->setObjectName("limpiar");

        verticalLayout_4->addWidget(limpiar);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName("verticalLayout_7");
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");

        verticalLayout_7->addWidget(label_2);

        horizontalSlider = new QSlider(centralwidget);
        horizontalSlider->setObjectName("horizontalSlider");
        horizontalSlider->setMaximum(100);
        horizontalSlider->setOrientation(Qt::Orientation::Horizontal);

        verticalLayout_7->addWidget(horizontalSlider);

        progressBar = new QProgressBar(centralwidget);
        progressBar->setObjectName("progressBar");
        progressBar->setValue(0);

        verticalLayout_7->addWidget(progressBar);


        horizontalLayout_7->addLayout(verticalLayout_7);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        label = new QLabel(centralwidget);
        label->setObjectName("label");

        verticalLayout_5->addWidget(label);

        horizontalSlider_2 = new QSlider(centralwidget);
        horizontalSlider_2->setObjectName("horizontalSlider_2");
        horizontalSlider_2->setMinimum(150);
        horizontalSlider_2->setMaximum(500);
        horizontalSlider_2->setOrientation(Qt::Orientation::Horizontal);

        verticalLayout_5->addWidget(horizontalSlider_2);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setMinimumSize(QSize(0, 21));
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe UI")});
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8("background-color: #e6e6e6;"));

        verticalLayout_5->addWidget(label_3);


        horizontalLayout_7->addLayout(verticalLayout_5);


        verticalLayout_4->addLayout(horizontalLayout_7);

        verticalSpacer_2 = new QSpacerItem(20, 50, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        pushButton_adelante = new QPushButton(centralwidget);
        pushButton_adelante->setObjectName("pushButton_adelante");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_adelante->sizePolicy().hasHeightForWidth());
        pushButton_adelante->setSizePolicy(sizePolicy);
        pushButton_adelante->setMinimumSize(QSize(50, 50));
        pushButton_adelante->setStyleSheet(QString::fromUtf8("background-color:#c93cd6;"));

        verticalLayout_2->addWidget(pushButton_adelante);


        verticalLayout->addLayout(verticalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        pushButton_izquierda = new QPushButton(centralwidget);
        pushButton_izquierda->setObjectName("pushButton_izquierda");
        pushButton_izquierda->setMinimumSize(QSize(50, 50));

        horizontalLayout->addWidget(pushButton_izquierda);

        pushButton_derecha = new QPushButton(centralwidget);
        pushButton_derecha->setObjectName("pushButton_derecha");
        pushButton_derecha->setMinimumSize(QSize(50, 50));

        horizontalLayout->addWidget(pushButton_derecha);


        verticalLayout->addLayout(horizontalLayout);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        pushButton_atras = new QPushButton(centralwidget);
        pushButton_atras->setObjectName("pushButton_atras");
        pushButton_atras->setMinimumSize(QSize(50, 50));

        verticalLayout_3->addWidget(pushButton_atras);


        verticalLayout->addLayout(verticalLayout_3);


        verticalLayout_4->addLayout(verticalLayout);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_3);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName("horizontalLayout_11");
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");

        horizontalLayout_11->addWidget(pushButton_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_2);

        checkBox_2 = new QCheckBox(centralwidget);
        checkBox_2->setObjectName("checkBox_2");

        horizontalLayout_11->addWidget(checkBox_2);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_3);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");

        horizontalLayout_11->addWidget(pushButton);


        verticalLayout_4->addLayout(horizontalLayout_11);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName("verticalLayout_6");
        plainTextEdit = new QPlainTextEdit(centralwidget);
        plainTextEdit->setObjectName("plainTextEdit");

        verticalLayout_6->addWidget(plainTextEdit);


        verticalLayout_4->addLayout(verticalLayout_6);


        horizontalLayout_2->addLayout(verticalLayout_4);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName("verticalLayout_9");
        graphicsView = new MyGraphicsView(centralwidget);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setStyleSheet(QString::fromUtf8("background-color: #cfcfcf;"));

        verticalLayout_9->addWidget(graphicsView);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");

        verticalLayout_9->addWidget(label_4);


        horizontalLayout_2->addLayout(verticalLayout_9);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 778, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Mapa", nullptr));
        limpiar->setText(QCoreApplication::translate("MainWindow", "Limpiar", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Velocidad de motores", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Periodo de analisis", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "120s", nullptr));
        pushButton_adelante->setText(QCoreApplication::translate("MainWindow", "Adelante", nullptr));
        pushButton_izquierda->setText(QCoreApplication::translate("MainWindow", "Izquierda", nullptr));
        pushButton_derecha->setText(QCoreApplication::translate("MainWindow", "Derecha", nullptr));
        pushButton_atras->setText(QCoreApplication::translate("MainWindow", "Atras", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Analizar", nullptr));
        checkBox_2->setText(QCoreApplication::translate("MainWindow", "solo movilidad", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
