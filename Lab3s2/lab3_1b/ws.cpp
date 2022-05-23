#include "ws.h"
#include "ui_ws.h"

ws::ws(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ws)
{
    ui->setupUi(this);
}


ws::~ws()
{
    delete ui;
}

QString ws::wsR(){
    return ui->lineEdit_2->text();
}
