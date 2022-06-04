#include "mainwindow.h"
#include "ui_mainwindow.h"

bitset* b1;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    bitset b1(1,7);
    qDebug()<<b1.to_string() << " " << b1.to_ulong();
    b1.reset();
    qDebug()<<b1.to_string();
    b1.set(1);
    qDebug()<<b1.to_string();
    b1.set(3);
    qDebug()<<b1.to_string();
    b1.set();
    qDebug()<<b1.to_string();
    ui->lineEdit->setReadOnly(1);
    ui->lineEdit_2->setReadOnly(1);
    ui->lineEdit_3->setReadOnly(1);
    ui->lineEdit_4->setReadOnly(1);
    ui->lineEdit_5->setReadOnly(1);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_4_clicked()
{
    delete b1;
    b1 = new bitset(ui->spinBox_3->value(),ui->spinBox_2->value());
    rewrite();
}

void MainWindow::on_pushButton_clicked()
{
    if(ui->radioButton->isChecked())
        b1->set(ui->spinBox->value());
    else
        b1->set();

    rewrite();
}

void MainWindow::rewrite()
{
    ui->lineEdit->setText(b1->to_string());
    if(b1->checkOverflowUl())
        ui->lineEdit_2->setText("ПЕРЕПОЛНЕНИЕ");
    else
        ui->lineEdit_2->setText(QString::number(b1->to_ulong()));
    ui->lineEdit_3->setText(b1->any()?"Да":"Нет");
    ui->lineEdit_4->setText(b1->none()?"Да":"Нет");
    ui->lineEdit_5->setText(b1->all()?"Да":"Нет");
}

void MainWindow::on_pushButton_2_clicked()
{
    if(ui->radioButton->isChecked())
        b1->reset(ui->spinBox->value());
    else
        b1->reset();

    rewrite();
}

void MainWindow::on_pushButton_3_clicked()
{
    b1->flip();
    rewrite();
}
