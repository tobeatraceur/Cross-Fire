#ifndef GRID_H
#define GRID_H

#include "mylabel.h"


#define MAP_SIZE 512
#define MAP_POS 50

class grid
{

public:

    MyLabel* label;

    grid(QWidget* parent=0, int type=0, int length=MAP_SIZE/4, int i=0, int j=0, QImage * rabbit=0, QImage * carrot=0, QImage * fire=0);

    void set_rabbit(QImage * rabbit, int length);

    void set_carrot(QImage * carrot, int length);

    void set_block(QImage * fire, int length);

    bool visited = false;//标记是否被访问过

    int f = MAP_SIZE * MAP_SIZE ;//相当于正无穷

    int h = MAP_SIZE * MAP_SIZE ;//相当于正无穷

    QVector<int> all_h;//存储到每个胡萝卜的h值

    int no_min;//存储最小的h对应的胡萝卜序号

    int idx = 0;//该格子横坐标

    int idy = 0;

    int parent = -1;//父节点

    QVector<int> step;//存储途径该节点时是第几步

};




#endif // GRID_H
