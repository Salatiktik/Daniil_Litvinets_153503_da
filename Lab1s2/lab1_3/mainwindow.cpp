#include "mainwindow.h"
#include "ui_mainwindow.h"

QString file_path = "C:\\Users\\0w0\\Documents\\lab1_3\\da.txt";
int len = 1;
int* mass = new int [3];
bool rewrite = false;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->table->setColumnCount(3);
    ui->table->setRowCount(1);
    ui->table->setColumnWidth(0,200);
    ui->table->setColumnWidth(1,165);
    ui->table->setColumnWidth(2,200);
    ui->table->setHorizontalHeaderLabels(QStringList{"Исходная дата","Следующий день","Разница с предыдущим"});

    load_base();
    qDebug()<<len;
    rewrite = true;
    ui->table->setEditTriggers(NULL);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void edit_file(Date* e, int i)
{
    QFile f(file_path);

    if(f.open(QIODevice::ReadWrite| QIODevice::Text))
    {
        for(int y = 0; y<i;y++)
        {
            f.readLine();
        }
        f.write((e[i].str().toStdString()+"\n").c_str(),11);
    }
}

void base_rewrite(Date* a, int i, int& len)
{
    QFile f(file_path);

    if(f.open(QIODevice::Text | QIODevice::ReadWrite))
    {
        for(int z = 0; z<i;z++)
        {
            f.readLine();
        }
        for(int y = i+1; y< len-1;y++)
        {
            f.write(((a[y].str()).toStdString()+"\n").c_str());
        }
        f.resize(11*(len-1));
    }
}

void MainWindow::load_base()
{
    QFile f(file_path);

    qDebug()<<1;
    if (f.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug()<<"da";
        while(!f.atEnd())
        {
            QByteArray line = f.readLine();

            qDebug()<<sizeof(line) << " asd";
            mass[0]=((line[0]-48)*10+line[1]-48);
            mass[1]=((line[3]-48)*10+line[4]-48);
            mass[2]=((line[6]-48)*1000+(line[7]-48)*100+(line[8]-48)*10+line[9]-48);
            addNew();
        }
    }
}

void MainWindow::delete_client()
{
    base_rewrite(dates, mass[0]-1, len);
    Date* new_b = new Date [len - 1];
    int o = 0;
    for (int i = 0; i < len; i++)
    {
        if (i == mass[0]-1)
        {
            i++;
            if (i == len)
            {
                break;
            }
        }
        new_b[o] = dates[i];
        o++;
    }
    len-=1;
    ui->spinBox_4->setRange(1,len-1);
    ui->spinBox_4->setValue(1);
    delete [] dates;
    dates = new_b;
    rewrite_table();
}

void MainWindow::on_pushButton_3_clicked()
{
    QWidget* window = new QWidget();
    window->setWindowTitle("Характеристика");
    QGridLayout* mainLay = new QGridLayout;

    QPushButton* ok = new QPushButton();
    ok ->setText("Ок");

    mainLay->addWidget(new QLabel("Следующий день: "),0,0);
    mainLay->addWidget(new QLabel(dates[ui->spinBox_4->value()-1].nextDay().str()),0,1);
    mainLay->addWidget(new QLabel("Предыдущий день: "),1,0);
    mainLay->addWidget(new QLabel(dates[ui->spinBox_4->value()-1].previousDay().str()),1,1);
    mainLay->addWidget(new QLabel("Номер недели: "),2,0);
    mainLay->addWidget(new QLabel(QString::number(dates[ui->spinBox_4->value()-1].weekNumber())),2,1);
    mainLay->addWidget(new QLabel("Дней до следующего дня рождения: "),3,0);
    mainLay->addWidget(new QLabel(QString::number(dates[ui->spinBox_4->value()-1].daysTillYourBirthDay(Date(ui->spinBox->value(),ui->spinBox_2->value(),ui->spinBox_3->value())))),3,1);

    mainLay->addWidget(ok,4,1);

    window->setLayout(mainLay);

    window->show();

    connect(ok, SIGNAL(clicked()),window,SLOT(close()));
}

void MainWindow::spbn_value(int i)
{
    mass[0]=i;
}

void MainWindow::spbn_2_value(int i)
{
    mass[1]=i;
}

void MainWindow::spbn_3_value(int i)
{
    mass[2]=i;
}

void MainWindow::addNew()
{
    qDebug()<<1;
    Date* dates_f = new Date[len+2];
    qDebug()<<len;
    for(int i = 0; i<len; i++)
    {
        qDebug()<<i;
        dates_f[i]=dates[i];
    }
    delete[]dates;
    dates=dates_f;
    dates[len-1]=Date(mass[0],mass[1],mass[2]);

    ui->table->setRowCount(len);
    ui->table->setItem(len-1,0,new QTableWidgetItem(dates[len-1].str()));
    qDebug()<<"da";
    ui->table->setItem(len-1,1,new QTableWidgetItem(dates[len-1].nextDay().str()));
    qDebug()<<"nda";
    if(len==1)
    {
        ui->table->setItem(len-1,2,new QTableWidgetItem("----"));
    }
    else
    {
        ui->table->setItem(len-1,2,new QTableWidgetItem(QString::fromStdString(std::to_string(dates[len-1].duration(dates[len-2])))));
    }

    if(rewrite)
    {
        edit_file(dates,len-1);
    }
    len++; ui->spinBox_4->setRange(1,len-1);
    qDebug()<<len;

}

void MainWindow::on_pushButton_2_clicked()
{
    QWidget* window = new QWidget();
    window->setWindowTitle("Ввод");
    QGridLayout* mainLay = new QGridLayout;
    QLabel* lbl = new QLabel("Строка: ");
    QSpinBox* spbn = new QSpinBox;
    spbn->setRange(1, len);

    QPushButton* ok = new QPushButton();
    ok ->setText("Ок");

    QPushButton* cancel = new QPushButton();
    cancel ->setText("Отмена");


    mainLay->addWidget(lbl, 0, 0);
    mainLay->addWidget(spbn, 0, 1);

    mainLay->addWidget(ok,1,0);
    mainLay->addWidget(cancel,1,1);

    window->setLayout(mainLay);

    window->show();

    mass[0]=spbn->value();

    connect(ok, SIGNAL(clicked()),this,SLOT(delete_client()));
    connect(ok, SIGNAL(clicked()),window,SLOT(close()));
    connect(cancel, SIGNAL(clicked()),window,SLOT(close()));

    connect(spbn, SIGNAL(valueChanged(int)),this,SLOT(spbn_value(int)));
}

void MainWindow::rewrite_table()
{
    ui->table->clear();
    ui->table->setHorizontalHeaderLabels(QStringList{"Исходная дата","Следующий день","Разница с предыдущим"});
    ui->table->setRowCount(len-1);
    for(int i = 0; i< len-1;i++)
    {
        ui->table->setItem(i,0,new QTableWidgetItem(dates[i].str()));

        ui->table->setItem(i,1,new QTableWidgetItem(dates[i].nextDay().str()));
        if(i==0)
        {
            ui->table->setItem(i,2,new QTableWidgetItem("----"));
        }
        else
        {
            ui->table->setItem(i,2,new QTableWidgetItem(QString::fromStdString(std::to_string(dates[i].duration(dates[i-1])))));
        }
    }
}

void MainWindow::on_pushButton_4_clicked()
{
    auto a = QFileDialog::getOpenFileName(0,"Выберите файл","","*.txt");
    if(a =="") return;

    if(checkFile(a))
    {
        file_path = a;
        len = 1;
        delete[]dates;
        dates = new Date[2];
        rewrite = false;
        ui->table->clear();
        ui->table->setHorizontalHeaderLabels(QStringList{"Исходная дата","Следующий день","Разница с предыдущим"});

        load_base();
        rewrite = true;

        qDebug() << file_path;
    }
    else
    {
        QWidget* window = new QWidget();
        window->setWindowTitle("Ошибка");
        QGridLayout* mainLay = new QGridLayout;
        QLabel* lbl = new QLabel("Даный файл не может использоваться в качестве базы");


        mainLay->addWidget(lbl, 0, 0);

        window->setLayout(mainLay);

        window->show();

        qDebug()<< "fuck";
    }



}

void MainWindow::on_pushButton_clicked()
{
    QWidget* window = new QWidget();
    window->setWindowTitle("Ввод");
    QGridLayout* mainLay = new QGridLayout;
    QLabel* lbl = new QLabel("День: ");
    QSpinBox* spbn = new QSpinBox;
    spbn->setRange(1, 31);
    QSpinBox* spbn_1 = new QSpinBox;
    spbn_1->setRange(1, 12);
    QSpinBox* spbn_2 = new QSpinBox;
    spbn_2->setRange(1800,2022);

    QPushButton* ok = new QPushButton();
    ok ->setText("Ок");

    QPushButton* cancel = new QPushButton();
    cancel ->setText("Отмена");


    mainLay->addWidget(lbl, 0, 0);
    mainLay->addWidget(spbn, 0, 1);
    mainLay->addWidget(new QLabel("Месяц: "), 1, 0);
    mainLay->addWidget(spbn_1, 1, 1);
    mainLay->addWidget(new QLabel("Год: "), 2, 0);
    mainLay->addWidget(spbn_2, 2, 1);

    mainLay->addWidget(ok,3,0);
    mainLay->addWidget(cancel,3,1);

    window->setLayout(mainLay);

    window->show();

    mass[0]=spbn->value();
    mass[1]=spbn_1->value();
    mass[2]=spbn_2->value();

    connect(ok, SIGNAL(clicked()),this,SLOT(addNew()));
    connect(ok, SIGNAL(clicked()),window,SLOT(close()));
    connect(cancel, SIGNAL(clicked()),window,SLOT(close()));

    connect(spbn, SIGNAL(valueChanged(int)),this,SLOT(spbn_value(int)));
    connect(spbn_1, SIGNAL(valueChanged(int)),this,SLOT(spbn_2_value(int)));
    connect(spbn_2, SIGNAL(valueChanged(int)),this,SLOT(spbn_3_value(int)));
}

void MainWindow::on_pushButton_5_clicked()
{
    QWidget* window = new QWidget();
    window->setWindowTitle("Ввод");
    QGridLayout* mainLay = new QGridLayout;
    QLabel* lbl = new QLabel("День: ");
    QSpinBox* spbn = new QSpinBox;
    spbn->setRange(1, 31);
    QSpinBox* spbn_1 = new QSpinBox;
    spbn_1->setRange(1, 12);
    QSpinBox* spbn_2 = new QSpinBox;
    spbn_2->setRange(1800,2022);

    QPushButton* ok = new QPushButton();
    ok ->setText("Ок");

    QPushButton* cancel = new QPushButton();
    cancel ->setText("Отмена");


    mainLay->addWidget(lbl, 0, 0);
    mainLay->addWidget(spbn, 0, 1);
    mainLay->addWidget(new QLabel("Месяц: "), 1, 0);
    mainLay->addWidget(spbn_1, 1, 1);
    mainLay->addWidget(new QLabel("Год: "), 2, 0);
    mainLay->addWidget(spbn_2, 2, 1);

    mainLay->addWidget(ok,3,0);
    mainLay->addWidget(cancel,3,1);

    window->setLayout(mainLay);

    window->show();

    mass[0]=spbn->value();
    mass[1]=spbn_1->value();
    mass[2]=spbn_2->value();

    connect(ok, SIGNAL(clicked()),this,SLOT(edit()));
    connect(ok, SIGNAL(clicked()),window,SLOT(close()));
    connect(cancel, SIGNAL(clicked()),window,SLOT(close()));

    connect(spbn, SIGNAL(valueChanged(int)),this,SLOT(spbn_value(int)));
    connect(spbn_1, SIGNAL(valueChanged(int)),this,SLOT(spbn_2_value(int)));
    connect(spbn_2, SIGNAL(valueChanged(int)),this,SLOT(spbn_3_value(int)));
}

void MainWindow::edit()
{
    dates[ui->spinBox_4->value()-1]=Date(mass[0],mass[1],mass[2]);
    edit_file(dates,ui->spinBox_4->value()-1);

    ui->table->setItem(ui->spinBox_4->value()-1,0,new QTableWidgetItem(dates[ui->spinBox_4->value()-1].str()));
    qDebug()<<"da";
    ui->table->setItem(ui->spinBox_4->value()-1,1,new QTableWidgetItem(dates[ui->spinBox_4->value()-1].nextDay().str()));
    qDebug()<<"nda";
    if(ui->spinBox_4->value()==1)
    {
        ui->table->setItem(ui->spinBox_4->value()-1,2,new QTableWidgetItem("----"));
    }
    else
    {
        ui->table->setItem(ui->spinBox_4->value()-1,2,new QTableWidgetItem(QString::fromStdString(std::to_string(dates[ui->spinBox_4->value()-1].duration(dates[ui->spinBox_4->value()-2])))));
    }

}

bool MainWindow::checkFile(QString a)
{
    bool ch = true;
    QFile f(a);

    qDebug()<<1;
    if (f.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug()<<"da";
        while(!f.atEnd())
        {
            QByteArray line = f.readLine();

            QString h = line;

            char* dd = (char*)calloc(3, sizeof(char));
            dd [0]= h.toStdString()[0];
            dd[1] = h.toStdString()[1];
            char* mm = (char*)calloc(3, sizeof(char));
            mm[0] = h.toStdString()[3];
            mm[1] = h.toStdString()[4];
            char* yy = (char*)calloc(5, sizeof(char));
            yy[0] = h.toStdString()[6];
            yy[1] = h.toStdString()[7];
            yy[2] = h.toStdString()[8];
            yy[3] = h.toStdString()[9];
            qDebug()<<sizeof(line) << " asd";
            if(atoi(dd) >= 32 || atoi(mm) >= 13 || atoi(yy) < 1500 || atoi(yy) > 2022 || h[2] != '.' || h[5] != '.' || h[10]!='\n')
            {
                qDebug()<<line << atoi(dd) << atoi(mm) << atoi(yy);
                ch=false;
            }
            free(dd);
            free(mm);
            free(yy);
        }
        return ch;
    }

}
