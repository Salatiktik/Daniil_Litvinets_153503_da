#include "city.h"
#include "ui_city.h"

city::city(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::city)
{
    ui->setupUi(this);
}

city::~city()
{
    delete ui;
}

QString city::returnCity(){
    return ui->lineEdit->text();
}
