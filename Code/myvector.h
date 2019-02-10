#ifndef MYVECTOR_H
#define MYVECTOR_H


#include <QVector>
#include "grid.h"

template<class T>
class MyVector : public QVector<T>
{
public:
    MyVector<T>()
        :QVector<grid>()
    {}

    typedef QTypedArrayData<grid> Data;
    Data *d;
   // bool operator==(const MyVector<T> &v) const;

    //bool contain(grid grid1);

};



#endif // MYVECTOR_H
