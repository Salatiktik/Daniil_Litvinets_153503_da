#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QGridLayout>
#include <QDebug>
#include <sstream>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    {
        Shared_ptr<int>sp2(new int(66));
        Weak_ptr<int>sp1(sp2);

        for(int i = 0; i<10;i++)
        {
            a[i]=sp2;
            b[i]=sp1;
        }
    }

    ui->tableWidget->setRowCount(10);
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setColumnWidth(0,200);
    ui->tableWidget->setColumnWidth(1,100);
    ui->tableWidget->setColumnWidth(2,50);
    ui->tableWidget->setEditTriggers(NULL);


    ui->tableWidget_2->setRowCount(10);
    ui->tableWidget_2->setColumnCount(2);
    ui->tableWidget_2->setColumnWidth(0,170);
    ui->tableWidget_2->setColumnWidth(1,170);
    ui->tableWidget_2->setEditTriggers(NULL);


    table_rewrite();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::table_rewrite()
{
    std::stringstream ad;
    ui->tableWidget->setHorizontalHeaderLabels(QStringList{"Адрес","Значение","Кол-во"});
    ui->tableWidget_2->setHorizontalHeaderLabels(QStringList{"Кол-во наблюдателей","Кол-во указателей"});


    for(int i = 0; i<10;i++)
    {
        ad << static_cast<void *>(a[i].get());
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString::fromStdString(ad.str())));

        ui->tableWidget->setItem(i,1,new QTableWidgetItem(QString::fromStdString(std::to_string(*a[i].get()))));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(QString::fromStdString(std::to_string(*a[i].get_count()))));
        ad.str("");
        qDebug()<<b[i].get_scount();
        qDebug()<<a[i].get_count();

        ui->tableWidget_2->setItem(i,0,new QTableWidgetItem(QString::fromStdString(std::to_string(*(b[i].get_wcount())))));
        ui->tableWidget_2->setItem(i,1,new QTableWidgetItem(QString::fromStdString(std::to_string(*(b[i].get_scount())))));


    }
}

void MainWindow::on_pushButton_clicked()
{
    {
        Shared_ptr<int> ptr (new int(rand()%100));
        a[ui->spinBox->value()-1] = a[ui->spinBox_2->value()-1];
    }
    table_rewrite();
}

void MainWindow::on_pushButton_2_clicked()
{
    {
        qDebug()<<b[ui->spinBox_3->value()-1].get_scount();

        a[ui->spinBox->value()-1] = b[ui->spinBox_3->value()-1].lock();
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

void MainWindow::on_pushButton_3_clicked()
{
    {
        Weak_ptr<int> ptr(a[ui->spinBox_4->value()-1]);
        b[ui->spinBox_5->value()-1]=ptr;
    }
    table_rewrite();
}

void MainWindow::on_pushButton_6_clicked()
{
    b[ui->spinBox_5->value()-1]=b[ui->spinBox_4->value()-1];
    table_rewrite();
}

void MainWindow::on_pushButton_7_clicked()
{
    {
        Shared_ptr<int> ptr (new int(rand()%100));
        a[ui->spinBox->value()-1] = ptr;
        qDebug()<<a[ui->spinBox->value()-1].get_count();
    }

    table_rewrite();
}
