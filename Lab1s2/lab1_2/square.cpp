#include "square.h"

Square::Square(int a) : Rect(a,a)
{
    QColor t = QColor(0,200,209);
    setBrush(t);
}
