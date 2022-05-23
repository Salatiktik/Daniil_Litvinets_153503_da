#include "pol.h"

#define pi 3.14159265358

Pol::Pol(int n, int r)
{
    QPolygonF pol_f;
    QPoint* coords_r = new QPoint[n];


    int x = 800, y = 100;
    for(int i = 0; i<n;i++)
    {
        coords_r[i]=QPoint(x+r*cos(pi*2*i/n),y+r*sin(pi*2*i/n));
    }
    for(int i = 0; i<n;i++)
    {
        pol_f<<coords_r[i];
    }

    pol_f<<coords_r[0];

    this->pol->setPolygon(pol_f);
}
