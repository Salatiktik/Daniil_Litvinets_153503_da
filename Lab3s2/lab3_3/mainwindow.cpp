#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    in = ui->lineEdit->text();
    inToPost();
    qDebug()<<post;
    QStringList postM = post.split('|');
    solution(postM);
    post = "";
}

void MainWindow::inToPost(){
    bool dr = false, numEnt = false;
    int drN = 0;
    double num = 0;
    for(int i = 0; i<in.length();i++)
    {
        qDebug()<<in[i];
        switch(in[i].unicode())
        {
        case '(':
        case '/':
        case '*':
            if(numEnt)
            {
                numEnt = false;
                num/=pow(10,drN);
                post.append(QString::number(num));
                post.append('|');
                num = 0;
                dr = false;
                drN = 0;
            }
            signs->add(in[i].unicode());

            break;
        case '+':
        case '-':
            if(numEnt)
            {
                numEnt = false;
                num/=pow(10,drN);
                post.append(QString::number(num));
                post.append('|');
                num = 0;
                dr = false;
                drN = 0;
            }

            if(signs->getCount()!=0)
            {
                if(signs->headValue()=='/'||signs->headValue()=='*')
                {
                    while(signs->getCount()!=0)
                    {
                        if(signs->headValue()!='+'&&signs->headValue()!='-'&&signs->headValue()!='(')
                        {
                            post.append(signs->headValue());
                            post.append('|');
                            signs->pop();
                        }
                        else
                            break;
                    }
                }
            }

            signs->add(in[i].unicode());

            break;
        case ')':

            if(numEnt)
            {
                numEnt = false;
                num/=pow(10,drN);
                post.append(QString::number(num));
                post.append('|');
                num = 0;
                dr = false;
                drN = 0;
            }

            while(signs->getCount()!=0)
            {
                if(signs->headValue()!='(')
                {
                    post.append(signs->headValue());
                    post.append('|');
                    signs->pop();
                }
                else
                    signs->pop();
                    break;
            }

            if(signs->checkBrack()){
                while(signs->getCount()!=0)
                {
                    if(signs->headValue()!='(')
                    {
                        post.append(signs->headValue());
                        post.append('|');
                        signs->pop();
                    }
                    else
                        signs->pop();
                        break;
                }
            }

            dr = false;
            break;
        case '.':
            dr = true;
            break;
        default:
            numEnt = true;
            num=num*10 + in[i].unicode()-48;
            if(dr)
                drN++;
        }
        qDebug()<<post << "\n";
    }
    if (num!=0)
    {
        numEnt = false;
        num/=pow(10,drN);
        post.append(QString::number(num));
        post.append('|');
    }
    while(signs->getCount()!=0)
    {
        if(signs->headValue()!='(')
        {
            post.append(signs->headValue());
            post.append('|');
            signs->pop();
        }
        else
            signs->pop();
    }


}

void MainWindow::solution(QStringList mass)
{
    qDebug()<<mass.length();
    for(int i = 0; i<mass.length()-1;i++)
    {
        if(mass[i].toDouble()==0&&mass[i][0]!='0')
        {
            double a = num->headValue();
            num->pop();
            double b = num->headValue();
            num->pop();
            switch(mass[i][0].unicode())
            {
            case '+':
                num->add(a+b);
                break;
            case '-':
                num->add(b-a);
                break;
            case '/':
                num->add(b/a);
                break;
            case '*':
                num->add(a*b);
                break;
            }
        }
        else
            num->add(mass[i].toDouble());
    }
    ui->label_2->setNum(num->headValue());
    num->pop();
}
