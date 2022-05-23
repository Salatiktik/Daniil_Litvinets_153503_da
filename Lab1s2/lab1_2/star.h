#ifndef STAR_H
#define STAR_H

#include "figure.h"
#include <QPolygonF>


class Star: public Figure
{
public:
    QGraphicsPolygonItem* star = new QGraphicsPolygonItem;
public:
    Star(int n, int r, int R);
    int perimeter();
    std::string mass_center();
};

#endif // STAR_H
