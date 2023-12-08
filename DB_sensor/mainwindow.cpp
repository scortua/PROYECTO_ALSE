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

int MainWindow::callback(void *data, int columnCount, char **columnValues, char **columnNames)
{
    // Obtener el puntero a la matriz de resultados
    QVector<QVector<QString>> *matrizResultados = static_cast<QVector<QVector<QString>> *>(data);

    // Crear un vector para almacenar los valores de la fila actual
    QVector<QString> fila;

    // Iterar sobre las columnas y almacenar los valores en el vector
    for (int i = 0; i < columnCount; ++i)
    {
        fila.push_back(columnValues[i] ? columnValues[i] : "NULL");
    }

    // Agregar la fila a la matriz
    matrizResultados->push_back(fila);

    // Devolver 0 para continuar procesando las filas
    return 0;
}

void MainWindow::abrir_db()
{
    char *zErrMsg = 0;
    int rc;
    double gh = 0.;

    QString sqlRecuento = "SELECT COUNT(sensor) FROM sensores WHERE Temperatura IS NOT NULL";
    rc = sqlite3_exec(db, sqlRecuento.toUtf8().constData(), callback, nullptr, &zErrMsg);


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
