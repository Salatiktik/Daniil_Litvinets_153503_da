#include "workshop.h"
#include "ui_workshop.h"

workshop::workshop(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::workshop)
{
    ui->setupUi(this);
}

workshop::~workshop()
{
    delete ui;
}

QString workshop::returnWs()
{
    return ui->lineEdit->text();
}
