#include "grid_group.h"

grid_group::grid_group(QWidget *parent, int size, QImage* rabbit, QImage* carrot, QImage *fire, float ratio)
{
    QList<int> random;//生成随机障碍物
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    for(int i=0; i<(float)size*(float)size*ratio; i++)
    {
        int test =qrand()%(size*size);
        random.append(test);
    }

    for(int i=0; i<size; i++)//逐个生成格子
    {
        for(int j=0; j<size; j++)
        {

            grid new_grid = grid(parent,0,MAP_SIZE/size,i,j,rabbit,carrot,fire);

            if(i==0 && j==0)
            {
                new_grid.set_rabbit(rabbit,MAP_SIZE/size);
            }
            else if(i==size-1 && j==size-1)
            {
                new_grid.set_carrot(carrot,MAP_SIZE/size);
            }
            else if(random.contains(i * size + j))
            {
                new_grid.set_block(fire,MAP_SIZE/size);
            }
            grid_group::gp[i * size + j] = new_grid;

            grid_group::size = size;

        }
    }
}

void grid_group::delete_gp()
{
    for(int i=0; i<size; i++)
    {
        for(int j=0; j<size; j++)
        {
            delete grid_group::gp[i * size + j].label;
        }
    }
}

void grid_group::show()
{
    for(int i=0; i<size; i++)
    {
        for(int j=0; j<size; j++)
        {
            grid_group::gp[i * size + j].label->show();

        }
    }
}


