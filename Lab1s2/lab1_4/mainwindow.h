#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <iostream>
#include <fstream>
#include <Windows.h>
#include <io.h>
#include <stdio.h>

#include <QFile>

#include <QSpinBox>
#include <QLineEdit>

#include <QPushButton>

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>

#include <QDebug>

#include <QTableView>


#include <QLabel>
#include <QStringList>

#include <QFileDialog>


#include <restaurant.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void addNewOrder();

    void addNewDish();

    void on_pushButton_clicked();

    void title(QString a);

    void category(QString a);

    void price(double a);

    void on_pushButton_3_clicked();

    void delete_dish();

    void delete_order();

    void rewriteTableDish();

    void rewriteTableOrder();

    void spbn_value(int i);

    void spbn_2_value(int i);

    void spbn_3_value(int i);

    void editDish();

    void on_pushButton_2_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_8_clicked();

    void qsort(int start, int end);

    void loadBase();

    void on_pushButton_9_clicked();

    void on_pushButton_5_clicked();

    bool checkFile(QString a);

private:
    Ui::MainWindow *ui;
    Food* dishes = new Food[1];
    Order* orders = new Order[1];
};
#endif // MAINWINDOW_H
