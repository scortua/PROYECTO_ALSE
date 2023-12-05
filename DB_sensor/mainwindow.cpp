#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <eigen3/Eigen/Dense>
#include <QMatrix>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_cmd_Operacion_clicked()
{
    //construir matriz de interfaz
    QMatrix R(3, 6);

    ui->Tmin->setText(QString::number(R(0, 0)));
    ui->Tprom->setText(QString::number(R(0, 1)));
    ui->Tmax->setText(QString::number(R(0, 2)));

    ui->Hmin->setText(QString::number(R(1, 0)));
    ui->Hprom->setText(QString::number(R(1, 1)));
    ui->Hmax->setText(QString::number(R(1, 2)));

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


