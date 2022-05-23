#include "mainwindow.h"
#include "ui_mainwindow.h"

QString path = "C:\\Users\\0w0\\Documents\\products.txt";

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setColumnWidth(0,200);
    ui->tableWidget->setColumnWidth(1,300);
    ui->tableWidget->setColumnWidth(2,100);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList({"Индекс цеха","Наименование товара","Количество"}));
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
                QByteArray a = f.readLine();
                QByteArray b = f.readLine();
                qDebug()<<b;
                QByteArray c = f.readLine();

                products->addTail(new Unit(QString::fromUtf8(a),QString::fromUtf8(b),QString::fromUtf8(c).toInt()));
            }
        }
    }
    else
    {
        error();
    }
}


void MainWindow::error(QString b)
{
    QWidget* bad = new QWidget();
    QGridLayout* a = new QGridLayout;
    a->addWidget(new QLabel(b),0,0);
    bad->setLayout(a);
    bad->show();
}

void MainWindow::on_pushButton_clicked()
{
    tableRewtire();
    input* in = new input();
    in->setModal(true);
    in->setResult(2);
    in->show();
    if(in->exec()==QDialog::Accepted)
    {
        products->addTail(new Unit(in->ws(),in->title(),in->num()));
        tableRewtire();
        delete in;
    }

}

void MainWindow::tableRewtire()
{
    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(products->getCount());
    qDebug()<<products->getCount();
    ui->tableWidget->setHorizontalHeaderLabels(QStringList({"Индекс цеха","Наименование товара","Количество"}));

    for(int i = 0; i<products->getCount();i++)
    {
        qDebug()<<i;
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(products->getNode(i)->value->prod_u->wsCode));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(products->getNode(i)->value->prod_u->prTitle));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(QString::number(products->getNode(i)->value->prod_u->num)));
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    tableRewtire();
    choose* ch = new choose;
    ch->setModal(true);
    ch->setRange(products->getCount());
    if(ch->exec()==QDialog::Accepted)
    {
        products->del(ch->returnValue());
        tableRewtire();
        delete ch;
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    tableRewtire();
    choose* ch = new choose;
    ch->setModal(true);
    ch->setRange(products->getCount());
    if(ch->exec()==QDialog::Accepted)
    {
        int u = ch->returnValue()-1;
        delete ch;
        input* in = new input();
        in->setModal(true);
        in->wsSet(products->getNode(u)->value->prod_u->wsCode);
        qDebug()<<products->getNode(u)->value->prod_u->prTitle;
        in->titleSet(products->getNode(u)->value->prod_u->prTitle);
        in->numSet(products->getNode(u)->value->prod_u->num);
        in->show();
        if(in->exec()==QDialog::Accepted)
        {
            delete products->getNode(u)->value;
            products->getNode(u)->value = new Unit(in->ws(),in->title(),in->num());
            tableRewtire();
            delete in;
        }
    }
}

void MainWindow::on_pushButton_4_clicked()
{
    int cnt = 0;
    tableRewtire();
    choose* a = new choose;
    a->setModal(true);
    a->show();
    a->setRange(100);
    a->setTitle("Минимальное количество");
    if(a->exec()==QDialog::Accepted)
    {
        int num = a->returnValue();

        for(int i = 0; i < products->getCount(); i++)
        {
            if(products->getNode(i)->value->prod_u->num>=num)
            {
                ui->tableWidget->item(i,0)->setBackgroundColor(QColor(100,240,200));
                cnt++;
            }

        }
        if(cnt==0)
        {
            error("Элементы не найдены!");
        }
    }
}

void MainWindow::on_pushButton_7_clicked()
{
    tableRewtire();
}

void MainWindow::on_pushButton_5_clicked()
{
    int cnt = 0;
    workshop* a = new workshop;
    a->setModal(true);
    a->show();
    if(a->exec()==QDialog::Accepted)
    {
        QString Ws = a->returnWs();

        for(int i = 0; i < products->getCount(); i++)
        {
            if(products->getNode(i)->value->prod_u->wsCode.split('\n')[0]==Ws)
            {
                ui->tableWidget->item(i,0)->setBackgroundColor(QColor(100,240,200));
                cnt++;
            }

        }
        if(cnt==0)
        {
            error("Элементы не найдены!");
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
        products->delAll();

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
            f.readLine();
            a = f.readLine();

            try {
                std::stoi(a.toStdString());
            } catch (std::invalid_argument) {
                return 0;
            }

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
        for(int i = 0; i<products->getCount();i++)
        {
            if(products->getNode(i)->value->prod_u->wsCode.toStdString()[products->getNode(i)->value->prod_u->wsCode.toStdString().length()-1]!='\n')
                write<<products->getNode(i)->value->prod_u->wsCode+"\n";
            else
                write<<products->getNode(i)->value->prod_u->wsCode;

            if(products->getNode(i)->value->prod_u->prTitle.toStdString()[products->getNode(i)->value->prod_u->prTitle.toStdString().length()-1]!='\n')
                write<<products->getNode(i)->value->prod_u->prTitle+"\n";
            else
                write<<products->getNode(i)->value->prod_u->prTitle;


            write<<QByteArray::fromStdString(std::to_string(products->getNode(i)->value->prod_u->num)+"\n");
        }
    }
}
