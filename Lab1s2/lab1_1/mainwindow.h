#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>

#include <QGraphicsEllipseItem>
#include <QGraphicsLineItem>

#include <QTimer>
#include <QTime>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class spokes : public QGraphicsLineItem
{
public:
    int x1,x2,y1,y2;
    void advance(int phase);
    void rotation_speed();
    spokes(int i);
};

class wheel : public QGraphicsEllipseItem{
public:
    wheel();

private:


};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void createWheel();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene* scene;
    QTimer* timer;
};
#endif // MAINWINDOW_H
