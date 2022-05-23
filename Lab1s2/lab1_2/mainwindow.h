#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QPushButton>

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>

#include <QMouseEvent>

#include <QGridLayout>

#include<QLabel>

#include <QTimer>
#include <QTime>

#include "circle.h"
#include "star.h"
#include "square.h"
#include "rhomb.h"
#include "triang.h"
#include "pol.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void change_figure(int i,int* mass);

private slots:
    void on_horizontalSlider_2_sliderMoved(int position);

    void on_spinBox_2_valueChanged(int arg1);

    void on_spinBox_valueChanged(int arg1);

    void on_horizontalSlider_3_sliderMoved(int position);

    void on_radioButton_clicked();

    void star_button();

    void tr_check();

    void spbn_value(int i);

    void spbn_2_value(int i);

    void spbn_3_value(int i);

    void on_radioButton_2_clicked();

    void on_radioButton_3_clicked();

    void on_radioButton_4_clicked();

    void on_radioButton_5_clicked();

    void on_radioButton_6_clicked();

    void on_radioButton_7_clicked();

    void on_pushButton_pressed();

    void on_pushButton_2_pressed();

    void on_pushButton_7_pressed();

    void on_pushButton_8_pressed();

    void on_pushButton_6_pressed();

    void on_pushButton_9_pressed();

    void on_pushButton_3_pressed();

    void on_pushButton_5_pressed();

    void on_pushButton_11_pressed();

    void on_pushButton_10_pressed();

    void on_pushButton_12_pressed();

    void on_pushButton_13_pressed();

    void on_pushButton_4_clicked();

    void on_radioButton_8_clicked();

    void figure_add();

    virtual void mousePressEvent(QMouseEvent* e);
    virtual void mouseDoubleClickEvent(QMouseEvent *e);

private:
    Ui::MainWindow *ui;
    QGraphicsScene* scene;
    QTimer* timer;

    QLabel* title = new QLabel();
    double square;
    double perimeter ;
    int mass_center_x ;
    int mass_center_y ;
};

class DrawWindow: public MainWindow
{
    Q_OBJECT

public:
    DrawWindow();
private:
    Ui::MainWindow *ui_d;
    QGraphicsScene scene_d;

};

#endif // MAINWINDOW_H
