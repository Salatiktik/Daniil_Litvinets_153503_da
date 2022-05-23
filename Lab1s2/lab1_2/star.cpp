#include "star.h"
#include <QPainter>

#define pi 3.14159265358

Star::Star(int n, int r, int R)
{
    //QGraphicsPolygonItem* star = new QGraphicsPolygonItem();
    QPolygonF star_f;
    QPoint* coords_R = new QPoint [n];
    QPoint* coords_r = new QPoint[n];


    int x = 800, y = 100;
    for(int i = 0; i<n;i++)
    {
        coords_r[i]=QPoint(x+r*cos(pi*2*i/n),y+r*sin(pi*2*i/n));
    }
    for(int i = 0; i<n;i++)
    {
        coords_R[i]=QPoint(x+R*cos(pi*(2*i+1)/n), y+R*sin(pi*(2*i+1)/n));
    }
    for(int i = 0; i<n;i++)
    {
        star_f<<coords_r[i]<<coords_R[i];
    }

    star_f<<coords_r[0];

    this->star->setPolygon(star_f);
}
