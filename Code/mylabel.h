#ifndef MYLABEL_H
#define MYLABEL_H
#include <QMainWindow>
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QMouseEvent>
#include <QTimer>



class MyLabel: public QLabel
{
    Q_OBJECT
public:
    MyLabel(QWidget * parent = 0,int length=0,QImage* rabbit=0,QImage* carrot=0, QImage * fire=0, int type=0);

    int length;

    QImage* rabbit;

    QImage* carrot;

    QImage * fire;

    QTimer *timer;

    int type;//格子类型0: space, 1:rabbit, 2:carrot, 3: block

    int click_times=0;//左键点击次数

    static int disable_flag;//地图是否发生变化标志位，用于禁用动画演示按钮


public slots:

    void slot_left_clicked();

    void slot_right_clicked();

    void slot_mid_clicked();

private:

protected:

    virtual void mouseReleaseEvent(QMouseEvent * ev);

signals:

    void leftButtonClicked();

    void rightButtonClicked();

    void midButtonClicked();

    void DoubleClicked();
};



#endif // MYLABEL_H
