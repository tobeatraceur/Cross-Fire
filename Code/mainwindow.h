#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"
#include <QDebug>
#include <qpainter.h>
#include "algorithm.h"
#include <QEventLoop>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    grid_group* group;//所有格子

    QImage map;

    QImage rabbit;

    QImage carrot;

    QImage fire;

    int display_flag=0; //设置显示方式，0：正常，1：只显示路径，2不显示步数,3：只显示路径且不显示步数


public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_pushButton_clicked();

    void on_pushButton_map_clicked();

    void on_pushButton_A_clicked();

    void on_pushButton_mc_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
