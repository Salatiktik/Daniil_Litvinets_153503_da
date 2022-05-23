#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    srand(time(0));
}

MainWindow::~MainWindow()
{
    delete ui;
}

int convert_key(QString g)
{
    std::string a = g.toStdString();
    int key = 0;
    for(int i = 1; i<g.length();i++)
    {
        key+=a[i]*pow(i,i);
    }
    qDebug()<< key;
    qDebug() << "rand" << rand();
    return abs(key);
}

void MainWindow::on_do_2_clicked()
{
    int size = 0;
    hash table(30);
    for (int i = 0; i < ui->spinBox_2->value(); i += 1){
        size++;
        table.insertItem(convert_key(ui->lineEdit->text()),rand()%100+1);
    }
    QString ans;
    QTextStream out(&ans);
    out << "hash:\n";
    out << table.displayHash();
    out << table.findMaxKey();
    ui->display->setText(ans);
}

