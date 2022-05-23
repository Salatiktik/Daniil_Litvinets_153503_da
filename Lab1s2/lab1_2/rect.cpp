#include "rect.h"

Rect::Rect(int x, int y)
{
    QColor t = QColor(106,5,206);
    setBrush(t);
    setRect(800,100,x,y);
    this->a = x;
    this->b = y;
}
