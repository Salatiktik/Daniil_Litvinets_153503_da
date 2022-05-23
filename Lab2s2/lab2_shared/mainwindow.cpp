#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <sstream>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    {
        Shared_ptr<int>sp2(new int(66));
        for(int i = 0; i<10;i++)
            a[i]=sp2;
    }

    Shared_ptr<int> sp1(new int [3]{1,2,3});
    qDebug()<<sp1[2];

    ui->tableWidget->setRowCount(10);
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setColumnWidth(0,200);
    ui->tableWidget->setColumnWidth(1,150);
    ui->tableWidget->setColumnWidth(2,100);



    table_rewrite();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::table_rewrite()
{
    std::stringstream ad;

    for(int i = 0; i<10;i++)
    {
        ad << static_cast<void *>(a[i].get());
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString::fromStdString(ad.str())));

        ui->tableWidget->setItem(i,1,new QTableWidgetItem(QString::fromStdString(std::to_string(*a[i].get()))));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(QString::fromStdString(std::to_string(a[i].get_count()))));
        ad.str("");
        qDebug()<< a[i].get();
    }
}

void MainWindow::on_pushButton_clicked()
{
    {
        Shared_ptr<int> ptr (new int(rand()%100));
        a[ui->spinBox->value()-1] = ptr;
        qDebug()<<a[ui->spinBox->value()-1].get_count();
    }
    table_rewrite();
}

void MainWindow::on_pushButton_2_clicked()
{
    {
        Shared_ptr<int> ptr (new int(rand()%100));
        a[ui->spinBox->value()-1] = a[ui->spinBox_2->value()-1];
    }
    table_rewrite();
}

void MainWindow::on_pushButton_4_clicked()
{
    QWidget* window = new QWidget();
    QGridLayout* mainLay = new QGridLayout;

    if(a[ui->spinBox->value()-1].is_unique())
        mainLay->addWidget(new QLabel("Уникален"), 0, 0);
    else
        mainLay->addWidget(new QLabel("Не уникален"), 0, 0);

    window->setLayout(mainLay);

    window->show();
}

void MainWindow::on_pushButton_5_clicked()
{
    close();
}
