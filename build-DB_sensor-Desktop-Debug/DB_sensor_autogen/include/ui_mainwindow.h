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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_9;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_10;
    QSpacerItem *horizontalSpacer_8;
    QHBoxLayout *horizontalLayout_9;
    QVBoxLayout *verticalLayout_7;
    QVBoxLayout *verticalLayout_5;
    QLabel *label;
    QHBoxLayout *horizontalLayout_6;
    QLineEdit *Tmin;
    QLineEdit *Tprom;
    QLineEdit *Tmax;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer;
    QLineEdit *ledT;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_14;
    QSpacerItem *horizontalSpacer_5;
    QVBoxLayout *verticalLayout_8;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_5;
    QLineEdit *Hmin;
    QLineEdit *Hprom;
    QLineEdit *Hmax;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_3;
    QLineEdit *ledH;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_11;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout_12;
    QSpacerItem *horizontalSpacer_9;
    QHBoxLayout *horizontalLayout_11;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *Vmin;
    QLineEdit *Vprom;
    QLineEdit *Vmax;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *horizontalSpacer_15;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *Pmin;
    QLineEdit *Pprom;
    QLineEdit *Pmax;
    QSpacerItem *horizontalSpacer_12;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_14;
    QSpacerItem *horizontalSpacer_10;
    QHBoxLayout *horizontalLayout_13;
    QVBoxLayout *verticalLayout;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *Dmin;
    QLineEdit *Dprom;
    QLineEdit *Dmax;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *horizontalSpacer_16;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_6;
    QHBoxLayout *horizontalLayout;
    QLineEdit *Lmin;
    QLineEdit *Lprom;
    QLineEdit *Lmax;
    QSpacerItem *horizontalSpacer_13;
    QSpacerItem *verticalSpacer_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1080, 720);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_9->addItem(verticalSpacer);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("DejaVu Serif"));
        font.setPointSize(11);
        label->setFont(font);

        verticalLayout_5->addWidget(label);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        Tmin = new QLineEdit(centralwidget);
        Tmin->setObjectName(QString::fromUtf8("Tmin"));
        Tmin->setMinimumSize(QSize(125, 25));
        Tmin->setMaximumSize(QSize(500, 250));
        QFont font1;
        font1.setFamily(QString::fromUtf8("DejaVu Sans"));
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        Tmin->setFont(font1);
        Tmin->setStyleSheet(QString::fromUtf8("QLineEdit { text-align: center; }"));

        horizontalLayout_6->addWidget(Tmin);

        Tprom = new QLineEdit(centralwidget);
        Tprom->setObjectName(QString::fromUtf8("Tprom"));
        Tprom->setMinimumSize(QSize(125, 25));
        Tprom->setMaximumSize(QSize(500, 250));
        Tprom->setFont(font1);
        Tprom->setStyleSheet(QString::fromUtf8("QLineEdit { text-align: center; }"));

        horizontalLayout_6->addWidget(Tprom);

        Tmax = new QLineEdit(centralwidget);
        Tmax->setObjectName(QString::fromUtf8("Tmax"));
        Tmax->setMinimumSize(QSize(125, 25));
        Tmax->setMaximumSize(QSize(500, 250));
        Tmax->setFont(font1);
        Tmax->setStyleSheet(QString::fromUtf8("QLineEdit { text-align: center; }"));

        horizontalLayout_6->addWidget(Tmax);


        verticalLayout_5->addLayout(horizontalLayout_6);


        verticalLayout_7->addLayout(verticalLayout_5);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer);

        ledT = new QLineEdit(centralwidget);
        ledT->setObjectName(QString::fromUtf8("ledT"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ledT->sizePolicy().hasHeightForWidth());
        ledT->setSizePolicy(sizePolicy);
        ledT->setMinimumSize(QSize(100, 100));
        ledT->setBaseSize(QSize(100, 100));
        ledT->setStyleSheet(QString::fromUtf8("QLineEdit { border-radius: 100px; }"));

        horizontalLayout_7->addWidget(ledT);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_2);


        verticalLayout_7->addLayout(horizontalLayout_7);


        horizontalLayout_9->addLayout(verticalLayout_7);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_14);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_5);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        verticalLayout_6->addWidget(label_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        Hmin = new QLineEdit(centralwidget);
        Hmin->setObjectName(QString::fromUtf8("Hmin"));
        Hmin->setMinimumSize(QSize(125, 25));
        Hmin->setMaximumSize(QSize(500, 250));
        Hmin->setFont(font1);
        Hmin->setStyleSheet(QString::fromUtf8("QLineEdit { text-align: center; }"));

        horizontalLayout_5->addWidget(Hmin);

        Hprom = new QLineEdit(centralwidget);
        Hprom->setObjectName(QString::fromUtf8("Hprom"));
        Hprom->setMinimumSize(QSize(50, 25));
        Hprom->setMaximumSize(QSize(500, 250));
        Hprom->setFont(font1);
        Hprom->setStyleSheet(QString::fromUtf8("QLineEdit { text-align: center; }"));

        horizontalLayout_5->addWidget(Hprom);

        Hmax = new QLineEdit(centralwidget);
        Hmax->setObjectName(QString::fromUtf8("Hmax"));
        Hmax->setMinimumSize(QSize(50, 25));
        Hmax->setMaximumSize(QSize(500, 250));
        Hmax->setFont(font1);
        Hmax->setStyleSheet(QString::fromUtf8("QLineEdit { text-align: center; }"));

        horizontalLayout_5->addWidget(Hmax);


        verticalLayout_6->addLayout(horizontalLayout_5);


        verticalLayout_8->addLayout(verticalLayout_6);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_3);

        ledH = new QLineEdit(centralwidget);
        ledH->setObjectName(QString::fromUtf8("ledH"));
        sizePolicy.setHeightForWidth(ledH->sizePolicy().hasHeightForWidth());
        ledH->setSizePolicy(sizePolicy);
        ledH->setMinimumSize(QSize(100, 100));
        ledH->setBaseSize(QSize(125, 63));
        ledH->setStyleSheet(QString::fromUtf8("QLineEdit { border-radius: 100px; }"));

        horizontalLayout_8->addWidget(ledH);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_4);


        verticalLayout_8->addLayout(horizontalLayout_8);


        horizontalLayout_9->addLayout(verticalLayout_8);


        horizontalLayout_10->addLayout(horizontalLayout_9);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_11);


        verticalLayout_9->addLayout(horizontalLayout_10);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_9->addItem(verticalSpacer_4);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_9);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        verticalLayout_2->addWidget(label_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        Vmin = new QLineEdit(centralwidget);
        Vmin->setObjectName(QString::fromUtf8("Vmin"));
        Vmin->setMinimumSize(QSize(50, 25));
        Vmin->setMaximumSize(QSize(500, 250));
        Vmin->setFont(font1);
        Vmin->setStyleSheet(QString::fromUtf8("QLineEdit { text-align: center; }"));

        horizontalLayout_4->addWidget(Vmin);

        Vprom = new QLineEdit(centralwidget);
        Vprom->setObjectName(QString::fromUtf8("Vprom"));
        Vprom->setMinimumSize(QSize(50, 25));
        Vprom->setMaximumSize(QSize(500, 250));
        Vprom->setFont(font1);
        Vprom->setStyleSheet(QString::fromUtf8("QLineEdit { text-align: center; }"));

        horizontalLayout_4->addWidget(Vprom);

        Vmax = new QLineEdit(centralwidget);
        Vmax->setObjectName(QString::fromUtf8("Vmax"));
        Vmax->setMinimumSize(QSize(50, 25));
        Vmax->setMaximumSize(QSize(500, 250));
        Vmax->setFont(font1);
        Vmax->setStyleSheet(QString::fromUtf8("QLineEdit { text-align: center; }"));

        horizontalLayout_4->addWidget(Vmax);


        verticalLayout_2->addLayout(horizontalLayout_4);


        horizontalLayout_11->addLayout(verticalLayout_2);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_6);

        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_15);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("DejaVu Serif"));
        font2.setPointSize(12);
        label_5->setFont(font2);

        verticalLayout_3->addWidget(label_5);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        Pmin = new QLineEdit(centralwidget);
        Pmin->setObjectName(QString::fromUtf8("Pmin"));
        Pmin->setMinimumSize(QSize(50, 25));
        Pmin->setMaximumSize(QSize(500, 250));
        Pmin->setFont(font1);
        Pmin->setStyleSheet(QString::fromUtf8("QLineEdit { text-align: center; }"));

        horizontalLayout_2->addWidget(Pmin);

        Pprom = new QLineEdit(centralwidget);
        Pprom->setObjectName(QString::fromUtf8("Pprom"));
        Pprom->setMinimumSize(QSize(50, 25));
        Pprom->setMaximumSize(QSize(500, 250));
        Pprom->setFont(font1);
        Pprom->setStyleSheet(QString::fromUtf8("QLineEdit { text-align: center; }"));

        horizontalLayout_2->addWidget(Pprom);

        Pmax = new QLineEdit(centralwidget);
        Pmax->setObjectName(QString::fromUtf8("Pmax"));
        Pmax->setMinimumSize(QSize(50, 25));
        Pmax->setMaximumSize(QSize(500, 250));
        Pmax->setFont(font1);
        Pmax->setStyleSheet(QString::fromUtf8("QLineEdit { text-align: center; }"));

        horizontalLayout_2->addWidget(Pmax);


        verticalLayout_3->addLayout(horizontalLayout_2);


        horizontalLayout_11->addLayout(verticalLayout_3);


        horizontalLayout_12->addLayout(horizontalLayout_11);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_12);


        verticalLayout_9->addLayout(horizontalLayout_12);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_9->addItem(verticalSpacer_2);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_10);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);

        verticalLayout->addWidget(label_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        Dmin = new QLineEdit(centralwidget);
        Dmin->setObjectName(QString::fromUtf8("Dmin"));
        Dmin->setMinimumSize(QSize(50, 25));
        Dmin->setMaximumSize(QSize(500, 250));
        Dmin->setFont(font1);
        Dmin->setStyleSheet(QString::fromUtf8("QLineEdit { text-align: center; }"));

        horizontalLayout_3->addWidget(Dmin);

        Dprom = new QLineEdit(centralwidget);
        Dprom->setObjectName(QString::fromUtf8("Dprom"));
        Dprom->setMinimumSize(QSize(50, 25));
        Dprom->setMaximumSize(QSize(500, 250));
        Dprom->setFont(font1);
        Dprom->setStyleSheet(QString::fromUtf8("QLineEdit { text-align: center; }"));

        horizontalLayout_3->addWidget(Dprom);

        Dmax = new QLineEdit(centralwidget);
        Dmax->setObjectName(QString::fromUtf8("Dmax"));
        Dmax->setMinimumSize(QSize(50, 25));
        Dmax->setMaximumSize(QSize(500, 250));
        Dmax->setFont(font1);
        Dmax->setStyleSheet(QString::fromUtf8("QLineEdit { text-align: center; }"));

        horizontalLayout_3->addWidget(Dmax);


        verticalLayout->addLayout(horizontalLayout_3);


        horizontalLayout_13->addLayout(verticalLayout);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_7);

        horizontalSpacer_16 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_16);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("DejaVu Serif"));
        font3.setPointSize(11);
        font3.setBold(false);
        font3.setWeight(50);
        label_6->setFont(font3);

        verticalLayout_4->addWidget(label_6);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        Lmin = new QLineEdit(centralwidget);
        Lmin->setObjectName(QString::fromUtf8("Lmin"));
        Lmin->setMinimumSize(QSize(10, 5));
        Lmin->setMaximumSize(QSize(500, 250));
        Lmin->setFont(font1);
        Lmin->setStyleSheet(QString::fromUtf8("QLineEdit { text-align: center; }"));

        horizontalLayout->addWidget(Lmin);

        Lprom = new QLineEdit(centralwidget);
        Lprom->setObjectName(QString::fromUtf8("Lprom"));
        Lprom->setMinimumSize(QSize(10, 5));
        Lprom->setMaximumSize(QSize(500, 250));
        Lprom->setFont(font1);
        Lprom->setStyleSheet(QString::fromUtf8("QLineEdit { text-align: center; }"));

        horizontalLayout->addWidget(Lprom);

        Lmax = new QLineEdit(centralwidget);
        Lmax->setObjectName(QString::fromUtf8("Lmax"));
        Lmax->setMinimumSize(QSize(10, 5));
        Lmax->setMaximumSize(QSize(500, 250));
        Lmax->setFont(font1);
        Lmax->setStyleSheet(QString::fromUtf8("QLineEdit { text-align: center; }"));

        horizontalLayout->addWidget(Lmax);


        verticalLayout_4->addLayout(horizontalLayout);


        horizontalLayout_13->addLayout(verticalLayout_4);


        horizontalLayout_14->addLayout(horizontalLayout_13);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_13);


        verticalLayout_9->addLayout(horizontalLayout_14);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_9->addItem(verticalSpacer_3);


        gridLayout->addLayout(verticalLayout_9, 0, 0, 1, 1);

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
        label->setText(QCoreApplication::translate("MainWindow", "TEMPERATURA EN C\302\260", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "HUMEDAD EN %", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "VELOCIDAD EN m/s", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "PRECIPITACION EN mm", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "DIRECCION DEL VIENTO EN \302\260 NORTE", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "INTENSIDAD DE LUZ EN LUMENES", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
