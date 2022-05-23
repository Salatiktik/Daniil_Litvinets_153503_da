#include "mainwindow.h"
#include "ui_mainwindow.h"

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
    randInt.clear();
    tmp.clear();
    ui->comboBox->clear();
    ui->comboBox_2->clear();
    for(int i = 0; i< ui->spinBox_3->value();i++)
    {
        int r = rand()%(ui->spinBox_2->value()-ui->spinBox->value())+ui->spinBox->value();
        ui->comboBox->addItem(QString::number(r));
        randInt.push(r);
    }

    int min = randInt.back();
    tmp.push(min);
    randInt.pop();

    for(int i = 0; i<ui->spinBox_3->value()-1;i++)
    {

        if(min > randInt.back())
            min = randInt.back();
        tmp.push(randInt.back());
        randInt.pop();
    }
    tmp.push(min);
    ui->comboBox_2->addItem(QString::number(min));
    bool is = true;

    for(int i = 0; i<ui->spinBox_3->value()-1;i++)
    {
        if(min==tmp.back()&&is)
        {
            tmp.pop();
            is=false;
        }
        else
        {
            ui->comboBox_2->addItem(QString::number(tmp.back()));
            tmp.pop();
        }
    }
}
