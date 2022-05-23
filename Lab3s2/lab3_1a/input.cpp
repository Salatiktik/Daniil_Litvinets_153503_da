#include "input.h"
#include "ui_input.h"

input::input(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::input)
{
    ui->setupUi(this);
}

input::~input()
{
    delete ui;
}

QString input::code()
{
    return ui->lineEdit_2->text();
}
QString input::city()
{
    return ui->lineEdit->text();
}
QString input::person1()
{
    return ui->lineEdit_3->text();
}
QString input::person2()
{
    return ui->lineEdit_4->text();
}
QString input::date()
{
    return ui->dateEdit->text();
}
QString input::time(){
    return ui->timeEdit->text();
}
double input::rate(){
    return ui->doubleSpinBox->value();
}

void input::codeSet(QString a)
{
    ui->lineEdit_2->setText(a);
}
void input::citySet(QString a)
{
    ui->lineEdit->setText(a);
}
void input::person1Set(QString a)
{
    ui->lineEdit_3->setText(a);
}
void input::person2Set(QString a)
{
    ui->lineEdit_4->setText(a);
}
void input::dateSet(QString a)
{
    ui->dateEdit->setDate(QDate::fromString(a));
}
void input::timeSet(QString a)
{
    ui->timeEdit->setTime(QTime::fromString(a));
}
void input::rateSet(double a){
    ui->doubleSpinBox->setValue(a);
}

