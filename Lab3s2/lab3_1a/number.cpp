#include "number.h"
#include "ui_number.h"

number::number(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::number)
{
    ui->setupUi(this);
}

number::~number()
{
    delete ui;
}

QString number::getNum()
{
    return ui->lineEdit->text();
}
