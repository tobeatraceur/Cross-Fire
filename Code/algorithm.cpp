#include "algorithm.h"

bool compare(const grid &grid1, const grid &grid2)//重写比较函数
{
    int g1 = grid1.f - grid1.h;
    int g2 = grid2.f - grid2.h;

    if(grid1.f < grid2.f)
        return true;
    else if(grid1.f == grid2.f && g1<g2)
        return true;
    else
        return false;

}

//局部的A*算法
int Astar(int type, int flag,int display_flag,int *count,int pos, int size, int posx, int posy, int g, grid *gp, QVector<grid> *open,QVector<grid> *close,QVector<int> *open_id,QVector<int> *close_id,QVector<int> *carrot_pos_x,QVector<int> *carrot_pos_y,QVector<int> *all_h)
{
    int h;
    int no_min;//h最小值对应的胡萝卜序号

    if(gp[pos].label->type !=3)
    {
        all_h->clear();
        if(flag == 1)
        {
            for(int i=0; i<carrot_pos_x->size(); i++)
            {
                all_h->append(abs(posx - 1 - carrot_pos_x->at(i)) + abs(posy - carrot_pos_y->at(i)));
            }
        }
        else if(flag == 2)
        {
            for(int i=0; i<carrot_pos_x->size(); i++)
            {
                all_h->append(abs(posx + 1 - carrot_pos_x->at(i)) + abs(posy - carrot_pos_y->at(i)));
            }
        }
        else if(flag == 3)
        {
            for(int i=0; i<carrot_pos_x->size(); i++)
            {
                all_h->append(abs(posx - carrot_pos_x->at(i)) + abs(posy - 1 - carrot_pos_y->at(i)));
            }
        }
        else if(flag == 4)
        {
            for(int i=0; i<carrot_pos_x->size(); i++)
            {
                all_h->append(abs(posx - carrot_pos_x->at(i)) + abs(posy + 1 - carrot_pos_y->at(i)));
            }
        }


        QVector<int>::Iterator h_iter = std::min_element(all_h->begin(), all_h->end());//找到最小值
        h = *h_iter;
        no_min = all_h->indexOf(h);

        int f ;
        if(type == 0)//选择算法类型
        {
            f = h + g + 1;
        }
        else if(type == 1)
        {
            f = h;
        }
        else if(type == 2)
        {
            f = g + 1;
        }

        if(h == 0)//已经到达
        {
            gp[pos].no_min = no_min;
            gp[pos].h = h;
            gp[pos].f = f;
            gp[pos].parent = posy * size + posx;

            carrot_pos_x->removeAt(no_min);
            carrot_pos_y->removeAt(no_min);

            open->clear();
            open_id->clear();
            close->clear();
            close_id->clear();
            open->append(gp[pos]);
            open_id->append(pos);
            return 0;
        }

        if(open_id->contains(pos))//更新open表
        {
            if(f < gp[pos].f)
            {
                gp[pos].f = f;
                gp[pos].parent = posy * size + posx;
            }

        }
        else if(!close_id->contains(pos))//加入open表
        {
            gp[pos].all_h = *all_h;
            gp[pos].no_min = no_min;
            gp[pos].h = h;
            gp[pos].f = f;
            gp[pos].parent = posy * size + posx;
            open->append(gp[pos]);
            open_id->append(pos);

            if(!gp[pos].visited)
            {
                if(display_flag != 1 && display_flag != 3)
                    gp[pos].label->setStyleSheet("background: rgb(255,255,255,50%)");
                *count = *count + 1;
            }
        }
    }
    return 1;
}

//全局搜索算法
void search(int type,grid_group* group,int display_flag)
{
    QVector<grid> open;
    QVector<grid> close;
    QVector<int> open_id;
    QVector<int> close_id;
    QVector<int> carrot_pos_x;
    QVector<int> carrot_pos_y;
    QVector<int> all_h;

    int size = group->size;
    int rabbit_pos;
    int rabbit_pos_x = -1;
    int rabbit_pos_y;   
    int h;
    int no_min;
    int step = 0;//路径步数
    int rabbit_flag = 0;//多个兔子标志位
    int count = 0;//拓展节点数
    int find_carrot = 0;//找到萝卜的数量
    grid * gp = group->gp;

    for(int i=0; i<size*size; i++)//刷新地图
    {
        gp[i].label->setText("");
        gp[i].label->setStyleSheet("background: transparent");
        gp[i].label->setStyleSheet("border:1px solid rgb(255,0,0,50%)");
        gp[i].step.clear();
        gp[i].parent = -1;
        gp[i].label->setAlignment(Qt::AlignCenter);
    }

    for(int i=0; i<size*size; i++)
    {
        if(gp[i].label->type == 1 && rabbit_flag == 0)
        {
            rabbit_pos_y = i/size;
            rabbit_pos_x = i%size;

            rabbit_pos = rabbit_pos_y*size+rabbit_pos_x;
            group->rabbit_position = rabbit_pos;
            rabbit_flag = 1;
        }
        else if(gp[i].label->type == 1 && rabbit_flag == 1)
        {
            QMessageBox::critical(NULL, "警告", "只能放置一个兔子！", QMessageBox::Yes, QMessageBox::Yes);
            return;
        }
        if(gp[i].label->type == 2)
        {
            carrot_pos_y.append(i/size);
            carrot_pos_x.append(i%size);
        }
    }

    if(rabbit_pos_x == -1 || carrot_pos_x.size() == 0)
    {
        QMessageBox::critical(NULL, "警告", "请放置好兔子和萝卜", QMessageBox::Yes, QMessageBox::Yes);
        return;
    }

    for(int i=0; i<carrot_pos_x.size(); i++)
    {
        gp[rabbit_pos].all_h.append(abs(rabbit_pos_x - carrot_pos_x[i]) + abs(rabbit_pos_y - carrot_pos_y[i]));
    }

    QVector<int>::Iterator h_iter = std::min_element(gp[rabbit_pos].all_h.begin(), gp[rabbit_pos].all_h.end());
    h = *h_iter;
    no_min = all_h.indexOf(h);

    gp[rabbit_pos].f = h;
    gp[rabbit_pos].h = h;
    gp[rabbit_pos].no_min = no_min;
    open.append(gp[rabbit_pos]);
    open_id.append(rabbit_pos);

    int end = -1;//路径终点
    int temp = 0; //用于暂存end

    while(true)
    {
        while(open.size() != 0)
        {
            qSort(open.begin(),open.end(),compare);//排序

            int posx = open.first().idx;
            int posy = open.first().idy;
            int pos1 = posy * size + posx - 1;
            int pos2 = posy * size + posx + 1;
            int pos3 = (posy-1) * size + posx;
            int pos4 = (posy+1) * size + posx;
            int g = open.first().f-open.first().h;

            close.append(gp[posy * size + posx]);
            close_id.append(posy * size + posx);
            open.removeFirst();
            open_id.removeAll(posy * size + posx);

            if(!gp[posy * size + posx].visited && display_flag != 1 && display_flag != 3)
            {
                gp[posy * size + posx].label->setStyleSheet("background: rgb(0,255,0,50%)");
            }

            if(posx-1>=0)//左
            {
                if(!Astar(type,1,display_flag,&count,pos1,size,posx,posy,g,gp,&open,&close,&open_id,&close_id,&carrot_pos_x,&carrot_pos_y,&all_h))
                {
                    end = pos1;

                    for(int i=0; i<open.size(); i++)
                    {
                        open[i].f = MAP_SIZE * MAP_SIZE;
                        open[i].h = MAP_SIZE * MAP_SIZE;
                        open[i].parent = -1;
                    }
                    for(int i=0; i<close.size(); i++)
                    {
                        close[i].f = MAP_SIZE * MAP_SIZE;
                        close[i].h = MAP_SIZE * MAP_SIZE;
                        close[i].parent = -1;
                    }
                    break;
                }
            }
            if(posx+1<size)//右
            {

                if(!Astar(type,2,display_flag,&count,pos2,size,posx,posy,g,gp,&open,&close,&open_id,&close_id,&carrot_pos_x,&carrot_pos_y,&all_h))
                {
                    end = pos2;

                    for(int i=0; i<open.size(); i++)
                    {
                        open[i].f = MAP_SIZE * MAP_SIZE;
                        open[i].h = MAP_SIZE * MAP_SIZE;
                        open[i].parent = -1;
                    }
                    for(int i=0; i<close.size(); i++)
                    {
                        close[i].f = MAP_SIZE * MAP_SIZE;
                        close[i].h = MAP_SIZE * MAP_SIZE;
                        close[i].parent = -1;
                    }
                    break;
                }
            }
            if(posy-1>=0)//上
            {
                if(!Astar(type,3,display_flag,&count,pos3,size,posx,posy,g,gp,&open,&close,&open_id,&close_id,&carrot_pos_x,&carrot_pos_y,&all_h))
                {
                    end = pos3;

                    for(int i=0; i<open.size(); i++)
                    {
                        open[i].f = MAP_SIZE * MAP_SIZE;
                        open[i].h = MAP_SIZE * MAP_SIZE;
                        open[i].parent = -1;
                    }
                    for(int i=0; i<close.size(); i++)
                    {
                        close[i].f = MAP_SIZE * MAP_SIZE;
                        close[i].h = MAP_SIZE * MAP_SIZE;
                        close[i].parent = -1;
                    }
                    break;
                }
            }
            if(posy+1<size)//下
            {
                if(!Astar(type,4,display_flag,&count,pos4,size,posx,posy,g,gp,&open,&close,&open_id,&close_id,&carrot_pos_x,&carrot_pos_y,&all_h))
                {
                    end = pos4;

                    for(int i=0; i<open.size(); i++)
                    {
                        open[i].f = MAP_SIZE * MAP_SIZE;
                        open[i].h = MAP_SIZE * MAP_SIZE;
                        open[i].parent = -1;
                    }
                    for(int i=0; i<close.size(); i++)
                    {
                        close[i].f = MAP_SIZE * MAP_SIZE;
                        close[i].h = MAP_SIZE * MAP_SIZE;
                        close[i].parent = -1;
                    }
                    break;
                }
            }

        }


        if(end == -1)
        {
            QMessageBox::critical(NULL, "警告", "不可到达，最短路径：" + QString::number(step+1) + "步\n已找到萝卜" + QString::number(find_carrot)+ "个", QMessageBox::Yes, QMessageBox::Yes);
            return;
        }

        find_carrot ++;
        temp = end;

        while(gp[end].parent >= 0)
        {
            step++;
            end = gp[end].parent;
        }

        end = temp;
        int step_count = step;

        while(gp[end].parent >= 0)//回溯
        {
            int last = end;
            gp[end].label->setStyleSheet("background: rgb(30,170,240,50%)");
            gp[end].step.append(step_count);

            if(gp[end].label->type == 0 && display_flag != 2 && display_flag != 3)
            {
                QFont ft;
                ft.setPointSize(gp[end].label->width()/4);
                ft.setWeight(QFont::Bold);
                gp[end].label->setAlignment(Qt::AlignHCenter);
                gp[end].label->setAlignment(Qt::AlignVCenter);
                gp[end].label->setFont(ft);
                gp[end].label->setText(gp[end].label->text() + " " + QString::number(step_count));
            }

            end = gp[end].parent;
            gp[last].parent = -2;
            gp[last].visited = true;
            step_count--;
        }

        if(carrot_pos_x.size() == 0)//搜索完毕
            break;
        else
        {
            end = -1;
        }
    }

   QMessageBox::information(NULL, "恭喜", "已到达，最短路径：" + QString::number(step+1) + "步\n共拓展节点：" + QString::number(count)+ "个\n已找到萝卜：" + QString::number(find_carrot)+ "个", QMessageBox::Yes, QMessageBox::Yes);
}
