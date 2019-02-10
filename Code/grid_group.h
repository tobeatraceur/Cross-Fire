#ifndef GRID_GROUP_H
#define GRID_GROUP_H

#include "grid.h"
#include <QObject>
#include <QtGlobal>
#include <QList>
#include <QTime>

class grid_group
{

public:
    grid_group(QWidget* parent=NULL, int size=4, QImage * rabbit=0, QImage * carrot=0, QImage * fire=0,float ratio=0.1);

    grid gp[32 * 32];

    int size;

    void delete_gp();

    void show();

    int rabbit_position=0;
};

#endif // GRID_GROUP_H
