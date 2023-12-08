#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <eigen3/Eigen/Dense>
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#include <QTimer>

using Eigen::MatrixXd;

sqlite3 *db;
QString sql;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
   ui->setupUi(this);

   ui->ledT->setStyleSheet("QLineEdit { border-radius: 100px; }");
   ui->ledH->setStyleSheet("QLineEdit { border-radius: 100px; }");

   timer = new QTimer(this);

       // Conecta el temporizador a la función que manejará la actualización
       connect(timer, &QTimer::timeout, this, &MainWindow::actualizarCadaMinuto);

       // Configura el temporizador para que se ejecute cada minuto (60000 milisegundos)
       timer->start(60000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::abrir_db()
{
    char *zErrMsg = 0;
    int rc;
    double gh = 0.;

    /* Open database */
    rc = sqlite3_open("sensores.db", &db);
    /* Create SQL statement */
    sql = "SELECT COUNT(sensor) FROM sensores WHERE Temperatura";
    rc = sqlite3_exec(db, sql.c_str(), callback, (void *)&gh, &zErrMsg);
    sql = "SELECT WHERE  FROM sensores;";
}

void MainWindow::actualizarCadaMinuto()
{
    // construir matriz de interfaz
    MatrixXd R(3, 6);

    ui->Tmin->setText(QString::number(R(0, 0)));
    ui->Tprom->setText(QString::number(R(1, 0)));
    ui->Tmax->setText(QString::number(R(2, 0)));

    ui->Hmin->setText(QString::number(R(0, 1)));
    ui->Hprom->setText(QString::number(R(1, 1)));
    ui->Hmax->setText(QString::number(R(2, 1)));

    ui->Vmin->setText(QString::number(R(0, 2)));
    ui->Vprom->setText(QString::number(R(1, 2)));
    ui->Vmax->setText(QString::number(R(2, 2)));

    ui->Dmin->setText(QString::number(R(0, 3)));
    ui->Dprom->setText(QString::number(R(1, 3)));
    ui->Dmax->setText(QString::number(R(2, 3)));

    ui->Pmin->setText(QString::number(R(0, 4)));
    ui->Pprom->setText(QString::number(R(1, 4)));
    ui->Pmax->setText(QString::number(R(2, 4)));

    ui->Lmin->setText(QString::number(R(0, 5)));
    ui->Lprom->setText(QString::number(R(1, 5)));
    ui->Lmax->setText(QString::number(R(2, 5)));

}
