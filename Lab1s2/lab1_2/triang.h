#ifndef TRIANG_H
#define TRIANG_H

#include "figure.h"

class Triang : public Figure
{
public:
    Triang(int a, int b, int c);
    QGraphicsPolygonItem* tr = new QGraphicsPolygonItem;
};

#endif // TRIANG_H
