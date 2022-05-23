#include "mainwindow.h"
#include "ui_mainwindow.h"

QString text = "|";

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    int r = rand()%99+1;
    qDebug()<<r;
    deq.push_front(r);
    text = "|"+QString::number(r)+text;
    ui->textBrowser->setText(text);
}

void MainWindow::on_pushButton_2_clicked()
{
    int r = rand()%99+1;
    qDebug()<<r;
    deq.push_back(r);
    text += QString::number(r)+"|";
    ui->textBrowser->setText(text);
}



void MainWindow::on_pushButton_3_clicked()
{
    qDebug()<< deq.pop_front();

    QStringList s = text.split('|');
    text = "|";
    for(int i = 2; i<s.length()-1;i++)
    {
        text+=s[i]+"|";
    }
    text+=s[s.length()-1];
    ui->textBrowser->setText(text);
}

void MainWindow::on_pushButton_4_clicked()
{
    qDebug()<< deq.pop_back();

    QStringList s = text.split('|');
    text = "|";
    qDebug()<<1;
    for(int i = 1; i<s.length()-3;i++)
    {
        text+=s[i]+"|";
    }
    text+=s[s.length()-3]+"|";
    ui->textBrowser->setText(text);
}



void MainWindow::on_pushButton_5_clicked()
{
    QMessageBox::information(this,"Размер","Размер очереди равен " + QString::number(deq.size()));
}

void MainWindow::on_pushButton_6_clicked()
{
    deq.clear();
    text = "|";
    ui->textBrowser->setText(text);
}

void MainWindow::on_pushButton_7_clicked()
{
    if(deq.empty())
        QMessageBox::information(this,"Наполненность","Данная очередь пуста");
    else
        QMessageBox::information(this,"Наполненность","Данная очередь не пуста");
}
