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

MatrixXd MainWindow::abrir_db()
{
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;

    // Abrir la base de datos
    rc = sqlite3_open("base_datos.db", &db);  // Reemplaza con la ruta correcta

    // Crear la SQL statement para obtener los últimos 6 registros
    const char *sql = "SELECT MINIMO, PROMEDIO, MAXIMO FROM sensores ORDER BY ID DESC LIMIT 6;";

    // Vector para almacenar los resultados
    std::vector<std::vector<std::string>> matrizResultados;

    // Función de devolución de llamada para procesar los resultados
    auto callback = [](void *data, int columnCount, char **columnValues, char **columnNames) -> int {
        auto &matrizResultados = *static_cast<std::vector<std::vector<std::string>> *>(data);

        // Crear un vector para almacenar los valores de la fila actual
        std::vector<std::string> fila;

        // Iterar sobre las columnas y almacenar los valores en el vector
        for (int i = 0; i < columnCount; ++i)
        {
            fila.push_back(columnValues[i] ? columnValues[i] : "NULL");
        }

        // Agregar la fila a la matriz
        matrizResultados.push_back(fila);

        // Devolver 0 para continuar procesando las filas
        return 0;
    };

    // Ejecutar la consulta SQL y procesar los resultados
    rc = sqlite3_exec(db, sql, callback, &matrizResultados, &zErrMsg);

    // Cerrar la base de datos después de usarla
    sqlite3_close(db);

    // Obtener las dimensiones de la matriz de resultados
    int filas = matrizResultados.size();
    int columnas = (filas > 0) ? matrizResultados[0].size() : 0;

    // Crear una matriz Eigen::MatrixXd con las mismas dimensiones
    MatrixXd matriz(filas, columnas);

    // Copiar los datos de la matriz de resultados a la matriz Eigen
    for (int i = 0; i < filas; ++i)
    {
        for (int j = 0; j < columnas; ++j)
        {
            // Convertir cada elemento de string a double
            matriz(i, j) = std::stod(matrizResultados[i][j]);
        }
    }

    return matriz;
}

void MainWindow::actualizarCadaMinuto()
{
    // construir matriz de interfaz
    MatrixXd R(3, 6);

    R = abrir_db();

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
