#include "mainwindow.h"
#include "ui_mainwindow.h"

QString path = "C:\\Users\\0w0\\Documents\\lab1_4\\d\\mmm.txt";
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    loadtext();
    checkFile();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::checkFile()
{
    bool a = true;
    int y = 1; int i = 0;
    for(int r = 0; r<text.length();r++,i++)
    {
        if(text[r]=='\n')
        {
            y++;
            i=0;
        }
        if(text[r]=='[')
        {
            symbols->add(1);
            id->add(i);
            str->add(y);
        }
        if(text[r]=='{')
        {
            symbols->add(2);
            id->add(i);
            str->add(y);
        }
        if(text[r]=='(')
        {
            symbols->add(3);
            id->add(i);
            str->add(y);
        }

        if(text[r]==']')
        {
            if(symbols->headValue()==1)
            {
                symbols->pop();
                id->pop();
                str->pop();
            }
            else
            {
                error(1,y,i);
                a=false;
                break;
            }
        }
        if(text[r]=='}')
        {
            if(symbols->headValue()==2)
            {
                symbols->pop();
                id->pop();
                str->pop();
            }
            else
            {
                error(1,y,i);
                a=false;
                break;
            }
        }
        if(text[r]==')')
        {
            if(symbols->headValue()==3)
            {
                symbols->pop();
                id->pop();
                str->pop();
            }
            else
            {
                error(1,y,i);
                a=false;
                break;
            }
        }
    }

    if(a)
    {
        if(symbols->getCount()!=0)
        {
            error(2,str->lastId(),id->lastId());
            a=false;
        }
        else
        {
            QWidget* good = new QWidget();
            QGridLayout* a = new QGridLayout;
            a->addWidget(new QLabel("Nice!"),0,0);
            good->setLayout(a);
            good->show();
        }
    }
}

void MainWindow::error(int var,int y, int i)
{
        QWidget* bad = new QWidget();
        QGridLayout* a = new QGridLayout;
        a->addWidget(new QLabel("Error!"),0,0);
        a->addWidget(new QLabel("Строка:"),1,0);
        a->addWidget(new QLabel(QString::number(y)),1,1);
        a->addWidget(new QLabel("Элемент:"),2,0);
        a->addWidget(new QLabel(QString::number(i+1)),2,1);
        a->addWidget(new QLabel("Тип ошибки:"),3,0);
        if(var-1)
            a->addWidget(new QLabel("Открывающая скобка"),3,1);
        else
            a->addWidget(new QLabel("Закрывающая скобка"),3,1);
        bad->setLayout(a);
        bad->show();

}

void MainWindow::loadtext()
{
    QFile f(path);

    qDebug()<<1;
    if (f.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug()<<"da";
        while(!f.atEnd())
        {
            QByteArray line = f.readAll();
            text = line;
            qDebug()<<text;
        }
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    auto a = QFileDialog::getOpenFileName(0,"Выберите файл","","*.txt");
    if(a =="") return;
    path = a;
    loadtext();
    ui->textEdit->setText(text);

}

void MainWindow::on_pushButton_clicked()
{
    text = ui->textEdit->toPlainText();
    for(int i = 0; i<symbols->getCount();i++)
        symbols->pop();
    for(int i = 0; i<id->getCount();i++)
        id->pop();
    for(int i = 0; i<str->getCount();i++)
        str->pop();
}

void MainWindow::on_pushButton_3_clicked()
{
    checkFile();
}
