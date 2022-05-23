#ifndef RECT_H
#define RECT_H

#include <QGraphicsItem>
#include <QGraphicsRectItem>

#include <QObject>
#include <QWidget>
#include <string>
#include <QTime>

class Rect : public QGraphicsRectItem
{
public:
    Rect(int x, int y);
    int a;
    int b;
};

#endif // RECT_H
