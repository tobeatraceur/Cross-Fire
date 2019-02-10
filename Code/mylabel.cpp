#include "mylabel.h"

int MyLabel::disable_flag = 0;
MyLabel::MyLabel(QWidget * parent, int length, QImage * rabbit, QImage * carrot, QImage *fire, int type) : QLabel(parent)
{
    MyLabel::length = length;
    MyLabel::rabbit = rabbit;
    MyLabel::carrot = carrot;
    MyLabel::fire= fire;
    MyLabel::type = type;
    timer = new QTimer(this);

}

void MyLabel::mouseReleaseEvent(QMouseEvent * ev)//鼠标响应事件
{
   Q_UNUSED(ev)

    if (Qt::LeftButton == ev->button())
    {
        click_times++;
        timer->start(250);
    }
    else if (Qt::RightButton == ev->button())
    {
        emit rightButtonClicked();
    }
    else if (Qt::MidButton == ev->button())
    {
        emit midButtonClicked();
    }
}

void MyLabel::slot_mid_clicked()//滚轮单击放置障碍
{


    QImage _fire;
    _fire = fire->scaled(length,
                      length
                      );
    MyLabel::setPixmap(QPixmap::fromImage(_fire));

    MyLabel::type = 3;
    disable_flag = 1;

}

void MyLabel::slot_left_clicked()
{
    timer->stop();
    if(1==click_times)//左键单击放置兔子
    {
        QImage _rabbit;
        _rabbit = rabbit->scaled(length,
                          length,
                                 Qt::KeepAspectRatio
                          );
        MyLabel::setAlignment(Qt::AlignCenter);
        MyLabel::setPixmap(QPixmap::fromImage(_rabbit));
        MyLabel::type = 1;
        disable_flag = 1;

    }
    else if(2==click_times)//双击清空格子
    {

        MyLabel::clear();
        MyLabel::setStyleSheet("background:transparent");
        MyLabel::setStyleSheet("border:1px solid rgb(255,0,0,50%)");
        MyLabel::type = 0;
        disable_flag = 1;

    }
    click_times = 0;

}

void MyLabel::slot_right_clicked()//右键单击萝卜
{
    QImage _carrot;
    _carrot = carrot->scaled(length,
                      length,
                             Qt::KeepAspectRatio
                      );
    MyLabel::setAlignment(Qt::AlignCenter);
    MyLabel::setPixmap(QPixmap::fromImage(_carrot));
    MyLabel::type = 2;
    disable_flag = 1;
}
