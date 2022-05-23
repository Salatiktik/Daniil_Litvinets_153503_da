#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <iostream>
#include <fstream>
#include <Windows.h>
#include <io.h>
#include <stdio.h>

#include <QFile>


#include <QPushButton>

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>

#include <QDebug>

#include <QTableView>


#include <QLabel>
#include <QStringList>

#include <QFileDialog>

#include <date.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void load_base();

private slots:
    void on_pushButton_clicked();

    void spbn_value(int i);

    void spbn_2_value(int i);

    void spbn_3_value(int i);

    void addNew();

    void delete_client();

    void on_pushButton_2_clicked();

    void rewrite_table();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void edit();

    bool checkFile(QString a);

private:
    Ui::MainWindow *ui;
    QGraphicsScene* scene;
    Date* dates =new Date[2];
};
#endif // MAINWINDOW_H
