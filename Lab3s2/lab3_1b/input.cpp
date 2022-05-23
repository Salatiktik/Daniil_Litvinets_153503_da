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

QString input::ws()
{
    return ui->lineEdit_2->text();
}
QString input::title(){
    return ui->lineEdit_3->text();
}
int input::num()
{
    return ui->spinBox->value();
}
void input::wsSet(QString a)
{
    ui->lineEdit_2->setText(a);
}

void input::titleSet(QString a){
    ui->lineEdit_3->setText(a);
}
void input::numSet(int a)
{
    ui->spinBox->setValue(a);
}

