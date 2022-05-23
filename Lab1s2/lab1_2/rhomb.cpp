#include "rhomb.h"

Rhomb::Rhomb(int d1, int d2)
{
    QPolygonF rhomb_f;

    int x = 800, y = 100;

    rhomb_f<<QPoint(x,y-(int)d1/2)<<QPoint(x-(int)d2/2,y)<<QPoint(x,y+(int)d1/2)<<QPoint(x+(int)d2/2,y);

    this->rhomb->setPolygon(rhomb_f);
}
