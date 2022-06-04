#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    map = new unordered_map<QString, QString>(25);
}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::rewrite()
{
    ui->display->setText(map->to_string());
}

void MainWindow::on_do_2_clicked()
{
    if(!map->contain(ui->lineEdit->text()))
        map->insertItem(ui->lineEdit->text(),ui->lineEdit_2->text());
    rewrite();
}

void MainWindow::on_do_4_clicked()
{
    if(map->contain(ui->lineEdit->text()))
    {
        QMessageBox* good = new QMessageBox();
        good->setIcon(QMessageBox::Icon::Information);
        good->setText("Данный ключ имеется в таблице");
        good->show();
    }
    else
    {

        QMessageBox* bad= new QMessageBox();
        bad->setIcon(QMessageBox::Icon::Critical);
        bad->setText("Данный ключ отсутствует в таблице");
        bad->show();
    }
}

void MainWindow::on_do_3_clicked()
{
    map->clearItem(ui->lineEdit->text());
    rewrite();
}

void MainWindow::on_do_5_clicked()
{
    map->rehash(ui->spinBox->value());
    rewrite();
}
