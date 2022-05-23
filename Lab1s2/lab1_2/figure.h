#ifndef FIGURE_H
#define FIGURE_H

#include <QObject>
#include <QWidget>
#include <QGraphicsItem>
#include <QGraphicsPolygonItem>
#include <QDebug>

class Figure: public QGraphicsPolygonItem
{
public:
    double square();
    double perimeter();
    int* massCenter();
};

#endif // FIGURE_H
