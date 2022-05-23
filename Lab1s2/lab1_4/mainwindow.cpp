#include "mainwindow.h"
#include "ui_mainwindow.h"

QString file_path = "C:\\Users\\0w0\\Documents\\lab1_4\\dishes.txt";

QString label_p;
QString cat_p;
double pr_p;


int len_d = 0;
int len_o = 0;
int p;
int* mass = new int [3];
bool rewrite = false;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->dishes_t->setColumnCount(3);
    ui->dishes_t->setRowCount(1);
    ui->dishes_t->setColumnWidth(0,200);
    ui->dishes_t->setColumnWidth(1,165);
    ui->dishes_t->setColumnWidth(2,100);
    ui->dishes_t->setHorizontalHeaderLabels(QStringList{"Название\nблюда","Категория","Цена BYN"});

    ui->orders_t->setColumnCount(4);
    ui->orders_t->setRowCount(1);
    ui->orders_t->setColumnWidth(0,85);
    ui->orders_t->setColumnWidth(1,85);
    ui->orders_t->setColumnWidth(2,200);
    ui->orders_t->setColumnWidth(3,100);
    ui->orders_t->setHorizontalHeaderLabels(QStringList{"Номер\nстолика","Номер\nзаказа","Название блюда","Количество"});

    ui->dishes_t->setEditTriggers(NULL);
    ui->orders_t->setEditTriggers(NULL);

    loadBase();
}

MainWindow::~MainWindow()
{
    delete ui;    
}

void MainWindow::addNewDish()
{
    qDebug()<<1;
    Food* dishes_f = new Food[len_d+1];
    qDebug()<<len_d;
    for(int i = 0; i<len_d; i++)
    {
        qDebug()<<i;
        dishes_f[i]=dishes[i];
    }
    delete[]dishes;
    dishes=dishes_f;
    len_d++;
    dishes[len_d-1]=Food(label_p,cat_p,pr_p);

    ui->dishes_t->setRowCount(len_d);
    ui->dishes_t->setItem(len_d-1,0,new QTableWidgetItem(dishes[len_d-1].label));
    qDebug()<<"da";
    ui->dishes_t->setItem(len_d-1,1,new QTableWidgetItem(dishes[len_d-1].category));
    qDebug()<<"nda";
    qDebug()<<(double)dishes[len_d-1].price;
    QString price_t = QString::fromStdString(std::to_string(dishes[len_d-1].price));
    price_t[price_t.length()-4]='\0';
    price_t[price_t.length()-3]='\0';
    price_t[price_t.length()-2]='\0';
    price_t[price_t.length()-1]='\0';
    ui->dishes_t->setItem(len_d-1,2, new QTableWidgetItem(price_t));
}

void MainWindow::addNewOrder()
{
    qDebug()<<1;
    Order* orders_f = new Order[len_o+1];
    qDebug()<<len_o;
    for(int i = 0; i<len_o; i++)
    {
        qDebug()<<i;
        orders_f[i]=orders[i];
    }
    delete[]orders;
    orders=orders_f;
    len_o++;
    orders[len_o-1]=Order(mass[0],label_p,Food(dishes[mass[2]-1].label,dishes[mass[2]-1].category,dishes[mass[2]-1].price),mass[1]);

    ui->orders_t->setRowCount(len_o);
    ui->orders_t->setItem(len_o-1,0,new QTableWidgetItem(QString::fromStdString(std::to_string(orders[len_o-1].table))));
    qDebug()<<"da";
    ui->orders_t->setItem(len_o-1,1,new QTableWidgetItem(orders[len_o-1].id));
    qDebug()<<"nda";
    ui->orders_t->setItem(len_o-1,2, new QTableWidgetItem(orders[len_o-1].dish.label));
    ui->orders_t->setItem(len_o-1,3, new QTableWidgetItem(QString::fromStdString(std::to_string(orders[len_o-1].dishes_num))));
}

void MainWindow::on_pushButton_clicked()
{
    QWidget* window = new QWidget();
    window->setWindowTitle("Ввод нового блюда");
    QGridLayout* mainLay = new QGridLayout;
    QSpinBox* spbn = new QSpinBox;
    spbn->setRange(1, len_d);
    QLineEdit* title = new QLineEdit;
    QLineEdit* cat = new QLineEdit;
    QDoubleSpinBox* price = new QDoubleSpinBox;

    price->setRange(0.10, 99.99);

    QPushButton* ok = new QPushButton();
    ok ->setText("Ок");

    QPushButton* cancel = new QPushButton();
    cancel ->setText("Отмена");


    mainLay->addWidget(new QLabel("Название :"), 0, 0);
    mainLay->addWidget(title, 0, 1);
    mainLay->addWidget(new QLabel("Категория : "), 1, 0);
    mainLay->addWidget(cat, 1, 1);
    mainLay->addWidget(new QLabel("Цена :"), 2, 0);
    mainLay->addWidget(price, 2, 1);


    mainLay->addWidget(ok,3,0);
    mainLay->addWidget(cancel,3,1);

    window->setLayout(mainLay);

    window->show();

    pr_p=price->value();

    mass[0]=spbn->value();

    connect(ok, SIGNAL(clicked()),this,SLOT(addNewDish()));
    connect(ok, SIGNAL(clicked()),window,SLOT(close()));
    connect(cancel, SIGNAL(clicked()),window,SLOT(close()));

    connect(title, SIGNAL(textChanged(QString)), this, SLOT(title(QString)));
    connect(cat, SIGNAL(textChanged(QString)), this, SLOT(category(QString)));
    connect(price, SIGNAL(valueChanged(double)), this, SLOT(price(double)));
    connect(spbn, SIGNAL(valueChanged(int)),this,SLOT(spbn_value(int)));
}

void MainWindow::title(QString a)
{
    label_p = a;
}

void MainWindow::category(QString a)
{
    cat_p = a;
}

void MainWindow::price(double a)
{
    pr_p=a;
    qDebug()<<a;
}

void MainWindow::on_pushButton_3_clicked()
{
    QWidget* window = new QWidget();
    window->setWindowTitle("Ввод");
    QGridLayout* mainLay = new QGridLayout;
    QLabel* lbl = new QLabel("Строка: ");
    QSpinBox* spbn = new QSpinBox;
    spbn->setRange(1, len_d);

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

    connect(ok, SIGNAL(clicked()),this,SLOT(delete_dish()));
    connect(ok, SIGNAL(clicked()),window,SLOT(close()));
    connect(cancel, SIGNAL(clicked()),window,SLOT(close()));

    connect(spbn, SIGNAL(valueChanged(int)),this,SLOT(spbn_value(int)));
}

void MainWindow::delete_dish()
{
    qDebug()<<len_d;
    bool already = true;
    int o = 0;
    Food* n_food = new Food[len_d-1];
    for(int i = 0; i<len_d;i++)
    {
        if(i==mass[0]-1)
            i++;
        qDebug()<<dishes[i].label;
        n_food[o]=dishes[i];
        o++;
    }
    len_d--;
    delete [] dishes;
    dishes = n_food;

    rewriteTableDish();
}

void MainWindow::delete_order()
{
    qDebug()<<len_d;
    bool already = true;
    Order* n_or = new Order[len_o-1];
    for(int i = 0; i<len_o-1;i++)
    {
        if(i!=mass[0]-1&&already)
        {
            n_or[i]=orders[i];
        }
        else
        {
            already = false;
        }

        if(!already)
        {
            n_or[i]=orders[i+1];
        }
    }
    len_o--;
    delete [] orders;
    orders = n_or;
    qDebug()<<len_o;
    rewriteTableOrder();
}

void MainWindow::rewriteTableDish()
{
    ui->dishes_t->clear();
    ui->dishes_t->setHorizontalHeaderLabels(QStringList{"Название\nблюда","Категория","Цена BYN"});
    ui->dishes_t->setRowCount(len_d);
    for(int i = 0; i< len_d;i++)
    {
        ui->dishes_t->setItem(i,0,new QTableWidgetItem(dishes[i].label));
        ui->dishes_t->setItem(i,1,new QTableWidgetItem(dishes[i].category));
        QString price_t = QString::fromStdString(std::to_string(dishes[i].price));
        price_t[price_t.length()-4]='\0';
        price_t[price_t.length()-3]='\0';
        price_t[price_t.length()-2]='\0';
        price_t[price_t.length()-1]='\0';
        ui->dishes_t->setItem(i,2, new QTableWidgetItem(price_t));
    }
}

void MainWindow::rewriteTableOrder()
{
    ui->orders_t->clear();
    ui->orders_t->setHorizontalHeaderLabels(QStringList{"Номер\nстолика","Номер\nзаказа","Название блюда","Количество"});
    ui->orders_t->setRowCount(len_o);
    for(int i = 0; i< len_o;i++)
    {
        ui->orders_t->setItem(i,0,new QTableWidgetItem(QString::fromStdString(std::to_string(orders[i].table))));
        ui->orders_t->setItem(i,1,new QTableWidgetItem(orders[i].id));
        ui->orders_t->setItem(i,2,new QTableWidgetItem(orders[i].dish.label));
        ui->orders_t->setItem(i,3, new QTableWidgetItem(QString::fromStdString(std::to_string(orders[i].dishes_num))));
    }
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

void MainWindow::on_pushButton_2_clicked()
{
    QWidget* window = new QWidget();
    window->setWindowTitle("Ввод нового блюда");
    QGridLayout* mainLay = new QGridLayout;
    QSpinBox* spbn = new QSpinBox;
    spbn->setRange(1, len_d);
    QLineEdit* title = new QLineEdit;
    QLineEdit* cat = new QLineEdit;
    QDoubleSpinBox* price = new QDoubleSpinBox;

    price->setRange(0.10, 99.99);

    QPushButton* ok = new QPushButton();
    ok ->setText("Ок");

    QPushButton* cancel = new QPushButton();
    cancel ->setText("Отмена");

    mainLay->addWidget(new QLabel("Номер блюда: "),0,0);
    mainLay->addWidget(spbn, 0,1);
    mainLay->addWidget(new QLabel("Название :"), 1, 0);
    mainLay->addWidget(title, 1, 1);
    mainLay->addWidget(new QLabel("Категория : "), 2, 0);
    mainLay->addWidget(cat, 2, 1);
    mainLay->addWidget(new QLabel("Цена :"), 3, 0);
    mainLay->addWidget(price, 3, 1);


    mainLay->addWidget(ok,4,0);
    mainLay->addWidget(cancel,4,1);

    window->setLayout(mainLay);

    window->show();

    pr_p = price->value();
    mass[0]=spbn->value();
    label_p = dishes[mass[0]].label;
    cat_p = dishes[mass[0]].category;

    connect(ok, SIGNAL(clicked()),this,SLOT(editDish()));
    connect(ok, SIGNAL(clicked()),window,SLOT(close()));
    connect(cancel, SIGNAL(clicked()),window,SLOT(close()));

    connect(title, SIGNAL(textChanged(QString)), this, SLOT(title(QString)));
    connect(cat, SIGNAL(textChanged(QString)), this, SLOT(category(QString)));
    connect(price, SIGNAL(valueChanged(double)), this, SLOT(price(double)));
    connect(spbn, SIGNAL(valueChanged(int)),this,SLOT(spbn_value(int)));
}

void MainWindow::editDish()
{
    dishes[mass[0]-1].label=label_p;
    dishes[mass[0]-1].category=cat_p;
    dishes[mass[0]-1].price=pr_p;
    rewriteTableDish();
}

void MainWindow::on_pushButton_7_clicked()
{
    QString* cat_m = new QString[len_d];
    int amount = 1;
    bool ch = true;
    cat_m[0] = dishes[0].category;
    for(int i = 1; i<len_d;i++)
    {

        qDebug()<<dishes[i].category << amount;
        for(int y = 0; y < amount;y++)
        {
            if(cat_m[y]==dishes[i].category)
                ch=false;
        }
        if(ch)
        {
            cat_m[amount]=dishes[i].category;
            amount++;

        }
        ch = true;
    }
    qDebug()<<len_d;
    int* pop = new int[len_d];

    for(int i = 0; i<len_d;i++)
    {
        pop[i]=0;
    }

    for(int y = 0;y<len_o;y++)
    {
        for(int x = 0; x<len_d;x++)
        {
            if(dishes[x].label == orders[y].dish.label)
            {
                qDebug()<<dishes[x].label << orders[y].dishes_num;
                pop[x]+= orders[y].dishes_num;
            }
        }
    }

    int* most = new int [amount];

    for(int i = 0; i<amount;i++)
    {
        most[i]=-1;
    }

    for(int i = 0;i<amount;i++)
    {
        for(int y = 0; y< len_d;y++)
        {
            if(cat_m[i]==dishes[y].category)
            {
                if(most[i]==-1)
                {
                    most[i]=y;
                }
                else
                {
                    if(pop[most[i]]<pop[y])
                        most[i]=y;
                }
            }
        }
    }

    QWidget* window = new QWidget();
    window->setWindowTitle("Топ по категориям");
    QGridLayout* mainLay = new QGridLayout;
    mainLay->addWidget(new QLabel("Категория :"),0,0);
    mainLay->addWidget(new QLabel("Блюдо :"),0,1);

    for(int i = 0;i<amount;i++)
    {
        mainLay->addWidget(new QLabel(cat_m[i]),i+1,0);
        if(most[i]==-1)
            mainLay->addWidget(new QLabel("-"),i+1,1);
        else
            mainLay->addWidget(new QLabel(dishes[most[i]].label),i+1,1);
    }
    window->setLayout(mainLay);
    window->show();
}

void MainWindow::on_pushButton_4_clicked()
{
    QWidget* window = new QWidget();
    window->setWindowTitle("Ввод нового заказа");
    QGridLayout* mainLay = new QGridLayout;
    QSpinBox* spbn = new QSpinBox;
    spbn->setRange(1, 10);

    QSpinBox* spbn_2 = new QSpinBox;
    spbn_2->setRange(1, 10);

    QSpinBox* spbn_3 = new QSpinBox;
    spbn_3->setRange(1, len_d);

    QPushButton* ok = new QPushButton();
    ok ->setText("Ок");

    QPushButton* cancel = new QPushButton();
    cancel ->setText("Отмена");
    label_p=QString::fromStdString("OR"+std::to_string(1000*(rand()%10)+100*(rand()%10)+10*(rand()%10)+(rand()%10)));

    mainLay->addWidget(new QLabel("Номер заказа :"), 0, 0);
    mainLay->addWidget(new QLabel(label_p), 0, 1);
    mainLay->addWidget(new QLabel("Количество порций : "), 1, 0);
    mainLay->addWidget(spbn_2, 1, 1);
    mainLay->addWidget(new QLabel("Номер столика :"), 2, 0);
    mainLay->addWidget(spbn, 2, 1);
    mainLay->addWidget(new QLabel("Номер блюда(см. список блюд) :"), 3, 0);
    mainLay->addWidget(spbn_3, 3, 1);

    mainLay->addWidget(ok,4,0);
    mainLay->addWidget(cancel,4,1);

    window->setLayout(mainLay);

    window->show();

    mass[0]=spbn->value();
    mass[1]=spbn_2->value();
    mass[2]=spbn_3->value();

    connect(ok, SIGNAL(clicked()),this,SLOT(addNewOrder()));
    connect(ok, SIGNAL(clicked()),window,SLOT(close()));
    connect(cancel, SIGNAL(clicked()),window,SLOT(close()));

    connect(spbn, SIGNAL(valueChanged(int)),this,SLOT(spbn_value(int)));
    connect(spbn_2, SIGNAL(valueChanged(int)),this,SLOT(spbn_2_value(int)));
    connect(spbn_3, SIGNAL(valueChanged(int)),this,SLOT(spbn_3_value(int)));
}

void MainWindow::on_pushButton_6_clicked()
{
    QWidget* window = new QWidget();
    window->setWindowTitle("Ввод");
    QGridLayout* mainLay = new QGridLayout;
    QLabel* lbl = new QLabel("Строка: ");
    QSpinBox* spbn = new QSpinBox;
    spbn->setRange(1, len_o);

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

    connect(ok, SIGNAL(clicked()),this,SLOT(delete_order()));
    connect(ok, SIGNAL(clicked()),window,SLOT(close()));
    connect(cancel, SIGNAL(clicked()),window,SLOT(close()));

    connect(spbn, SIGNAL(valueChanged(int)),this,SLOT(spbn_value(int)));
}

void MainWindow::qsort(int start, int end)
{
    qDebug()<< start << end;
    double mid = orders[(start+end)/2].orderPrice();
    int s = start, e = end;

    do{
        qDebug()<<"d";
        while(orders[s].orderPrice()>mid)
            s++;
        while(orders[e].orderPrice()<mid)
            e--;
        if(s<=e)
        {
            Order a = Order(orders[s].table,orders[s].id,Food(orders[s].dish.label,orders[s].dish.category,orders[s].dish.price),orders[s].dishes_num);
            orders [s]=Order(orders[e].table,orders[e].id,Food(orders[e].dish.label,orders[e].dish.category,orders[e].dish.price),orders[e].dishes_num);
            orders [e]=Order(a.table,a.id,Food(a.dish.label,a.dish.category,a.dish.price),a.dishes_num);
            s++;
            e--;
        }
    }while(s<=e);

    qDebug()<<"l";
    if(start<e)
        qsort(start,e);
    if(s<end)
        qsort(s,end);
}

void MainWindow::on_pushButton_8_clicked()
{
    qDebug()<<len_o;
    qsort(0,len_o-1);
    rewriteTableOrder();

    QWidget* window = new QWidget();
    window->setWindowTitle("Ввод");
    QGridLayout* mainLay = new QGridLayout;

    mainLay->addWidget(new QLabel("Номер заказа:"),0,0);
    mainLay->addWidget(new QLabel(orders[0].id),0,1);
    mainLay->addWidget(new QLabel("Выручка:"),1,0);
    mainLay->addWidget(new QLabel(QString::fromStdString(std::to_string(orders[0].orderPrice()))),1,1);

    window->setLayout(mainLay);

    window->show();

}

void MainWindow::loadBase()
{
    QFile f("C:\\Users\\0w0\\Documents\\lab1_4\\dishes_base.txt");

    qDebug()<<1;
    if (f.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug()<<"da";
        while(!f.atEnd())
        {
            QByteArray line = f.readLine();
            qDebug()<<line;

            label_p = line;
            line = f.readLine();
            qDebug()<<line;
            cat_p=line;
            line = f.readLine();
            qDebug()<<"double" << line;
            pr_p=std::stod(line.toStdString());
            addNewDish();
        }
    }
}

void MainWindow::on_pushButton_9_clicked()
{
    QFile f("C:\\Users\\0w0\\Documents\\lab1_4\\dishes_base.txt");

    qDebug()<<1;
    if (f.open(QIODevice::WriteOnly | QIODevice::Truncate))
    {
        f.close();
    }

    qDebug()<<2;
    QFile fout("C:\\Users\\0w0\\Documents\\lab1_4\\dishes_base.txt");

    if(fout.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream write(&fout);
        qDebug()<<3;
        for(int i = 0; i<len_d;i++)
        {
            write<<QByteArray::fromStdString(dishes[i].label.toStdString()+"\n");
            write<<QByteArray::fromStdString(dishes[i].category.toStdString()+"\n");
            write<<QByteArray::fromStdString(std::to_string(dishes[i].price)+"\n");
        }
    }
}

void MainWindow::on_pushButton_5_clicked()
{
    auto a = QFileDialog::getOpenFileName(0,"Выберите файл","","*.txt");
    if(a =="") return;

    if(checkFile(a))
    {
        file_path = a;
        len_d = 0;
        delete[]dishes;
        dishes = new Food[2];
        rewrite = false;
        ui->dishes_t->clear();
        ui->dishes_t->setHorizontalHeaderLabels(QStringList{"Название\nблюда","Категория","Цена BYN"});

        loadBase();
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
            line = f.readLine();
            line=f.readLine();


            try {
                std::stod(line.toStdString());
            } catch (std::invalid_argument) {
                ch=false;
            }
        }
        return ch;
    }

}
