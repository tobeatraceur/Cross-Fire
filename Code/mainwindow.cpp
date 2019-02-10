#include "mainwindow.h"




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowFlags(windowFlags()&~Qt::WindowMaximizeButtonHint);    // 禁止最大化按钮

    setFixedSize(this->width(),this->height());                     // 禁止拖动窗口大小

    setWindowIcon(QIcon("CF.ico"));//设置图标

    setAutoFillBackground(true);//设置背景
    QPalette pal = this->palette();
    QImage background;
    background.load(":/image/background.jpg");
    background = background.scaled(this->frameGeometry().width(),
                      this->frameGeometry().height()
                      );
    pal.setBrush(backgroundRole(), QPixmap::fromImage(background));
    setPalette(pal);

    ui->label->setGeometry(MAP_POS,MAP_POS,MAP_SIZE,MAP_SIZE);//设置地图
    map.load(":/image/map.jpg");
    map = map.scaled(MAP_SIZE,
                      MAP_SIZE,
                      Qt::KeepAspectRatio);
    QPixmap _map = QPixmap::fromImage(map);
    QPixmap tmpmap(_map.size());
    tmpmap.fill(Qt::transparent);
    QPainter p1(&tmpmap);
    p1.setCompositionMode(QPainter::CompositionMode_Source);
    p1.drawPixmap(0, 0, _map);
    p1.setCompositionMode(QPainter::CompositionMode_DestinationIn);
    p1.fillRect(tmpmap.rect(), QColor(0, 0, 0, 100));
    p1.end();
    ui->label->setPixmap(_map);

    fire.load(":/image/fire.jpg");
    rabbit.load(":/image/rabbit.png");
    carrot.load(":/image/carrot.png");
    group = new grid_group(this,4,&rabbit,&carrot,&fire);
    ui->pushButton_2->setDisabled(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()//贪婪搜索
{
    if(ui->checkBox->isChecked())//确认显示设置选项
    {
        if(ui->checkBox_2->isChecked())
            display_flag = 3;
        else
            display_flag = 1;
    }
    else if (ui->checkBox_2->isChecked())
        display_flag = 2;
    else
        display_flag = 0;

    search(1,group,display_flag);

    ui->pushButton_2->setEnabled(true);
    MyLabel::disable_flag = 0;
}

void MainWindow::on_pushButton_map_clicked()//生成新地图
{
    int size = pow(2, ui->comboBox->currentIndex()+2);
    float ratio = (float)(ui->comboBox_2->currentIndex()+1) * 0.1;

    group->delete_gp();
    *group = grid_group(this,size,&rabbit,&carrot, &fire, ratio);
    group->show();
}

void MainWindow::on_pushButton_A_clicked()//一致代价搜索
{
    if(ui->checkBox->isChecked())
    {
        if(ui->checkBox_2->isChecked())
            display_flag = 3;
        else
            display_flag = 1;
    }
    else if (ui->checkBox_2->isChecked())
        display_flag = 2;
    else
        display_flag = 0;

    search(2,group,display_flag);
    ui->pushButton_2->setEnabled(true);
    MyLabel::disable_flag = 0;
}

void MainWindow::on_pushButton_mc_clicked()//A*搜索
{
    if(ui->checkBox->isChecked())
    {
        if(ui->checkBox_2->isChecked())
            display_flag = 3;
        else
            display_flag = 1;
    }
    else if (ui->checkBox_2->isChecked())
        display_flag = 2;
    else
        display_flag = 0;

    search(0,group,display_flag);
    ui->pushButton_2->setEnabled(true);
    MyLabel::disable_flag = 0;
}

void MainWindow::on_pushButton_2_clicked()//动画演示
{
    if(MyLabel::disable_flag == 1)//地图改变但尚未搜索
    {
        QMessageBox::information(NULL, "提示", "请先搜索", QMessageBox::Yes, QMessageBox::Yes);
        return;
    }
    else//禁用按钮
    {
        ui->pushButton_mc->setDisabled(true);
        ui->pushButton_2->setDisabled(true);
        ui->pushButton_A->setDisabled(true);
        ui->pushButton_map->setDisabled(true);
        ui->pushButton->setDisabled(true);
    }

    int step = 1;
    int flag = -1;//标记动画结束,-1表示没有搜索，0表示结束
    int size = group->size;
    int pos = group->rabbit_position;
    int posx = pos % size;
    int posy = pos / size;
    int pos1 = posy * size + posx - 1;
    int pos2 = posy * size + posx + 1;
    int pos3 = (posy-1) * size + posx;
    int pos4 = (posy+1) * size + posx;
    int length = MAP_SIZE / size;

    grid* gp = group->gp;

    QImage _rabbit;
    _rabbit = rabbit.scaled(length,
                      length,
                      Qt::KeepAspectRatio
                      );
    QImage _carrot;
    _carrot = carrot.scaled(length,
                      length,
                      Qt::KeepAspectRatio
                      );

    while(true)
    {
        gp[pos].label->clear();

        if(gp[pos].label->type == 2)
        {
            gp[pos].label->setPixmap(QPixmap::fromImage(_carrot));
            gp[pos].label->setAlignment(Qt::AlignCenter);
        }

        if(posx-1>=0)
        {
            if(gp[pos1].step.contains(step))
            {
                gp[pos1].label->setPixmap(QPixmap::fromImage(_rabbit));
                gp[pos1].label->setAlignment(Qt::AlignCenter);
                pos = pos1;
                flag = 1;
            }
        }
        if(posx+1<size)
        {
            if(gp[pos2].step.contains(step))
            {
                gp[pos2].label->setPixmap(QPixmap::fromImage(_rabbit));
                gp[pos2].label->setAlignment(Qt::AlignCenter);
                pos = pos2;
                flag = 1;
            }
        }
        if(posy-1>=0)
        {
            if(gp[pos3].step.contains(step))
            {
                gp[pos3].label->setPixmap(QPixmap::fromImage(_rabbit));
                gp[pos3].label->setAlignment(Qt::AlignCenter);
                pos = pos3;
                flag = 1;
            }
        }
        if(posy+1<size)
        {
            if(gp[pos4].step.contains(step))
            {
                gp[pos4].label->setPixmap(QPixmap::fromImage(_rabbit));
                gp[pos4].label->setAlignment(Qt::AlignCenter);
                pos = pos4;
                flag = 1;
            }

        }

        posx = pos % size;
        posy = pos / size;
        pos1 = posy * size + posx - 1;
        pos2 = posy * size + posx + 1;
        pos3 = (posy-1) * size + posx;
        pos4 = (posy+1) * size + posx;

        step++;


        if(flag == 0)
        {
            gp[group->rabbit_position].label->setPixmap(QPixmap::fromImage(_rabbit));
            gp[group->rabbit_position].label->setAlignment(Qt::AlignCenter);
            QMessageBox::information(NULL, "恭喜", "显示完毕", QMessageBox::Yes, QMessageBox::Yes);
            break;
        }
        else if(flag == -1)
        {

            gp[group->rabbit_position].label->setPixmap(QPixmap::fromImage(_rabbit));
            gp[group->rabbit_position].label->setAlignment(Qt::AlignCenter);

            QMessageBox::information(NULL, "提示", "请先搜索", QMessageBox::Yes, QMessageBox::Yes);
            break;
        }

        flag = 0;

        QEventLoop eventloop;//暂停一段时间
        QTimer::singleShot(100, &eventloop, SLOT(quit()));
        eventloop.exec();
    }

    ui->pushButton_mc->setEnabled(true);
    ui->pushButton_2->setEnabled(true);
    ui->pushButton_A->setEnabled(true);
    ui->pushButton_map->setEnabled(true);
    ui->pushButton->setEnabled(true);
}
