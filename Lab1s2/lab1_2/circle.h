#ifndef CIRCLE_H
#define CIRCLE_H

#include <QObject>
#include <QWidget>
#include <QGraphicsItem>
#include <QGraphicsEllipseItem>
#include <string>
#include <QTime>

class Circle: public QGraphicsEllipseItem
{
protected:
    int x,y,r;
public:
    Circle(int r);
    double square();
    double perimeter();
    std::string massCenter();
    void rotate(int position, int x, int y);

};

#endif // CIRCLE_H
