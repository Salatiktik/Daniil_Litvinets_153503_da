#include "triang.h"
#include <QColor>

Triang::Triang(int a, int b, int c)
{
    QPolygonF tr_f;
    QColor t = QColor(45,8,9);
    setBrush(t);

    int x = 800, y = 100;

    tr_f << QPoint(x,y) << QPoint(x+c,y) << QPoint(x+c+(a*a-b*b-c*c)/(2*c),y+b*(1-pow((a*a-b*b-c*c)/(2*c*b),2)));
    this->tr->setPolygon(tr_f);
}
