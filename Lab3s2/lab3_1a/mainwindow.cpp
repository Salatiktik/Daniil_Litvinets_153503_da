#include "mainwindow.h"
#include "ui_mainwindow.h"

QString path = "C:\\Users\\0w0\\Documents\\calls.txt";

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->tableWidget->setColumnCount(6);
    ui->tableWidget->setColumnWidth(1,100);
    ui->tableWidget->setColumnWidth(2,100);
    ui->tableWidget->setColumnWidth(3,100);
    ui->tableWidget->setColumnWidth(4,190);
    ui->tableWidget->setColumnWidth(5,190);
    ui->tableWidget->setColumnWidth(0,100);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList({"Дата","Время","Тариф","Город","Вызывающий","Вызываемый"}));
    tableLoad();
    tableRewtire();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::tableLoad()
{
    if(checkFile(path))
    {
        QFile f(path);

        qDebug()<<1;
        if (f.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            qDebug()<<"da";
            while(!f.atEnd())
            {
                calls->addTail(new Unit(f.readLine(),f.readLine(),f.readLine(),f.readLine(),f.readLine().toDouble(),f.readLine(),f.readLine()));
            }
        }
    }
    else
    {
        error();
    }
}

bool MainWindow::date_in(std::string h)
{
    char* dd = (char*)calloc(3, sizeof(char));
    dd [0]= h[0];
    dd[1] = h[1];
    char* mm = (char*)calloc(3, sizeof(char));
    mm[0] = h[3];
    mm[1] = h[4];
    char* yy = (char*)calloc(5, sizeof(char));
    yy[0] = h[6];
    yy[1] = h[7];
    yy[2] = h[8];
    yy[3] = h[9];
    if (atoi(dd) >= 32 || atoi(mm) >= 13 || atoi(yy) < 1900 || atoi(yy) > 2021 || h[2] != '.' || h[5] != '.')
    {
        free(dd);
        free(mm);
        free(yy);
        return 0;
    }
    free(dd);
    free(mm);
    free(yy);
    return 1;
}

bool MainWindow::time_in(std::string h)
{
    char* hh = (char*)calloc(3, sizeof(char));
    hh[0] = h[0];
    hh[1] = h[1];
    char* mm = (char*)calloc(3, sizeof(char));
    mm[0] = h[3];
    mm[1] = h[4];
    if (atoi(hh) >=60 || atoi(mm) >=60 || h[2] != ':')
    {
        free(hh);
        free(mm);
        return 0;
    }
    free(hh);
    free(mm);

    return 1;
}

void MainWindow::error()
{
    QWidget* bad = new QWidget();
    QGridLayout* a = new QGridLayout;
    a->addWidget(new QLabel("Проверьте данные и попробуйте снова!"),0,0);
    bad->setLayout(a);
    bad->show();
}

void MainWindow::on_pushButton_clicked()
{
    input* in = new input();
    in->setModal(true);
    in->setResult(2);
    in->show();
    if(in->exec()==QDialog::Accepted)
    {
        calls->addTail(new Unit(in->code(),in->city(),in->date(),in->time(),in->rate(),in->person1(),in->person2()));
        tableRewtire();
        delete in;
    }

}

void MainWindow::tableRewtire()
{
    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(calls->getCount());
    qDebug()<<calls->getCount();
    ui->tableWidget->setHorizontalHeaderLabels(QStringList({"Дата","Время","Тариф","Город","Вызывающий","Вызываемый"}));

    for(int i = 0; i<calls->getCount();i++)
    {
        qDebug()<<i;
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(calls->getNode(i)->value->call_u->date));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(calls->getNode(i)->value->call_u->time));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(QString::number(calls->getNode(i)->value->call_u->rate)));
        ui->tableWidget->setItem(i,3,new QTableWidgetItem(calls->getNode(i)->value->call_u->city.name));
        ui->tableWidget->setItem(i,4,new QTableWidgetItem(calls->getNode(i)->value->call_u->person1));
        ui->tableWidget->setItem(i,5,new QTableWidgetItem(calls->getNode(i)->value->call_u->person2));
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    choose* ch = new choose;
    ch->setModal(true);
    ch->setRange(calls->getCount());
    if(ch->exec()==QDialog::Accepted)
    {
        qDebug()<<calls->getCount() << "sdf";
        if(calls->getCount()!=0)
        {
            calls->del(ch->returnValue());
            tableRewtire();
        }
        else
            error();
        delete ch;
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    choose* ch = new choose;
    ch->setModal(true);
    ch->setRange(calls->getCount());
    if(ch->exec()==QDialog::Accepted)
    {
        int u = ch->returnValue()-1;
        delete ch;
        input* in = new input();
        in->setModal(true);
        qDebug()<<calls->getNode(u)->value->call_u->city.code;
        in->codeSet(calls->getNode(u)->value->call_u->city.code);
        qDebug()<<calls->getNode(u)->value->call_u->city.name;
        in->citySet(calls->getNode(u)->value->call_u->city.name);
        in->dateSet(calls->getNode(u)->value->call_u->date);
        in->timeSet(calls->getNode(u)->value->call_u->time);
        in->rateSet(calls->getNode(u)->value->call_u->rate);

        in->person1Set(calls->getNode(u)->value->call_u->person1);
        in->person2Set(calls->getNode(u)->value->call_u->person2);
        in->show();
        if(in->exec()==QDialog::Accepted)
        {
            delete calls->getNode(u)->value;
            calls->getNode(u)->value = new Unit(in->code(),in->city(),in->date(),in->time(),in->rate(),in->person1(),in->person2());
            tableRewtire();
            delete in;
        }
    }
}

void MainWindow::on_pushButton_4_clicked()
{
    number* a = new number;
    a->setModal(true);
    a->show();
    if(a->exec()==QDialog::Accepted)
    {
        QString num = a->getNum();

        for(int i = 0; i < calls->getCount(); i++)
        {
            if(calls->getNode(i)->value->call_u->person1.split('\n')[0]==num)
            {
                ui->tableWidget->item(i,4)->setBackgroundColor(QColor(100,240,200));

            }
            if(calls->getNode(i)->value->call_u->person2.split('\n')[0]==num)
            {
                ui->tableWidget->item(i,5)->setBackgroundColor(QColor(100,240,200));
            }
        }
    }
}

void MainWindow::on_pushButton_7_clicked()
{
    tableRewtire();
}

void MainWindow::on_pushButton_5_clicked()
{
    city* a = new city;
    a->setModal(true);
    a->show();
    if(a->exec()==QDialog::Accepted)
    {
        QString city = a->returnCity();

        for(int i = 0; i < calls->getCount(); i++)
        {
            if(calls->getNode(i)->value->call_u->city.name.split('\n')[0]==city)
            {
                ui->tableWidget->item(i,3)->setBackgroundColor(QColor(100,240,200));
            }
        }
    }
}

void MainWindow::on_pushButton_10_clicked()
{
    auto a = QFileDialog::getOpenFileName(0,"Выберите файл","","*.txt");
    if(a =="") return;

    if(checkFile(a))
    {
        path = a;
        calls->delAll();

        tableLoad();
        tableRewtire();

    }
    else
    {
        error();
    }
}

bool MainWindow::checkFile(QString a)
{
    QFile f(a);

    qDebug()<<1;
    if (f.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug()<<"da";
        while(!f.atEnd())
        {
            QString a = f.readLine();
            if(a[1]!='-'||a[5]!='-')
                return 0;
            f.readLine();
            if(!date_in(f.readLine().toStdString()))
                return 0;
            if(!time_in(f.readLine().toStdString()))
                return 0;
            f.readLine();
            f.readLine();
            f.readLine();
        }
        return 1;
    }
}


void MainWindow::on_pushButton_6_clicked()
{
    QFile f(path);

    if (f.open(QIODevice::WriteOnly | QIODevice::Truncate))
    {
        f.close();
    }

    QFile fout(path);

    if(fout.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream write(&fout);
        qDebug()<<3;
        for(int i = 0; i<calls->getCount();i++)
        {
            (calls->getNode(i)->value->call_u->city.code.toStdString()[calls->getNode(i)->value->call_u->city.code.toStdString().length()-1]!='\n')? write<<QByteArray::fromStdString(calls->getNode(i)->value->call_u->city.code.toStdString()+"\n"):write<<QByteArray::fromStdString(calls->getNode(i)->value->call_u->city.code.toStdString());
            (calls->getNode(i)->value->call_u->city.name.toStdString()[calls->getNode(i)->value->call_u->city.name.toStdString().length()-1]!='\n')? write<<QByteArray::fromStdString(calls->getNode(i)->value->call_u->city.name.toStdString()+"\n"):write<<QByteArray::fromStdString(calls->getNode(i)->value->call_u->city.name.toStdString());
            (calls->getNode(i)->value->call_u->date.toStdString()[calls->getNode(i)->value->call_u->date.toStdString().length()-1]!='\n')? write<<QByteArray::fromStdString(calls->getNode(i)->value->call_u->date.toStdString()+"\n"):write<<QByteArray::fromStdString(calls->getNode(i)->value->call_u->date.toStdString());
            (calls->getNode(i)->value->call_u->time.toStdString()[calls->getNode(i)->value->call_u->time.toStdString().length()-1]!='\n')? write<<QByteArray::fromStdString(calls->getNode(i)->value->call_u->time.toStdString()+"\n"):write<<QByteArray::fromStdString(calls->getNode(i)->value->call_u->time.toStdString());
            (QString::number(calls->getNode(i)->value->call_u->rate).toStdString()[QString::number(calls->getNode(i)->value->call_u->rate).toStdString().length()-1]!='\n')? write<<QByteArray::fromStdString(QString::number(calls->getNode(i)->value->call_u->rate).toStdString()+"\n"):write<<QByteArray::fromStdString(QString::number(calls->getNode(i)->value->call_u->rate).toStdString());
            (calls->getNode(i)->value->call_u->person1.toStdString()[calls->getNode(i)->value->call_u->person1.toStdString().length()-1]!='\n')? write<<QByteArray::fromStdString(calls->getNode(i)->value->call_u->person1.toStdString()+"\n"):write<<QByteArray::fromStdString(calls->getNode(i)->value->call_u->person1.toStdString());
            (calls->getNode(i)->value->call_u->person2.toStdString()[calls->getNode(i)->value->call_u->person2.toStdString().length()-1]!='\n')? write<<QByteArray::fromStdString(calls->getNode(i)->value->call_u->person2.toStdString()+"\n"):write<<QByteArray::fromStdString(calls->getNode(i)->value->call_u->person2.toStdString());
        }
    }
}

void MainWindow::on_pushButton_8_clicked()
{
    calls->sort(0,calls->getCount()-1);
    tableRewtire();
}
