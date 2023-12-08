#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <eigen3/Eigen/Dense>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Eigen::MatrixXd abrir_db();

private slots:
    void actualizarCadaMinuto();

private:
    Ui::MainWindow *ui;
     QTimer *timer;  // Objeto QTimer
};
#endif // MAINWINDOW_H
