#ifndef ALGORITHM_H
#define ALGORITHM_H
#include "grid.h"
#include "grid_group.h"
#include "myvector.h"

bool compare(const grid &grid1, const grid &grid2);

int Astar(int type, int flag,int display_flag,int *count,int pos, int size, int posx, int posy, int g, grid *gp, QVector<grid> *open,QVector<grid> *close,QVector<int> *open_id,QVector<int> *close_id,QVector<int> *carrot_pos_x,QVector<int> *carrot_pos_y,QVector<int> *all_h);

void search(int type,grid_group* group,int display_flag);

#endif // ALGORITHM_H
