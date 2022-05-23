#include "choose.h"
#include "ui_choose.h"

choose::choose(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::choose)
{
    ui->setupUi(this);
}

choose::~choose()
{
    delete ui;
}

void choose::setRange(int x)
{
    ui->spinBox->setRange(1,x);
}

int choose::returnValue()
{
    return ui->spinBox->value();
}

void choose::setTitle(QString a)
{
    ui->label->setText(a);
}
