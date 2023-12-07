/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_6;
    QLineEdit *Tmin;
    QLineEdit *Tprom;
    QLineEdit *Tmax;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_5;
    QLineEdit *Hmin;
    QLineEdit *Hprom;
    QLineEdit *Hmax;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *Vmin;
    QLineEdit *Vprom;
    QLineEdit *Vmax;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *Dmin;
    QLineEdit *Dprom;
    QLineEdit *Dmax;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *Pmin;
    QLineEdit *Pprom;
    QLineEdit *Pmax;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_6;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout;
    QLineEdit *Lmin;
    QLineEdit *Lprom;
    QLineEdit *Lmax;
    QLineEdit *lineEdit_19;
    QLineEdit *lineEdit_20;
    QWidget *widget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1080, 720);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(520, 580, 151, 23));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 611, 234));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_7->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        Tmin = new QLineEdit(groupBox);
        Tmin->setObjectName(QString::fromUtf8("Tmin"));
        Tmin->setMinimumSize(QSize(10, 5));
        Tmin->setMaximumSize(QSize(500, 250));

        horizontalLayout_6->addWidget(Tmin);

        Tprom = new QLineEdit(groupBox);
        Tprom->setObjectName(QString::fromUtf8("Tprom"));
        Tprom->setMinimumSize(QSize(10, 5));
        Tprom->setMaximumSize(QSize(500, 250));

        horizontalLayout_6->addWidget(Tprom);

        Tmax = new QLineEdit(groupBox);
        Tmax->setObjectName(QString::fromUtf8("Tmax"));
        Tmax->setMinimumSize(QSize(10, 5));
        Tmax->setMaximumSize(QSize(500, 250));

        horizontalLayout_6->addWidget(Tmax);


        horizontalLayout_7->addLayout(horizontalLayout_6);


        gridLayout->addLayout(horizontalLayout_7, 0, 0, 1, 1);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_8->addWidget(label_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        Hmin = new QLineEdit(groupBox);
        Hmin->setObjectName(QString::fromUtf8("Hmin"));
        Hmin->setMinimumSize(QSize(10, 5));
        Hmin->setMaximumSize(QSize(500, 250));

        horizontalLayout_5->addWidget(Hmin);

        Hprom = new QLineEdit(groupBox);
        Hprom->setObjectName(QString::fromUtf8("Hprom"));
        Hprom->setMinimumSize(QSize(10, 5));
        Hprom->setMaximumSize(QSize(500, 250));

        horizontalLayout_5->addWidget(Hprom);

        Hmax = new QLineEdit(groupBox);
        Hmax->setObjectName(QString::fromUtf8("Hmax"));
        Hmax->setMinimumSize(QSize(10, 5));
        Hmax->setMaximumSize(QSize(500, 250));

        horizontalLayout_5->addWidget(Hmax);


        horizontalLayout_8->addLayout(horizontalLayout_5);


        gridLayout->addLayout(horizontalLayout_8, 1, 0, 1, 1);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_9->addWidget(label_3);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        Vmin = new QLineEdit(groupBox);
        Vmin->setObjectName(QString::fromUtf8("Vmin"));
        Vmin->setMinimumSize(QSize(10, 5));
        Vmin->setMaximumSize(QSize(500, 250));

        horizontalLayout_4->addWidget(Vmin);

        Vprom = new QLineEdit(groupBox);
        Vprom->setObjectName(QString::fromUtf8("Vprom"));
        Vprom->setMinimumSize(QSize(10, 5));
        Vprom->setMaximumSize(QSize(500, 250));

        horizontalLayout_4->addWidget(Vprom);

        Vmax = new QLineEdit(groupBox);
        Vmax->setObjectName(QString::fromUtf8("Vmax"));
        Vmax->setMinimumSize(QSize(10, 5));
        Vmax->setMaximumSize(QSize(500, 250));

        horizontalLayout_4->addWidget(Vmax);


        horizontalLayout_9->addLayout(horizontalLayout_4);


        gridLayout->addLayout(horizontalLayout_9, 2, 0, 1, 1);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_10->addWidget(label_4);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        Dmin = new QLineEdit(groupBox);
        Dmin->setObjectName(QString::fromUtf8("Dmin"));
        Dmin->setMinimumSize(QSize(10, 5));
        Dmin->setMaximumSize(QSize(500, 250));

        horizontalLayout_3->addWidget(Dmin);

        Dprom = new QLineEdit(groupBox);
        Dprom->setObjectName(QString::fromUtf8("Dprom"));
        Dprom->setMinimumSize(QSize(10, 5));
        Dprom->setMaximumSize(QSize(500, 250));

        horizontalLayout_3->addWidget(Dprom);

        Dmax = new QLineEdit(groupBox);
        Dmax->setObjectName(QString::fromUtf8("Dmax"));
        Dmax->setMinimumSize(QSize(10, 5));
        Dmax->setMaximumSize(QSize(500, 250));

        horizontalLayout_3->addWidget(Dmax);


        horizontalLayout_10->addLayout(horizontalLayout_3);


        gridLayout->addLayout(horizontalLayout_10, 3, 0, 1, 1);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_11->addWidget(label_5);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_5);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        Pmin = new QLineEdit(groupBox);
        Pmin->setObjectName(QString::fromUtf8("Pmin"));
        Pmin->setMinimumSize(QSize(10, 5));
        Pmin->setMaximumSize(QSize(500, 250));

        horizontalLayout_2->addWidget(Pmin);

        Pprom = new QLineEdit(groupBox);
        Pprom->setObjectName(QString::fromUtf8("Pprom"));
        Pprom->setMinimumSize(QSize(10, 5));
        Pprom->setMaximumSize(QSize(500, 250));

        horizontalLayout_2->addWidget(Pprom);

        Pmax = new QLineEdit(groupBox);
        Pmax->setObjectName(QString::fromUtf8("Pmax"));
        Pmax->setMinimumSize(QSize(10, 5));
        Pmax->setMaximumSize(QSize(500, 250));

        horizontalLayout_2->addWidget(Pmax);


        horizontalLayout_11->addLayout(horizontalLayout_2);


        gridLayout->addLayout(horizontalLayout_11, 4, 0, 1, 1);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_12->addWidget(label_6);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_6);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        Lmin = new QLineEdit(groupBox);
        Lmin->setObjectName(QString::fromUtf8("Lmin"));
        Lmin->setMinimumSize(QSize(10, 5));
        Lmin->setMaximumSize(QSize(500, 250));

        horizontalLayout->addWidget(Lmin);

        Lprom = new QLineEdit(groupBox);
        Lprom->setObjectName(QString::fromUtf8("Lprom"));
        Lprom->setMinimumSize(QSize(10, 5));
        Lprom->setMaximumSize(QSize(500, 250));

        horizontalLayout->addWidget(Lprom);

        Lmax = new QLineEdit(groupBox);
        Lmax->setObjectName(QString::fromUtf8("Lmax"));
        Lmax->setMinimumSize(QSize(10, 5));
        Lmax->setMaximumSize(QSize(500, 250));

        horizontalLayout->addWidget(Lmax);


        horizontalLayout_12->addLayout(horizontalLayout);


        gridLayout->addLayout(horizontalLayout_12, 5, 0, 1, 1);

        lineEdit_19 = new QLineEdit(centralwidget);
        lineEdit_19->setObjectName(QString::fromUtf8("lineEdit_19"));
        lineEdit_19->setGeometry(QRect(740, 180, 125, 50));
        lineEdit_19->setMinimumSize(QSize(25, 6));
        lineEdit_19->setBaseSize(QSize(125, 63));
        lineEdit_20 = new QLineEdit(centralwidget);
        lineEdit_20->setObjectName(QString::fromUtf8("lineEdit_20"));
        lineEdit_20->setGeometry(QRect(750, 310, 125, 50));
        lineEdit_20->setMinimumSize(QSize(25, 6));
        lineEdit_20->setBaseSize(QSize(125, 63));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(360, 430, 120, 80));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1080, 20));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Dar ultimo dato", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "SENSORES", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "TEMPERATURA", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "HUMEDAD", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "VELOCIDAD", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "DIRECCION DEL VIENTO", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "PRECIPITACION", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "INTENSIDAD DE LUZ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
