#ifndef POL_H
#define POL_H

#include "figure.h"

class Pol : public Figure
{
public:
    QGraphicsPolygonItem* pol = new QGraphicsPolygonItem;
public:
    Pol(int n, int r);
};

#endif // POL_H
