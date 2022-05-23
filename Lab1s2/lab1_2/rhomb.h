#ifndef RHOMB_H
#define RHOMB_H

#include "figure.h"
#include <QPolygonF>

class Rhomb : public Figure
{
public:
    QGraphicsPolygonItem* rhomb = new QGraphicsPolygonItem;
public:
    Rhomb(int d1, int d2);
};

#endif // RHOMB_H
