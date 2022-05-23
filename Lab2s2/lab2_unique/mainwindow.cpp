#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <sstream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Unique_ptr<int>sp2(new int(66));

    ui->tableWidget->setRowCount(10);
    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setColumnWidth(0,250);
    ui->tableWidget->setColumnWidth(1,250);

    for(int i = 0; i<10;i++)
        a[i]=sp2;

    table_rewrite();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::table_rewrite()
{
    std::stringstream ad;
    ui->tableWidget->clear();
    for(int i = 0; i<10;i++)
    {
        ad << static_cast<void *>(a[i].get());
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString::fromStdString(ad.str())));

        if(a[i].get())
        {
            ui->tableWidget->setItem(i,1,new QTableWidgetItem(QString::fromStdString(std::to_string(*a[i].get()))));
        }
        else
        {
            ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString(" ")));
        }
        ad.str("");
        qDebug()<< a[i].get();
    }
}

void MainWindow::on_pushButton_clicked()
{
    Unique_ptr<int> ptr (new int(rand()%100));
    a[ui->spinBox->value()-1] = ptr;
    table_rewrite();
}

void MainWindow::on_pushButton_2_clicked()
{
    Unique_ptr<int> ptr (new int(rand()%100));
    a[ui->spinBox->value()-1] = a[ui->spinBox_2->value()-1];
    table_rewrite();
}

void MainWindow::on_pushButton_5_clicked()
{
    close();
}
