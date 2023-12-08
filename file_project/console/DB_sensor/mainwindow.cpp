#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <eigen3/Eigen/Dense>
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#include <QTimer>

using Eigen::MatrixXd;
using namespace std;

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

MatrixXd abrir_db()
{
    sqlite3 *db;
    sqlite3_open("~/Projects/PROYECTO_ALSE/file_project/console/build/base_datos.db", &db);

    vector<vector<double>> results;

    auto callback = [](void* data, int cols, char** values, char** names) -> int {
        auto& results = *static_cast<vector<vector<double>>*>(data);
        vector<double> row;
        for (int i = 0; i < cols; ++i)
        {
            row.push_back(std::stod(values[i]));
        }
        results.push_back(row);
        return 0;
    };

    char *errMsg;
    sqlite3_exec(db, "SELECT MINIMO, PROMEDIO, MAXIMO FROM sensores ORDER BY ID DESC LIMIT 6;", callback, &results, &errMsg);

    sqlite3_close(db);

    // Convert the results to an Eigen::MatrixXd
    MatrixXd matrix(results.size(), results[0].size());
    for (int i = 0; i < results.size(); ++i)
        for (int j = 0; j < results[0].size(); ++j)
            matrix(i, j) = results[i][j];

    return matrix;
}

void MainWindow::actualizarCadaMinuto()
{
    // construir matriz de interfaz
    MatrixXd R = abrir_db();

    QPalette palT = ui->ledT->palette();
    QPalette palH = ui->ledH->palette();

    ui->Tmin->setText(QString::number(R(0, 0)));
    ui->Tprom->setText(QString::number(R(1, 0)));
    ui->Tmax->setText(QString::number(R(2, 0)));

    if ((R(1, 0) == -10) || (R(1, 0) == 45))
    {
        palH.setColor(QPalette::Button, QColor(Qt::red));
        ui->ledT->setAutoFillBackground(true);
        ui->ledT->setPalette(palT);
        ui->ledT->update();
    }
    else if ((R(1, 0) <= -5) || (R(1, 0) >= 40))
    {
        palH.setColor(QPalette::Button, QColor(Qt::yellow));
        ui->ledT->setAutoFillBackground(true);
        ui->ledT->setPalette(palT);
        ui->ledT->update();
    }
    else
    {
        palH.setColor(QPalette::Button, QColor(Qt::green));
        ui->ledT->setAutoFillBackground(true);
        ui->ledT->setPalette(palT);
        ui->ledT->update();
    }

    ui->Hmin->setText(QString::number(R(0, 1)));
    ui->Hprom->setText(QString::number(R(1, 1)));
    ui->Hmax->setText(QString::number(R(2, 1)));

    if ((R(1, 1) == 100) || (R(1, 1) == 0))
    {
        palT.setColor(QPalette::Button, QColor(Qt::red));
        ui->ledH->setAutoFillBackground(true);
        ui->ledH->setPalette(palT);
        ui->ledH->update();
    }
    else if ((R(1, 1) <= 10) || (R(1, 1) >= 90))
    {
        palT.setColor(QPalette::Button, QColor(Qt::yellow));
        ui->ledH->setAutoFillBackground(true);
        ui->ledH->setPalette(palT);
        ui->ledH->update();
    }
    else
    {
        palT.setColor(QPalette::Button, QColor(Qt::green));
        ui->ledH->setAutoFillBackground(true);
        ui->ledH->setPalette(palT);
        ui->ledH->update();
    }

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
