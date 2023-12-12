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

    // Agregar el icono de archivo a la ventana
    setWindowIcon(QIcon("../alse.png"));

    timer = new QTimer(this);

    // Conecta el temporizador a la función que manejará la actualización
    connect(timer, &QTimer::timeout, this, &MainWindow::actualizarCadaMinuto);

    // Llama a la función de actualización inmediatamente
    actualizarCadaMinuto();

    // Configura el temporizador para que se ejecute cada minuto (60000 milisegundos)
    timer->start(60000); // 60000
}

MainWindow::~MainWindow()
{
    delete ui;
}

MatrixXd MainWindow::abrir_db()
{
    MatrixXd R(6, 3);

    db = QSqlDatabase::addDatabase("QSQLITE"); // agrega la base de datos a qt
    db.setDatabaseName("../db_name.db");       // crea una conexion con la base de datos
    if (db.open())                             // abre la base de datos
    {
        qDebug() << "Base de datos abierta";
    }
    else
    {
        qDebug() << "Error al abrir la base de datos";
    }
    QString consulta = "SELECT MINIMO, PROMEDIO, MAXIMO FROM (SELECT ID, MINIMO, PROMEDIO, MAXIMO FROM sensores_pc ORDER BY ID DESC LIMIT 6) ORDER BY ID ASC";
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
        query.next();                                                                                // Avanza a la siguiente fila
        R.row(i) << query.value(0).toDouble(), query.value(1).toDouble(), query.value(2).toDouble(); // Asigna los valores de la fila a la matriz
    }
    db.close(); // Cierra la conexión
    return R;
}

void MainWindow::actualizarCadaMinuto()
{
    // construir matriz de interfaz
    MatrixXd R(6, 3);

    R = abrir_db();

    // paleta de colores
    QPalette palT = ui->ledT->palette();
    QPalette palH = ui->ledH->palette();

    // asignacion de temperatura
    ui->Tmin->setText(QString::number(R(0, 0)));
    ui->Tprom->setText(QString::number(R(0, 1)));
    ui->Tmax->setText(QString::number(R(0, 2)));

    ui->Tmin->setAlignment(Qt::AlignCenter);
    ui->Tprom->setAlignment(Qt::AlignCenter);
    ui->Tmax->setAlignment(Qt::AlignCenter);

    // asignacion de forma temperatura led
    QRect rectT(QPoint(), ui->ledT->size());
    QRegion region(rectT, QRegion::Ellipse);
    ui->ledT->setMask(region);

    QString color;
    if (R(0, 1) == 45 || R(0, 1) == -10)
    {
        color = "red";
        ui->ledT->setText("Warning");
    }
    else if (R(0, 1) < -5 || R(0, 1) > 40)
    {
        color = "orange";
        ui->ledT->setText("Caution");
    }
    else
    {
        color = "green";
        ui->ledT->setText("Well");
    }
    ui->ledT->setAlignment(Qt::AlignCenter);

    // Aplicar el color al QLineEdit
    QString styleSheetT = QString("QLineEdit { background-color: %1; }").arg(color);
    ui->ledT->setStyleSheet(styleSheetT);

    // asignacion de humedad
    ui->Hmin->setText(QString::number(R(1, 0)));
    ui->Hprom->setText(QString::number(R(1, 1)));
    ui->Hmax->setText(QString::number(R(1, 2)));

    ui->Hmin->setAlignment(Qt::AlignCenter);
    ui->Hprom->setAlignment(Qt::AlignCenter);
    ui->Hmax->setAlignment(Qt::AlignCenter);

    // asignacion forma de humedad led
    QRect rectH(QPoint(), ui->ledH->size());
    QRegion ledH(rectH, QRegion::Ellipse);
    ui->ledH->setMask(region);

    if (R(1, 1) == 100 || R(1, 1) == 0)
    {
        color = "red";
        ui->ledH->setText("Warning");
    }
    else if (R(1, 1) < 10 || R(1, 1) > 90)
    {
        color = "orange";
        ui->ledH->setText("Caution");
    }
    else
    {
        color = "green";
        ui->ledH->setText("Well");
    }
    ui->ledH->setAlignment(Qt::AlignCenter);

    // Aplicar el color al QLineEdit
    QString styleSheetH = QString("QLineEdit { background-color: %1; }").arg(color);
    ui->ledH->setStyleSheet(styleSheetH);

    // asignacion velocidad
    ui->Vmin->setText(QString::number(R(2, 0)));
    ui->Vprom->setText(QString::number(R(2, 1)));
    ui->Vmax->setText(QString::number(R(2, 2)));

    ui->Vmin->setAlignment(Qt::AlignCenter);
    ui->Vprom->setAlignment(Qt::AlignCenter);
    ui->Vmax->setAlignment(Qt::AlignCenter);

    // asignacion direccion de viento
    ui->Dmin->setText(QString::number(R(3, 0)));
    ui->Dprom->setText(QString::number(R(3, 1)));
    ui->Dmax->setText(QString::number(R(3, 2)));

    ui->Dmin->setAlignment(Qt::AlignCenter);
    ui->Dprom->setAlignment(Qt::AlignCenter);
    ui->Dmax->setAlignment(Qt::AlignCenter);

    ui->Pmin->setText(QString::number(R(4, 0)));
    ui->Pprom->setText(QString::number(R(4, 1)));
    ui->Pmax->setText(QString::number(R(4, 2)));

    // asignacion presipitacion
    ui->Pmin->setAlignment(Qt::AlignCenter);
    ui->Pprom->setAlignment(Qt::AlignCenter);
    ui->Pmax->setAlignment(Qt::AlignCenter);

    // asignacion luz
    ui->Lmin->setText(QString::number(R(5, 0)));
    ui->Lprom->setText(QString::number(R(5, 1)));
    ui->Lmax->setText(QString::number(R(5, 2)));

    ui->Lmin->setAlignment(Qt::AlignCenter);
    ui->Lprom->setAlignment(Qt::AlignCenter);
    ui->Lmax->setAlignment(Qt::AlignCenter);
}
