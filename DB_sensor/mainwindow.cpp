#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <eigen3/Eigen/Dense>

#include <QDebug>
#include <stdlib.h>
#include <QTimer>

#include <QSqlDatabase>
#include <QSqlQuery>

using Eigen::MatrixXd;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    timer = new QTimer(this);

    // Conecta el temporizador a la función que manejará la actualización
    connect(timer, &QTimer::timeout, this, &MainWindow::actualizarCadaMinuto);

    // Configura el temporizador para que se ejecute cada minuto (60000 milisegundos)
    timer->start(1000); // 60000
}

MainWindow::~MainWindow()
{
    delete ui;
}

MatrixXd MainWindow::abrir_db()
{
    MatrixXd R(6, 3);

    db = QSqlDatabase::addDatabase("QSQLITE"); // agrega la base de datos a qt
    db.setDatabaseName("base_datos.db"); // crea una conexion con la base de datos

    if (db.open()) // abre la base de datos
    {
        qDebug() << "Base de datos abierta";
    }
    else
    {
        qDebug() << "Error al abrir la base de datos";
    }

    QString consulta = "SELECT MINIMO, PROMEDIO, MAXIMO FROM (SELECT ID, MINIMO, PROMEDIO, MAXIMO FROM sensores ORDER BY ID DESC LIMIT 6) ORDER BY ID ASC";
    QSqlQuery query(db); // Asigna la conexión a la consulta

    if (query.prepare(consulta))
    {
        if (query.exec())
        {
            qDebug() << "Consulta realizada";
        }
        else
        {
            qDebug() << "Error al ejecutar la consulta";
        }
    }
    else
    {
        qDebug() << "Error al preparar la consulta";
    }

    for (int i = 0; i < 6; i++)
    {
        query.next();
        R.row(i) << query.value(0).toDouble(), query.value(1).toDouble(), query.value(2).toDouble();
    }

    db.close(); // Cierra la conexión

    return R;
}

void MainWindow::actualizarCadaMinuto()
{
    // construir matriz de interfaz
    MatrixXd R(6, 3);

    R = abrir_db();

    QPalette palT = ui->ledT->palette();
    QPalette palH = ui->ledH->palette();

    ui->Tmin->setText(QString::number(R(0, 0)));
    ui->Tprom->setText(QString::number(R(0, 1)));
    ui->Tmax->setText(QString::number(R(0, 2)));

    QRect rectT(QPoint(), ui->ledT->size());
    QRegion region(rectT,QRegion::Ellipse);
    ui->ledT->setMask(region);

    QString color;
    if (R(0,1) == 45 || R(0,1) == -10)
        color = "red";
    else if (R(0,1) < -5 || R(0,1) > 40)
        color = "orange";
    else
        color = "green";

    // Aplicar el color al QLineEdit
    QString styleSheetT = QString("QLineEdit { background-color: %1; }").arg(color);
    ui->ledT->setStyleSheet(styleSheetT);

    ui->Hmin->setText(QString::number(R(1, 0)));
    ui->Hprom->setText(QString::number(R(1, 1)));
    ui->Hmax->setText(QString::number(R(1, 2)));

    QRect rectH(QPoint(), ui->ledH->size());
    QRegion ledH(rectH,QRegion::Ellipse);
    ui->ledH->setMask(region);

    if (R(1,1) == 100 || R(1,1) == 0)
        color = "red";
    else if (R(1,1) < 10 || R(1,1) > 90)
        color = "orange";
    else
        color = "green";

    // Aplicar el color al QLineEdit
    QString styleSheetH = QString("QLineEdit { background-color: %1; }").arg(color);
    ui->ledH->setStyleSheet(styleSheetH);

    ui->Vmin->setText(QString::number(R(2, 0)));
    ui->Vprom->setText(QString::number(R(2, 1)));
    ui->Vmax->setText(QString::number(R(2, 2)));

    ui->Dmin->setText(QString::number(R(3, 0)));
    ui->Dprom->setText(QString::number(R(3, 1)));
    ui->Dmax->setText(QString::number(R(3, 2)));

    ui->Pmin->setText(QString::number(R(4, 0)));
    ui->Pprom->setText(QString::number(R(4, 1)));
    ui->Pmax->setText(QString::number(R(4, 2)));

    ui->Lmin->setText(QString::number(R(5, 0)));
    ui->Lprom->setText(QString::number(R(5, 1)));
    ui->Lmax->setText(QString::number(R(5, 2)));
}
