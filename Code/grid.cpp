#include "grid.h"

grid::grid(QWidget *parent, int type, int length, int i, int j, QImage* rabbit, QImage* carrot, QImage *fire)
{


    grid::idx = j;
    grid::idy = i;
    grid::label = new MyLabel(parent,length, rabbit, carrot, fire);
    grid::label->type = type;

    grid::label->setGeometry(MAP_POS+i*length,MAP_POS+j*length,length,length);
    grid::label->setStyleSheet("background:transparent");
    grid::label->setStyleSheet("border:1px solid rgb(255,0,0,50%)");

    QObject::connect(grid::label, SIGNAL(rightButtonClicked()), grid::label, SLOT(slot_right_clicked()));
    QObject::connect(grid::label, SIGNAL(midButtonClicked()), grid::label, SLOT(slot_mid_clicked()));
    QObject::connect(label->timer, SIGNAL(timeout()), grid::label, SLOT(slot_left_clicked()));
}

void grid::set_rabbit(QImage* rabbit,int length)
{
    QImage _rabbit = (*rabbit).scaled(length,
                      length,
                      Qt::KeepAspectRatio
                      );

    grid::label->setAlignment(Qt::AlignCenter);
    grid::label->type = 1;
    grid::label->setPixmap(QPixmap::fromImage(_rabbit));

}

void grid::set_carrot(QImage* carrot,int length)
{
    QImage _carrot = (*carrot).scaled(length,
                      length,
                                      Qt::KeepAspectRatio
                      );
    grid::label->setAlignment(Qt::AlignCenter);
    grid::label->type = 2;
    grid::label->setPixmap(QPixmap::fromImage(_carrot));

}

void grid::set_block(QImage *fire, int length)
{
    grid::label->type = 3;
    QImage _fire = (*fire).scaled(length,
                      length
                      );
    grid::label->setPixmap(QPixmap::fromImage(_fire));
}

