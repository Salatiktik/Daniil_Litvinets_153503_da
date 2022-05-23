#include "circle.h"
#include <QGraphicsEllipseItem>

Circle::Circle(int r)
{
    QColor a = QColor(rand()%256,rand()%256,rand()%256);
    setBrush(a);
    setRect(800,100,r,r);
    this->r = r;
}

double Circle::square()
{
    return this->r * this->r * 3.1415;
}

double Circle::perimeter()
{
    return this->r * 2 * 3.1415;
}

std::string Circle:: massCenter()
{
    return std::to_string(this->x+this->r)+std::to_string(this->y+this->r);
}
