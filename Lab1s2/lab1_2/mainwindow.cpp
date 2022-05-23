#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "circle.h"

#define pi 3.14159265358

int x_t,y_t,x_d,y_d,i;
int* mass = new int [4];
QPolygon t;
bool drawing = false;
QPoint start = QPoint(-0,-0), prev;

QGraphicsItem* Item;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(570,0,700,700, this);
    ui->graphicsView->setScene(scene);


    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), scene, SLOT(advance()));
    timer -> start(1000/60);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_horizontalSlider_2_sliderMoved(int position)
{
    Item->setTransformOriginPoint(x_t+580,y_t);
    Item->setRotation(position);
}


void MainWindow::on_spinBox_2_valueChanged(int arg1)
{
    x_t = arg1;
}

void MainWindow::on_spinBox_valueChanged(int arg1)
{
    y_t = arg1;
}

void MainWindow::on_horizontalSlider_3_sliderMoved(int position)
{
    Item->setTransformOriginPoint(x_t+580,y_t);
    Item->setScale((double)position/100);
}

void MainWindow::on_radioButton_clicked()
{
    QWidget* window = new QWidget();
    window->setWindowTitle("Настройка");
    QGridLayout* mainLay = new QGridLayout;
    QLabel* lbl = new QLabel("Количество Вершин: ");
    QSpinBox* spbn = new QSpinBox;
    spbn->setRange(5, 30);

    QSpinBox* spbn_r = new QSpinBox;
    spbn_r->setRange(50, 300);

    QSpinBox* spbn_R = new QSpinBox;
    spbn_R->setRange(60, 400);


    QPushButton* ok = new QPushButton();
    ok ->setText("Ок");

    QPushButton* cancel = new QPushButton();
    cancel ->setText("Отмена");


    mainLay->addWidget(lbl, 0, 0);
    mainLay->addWidget(spbn, 0, 1);
    mainLay->addWidget(new QLabel("Внутренний радиус: "), 1, 0);
    mainLay->addWidget(spbn_r, 1, 1);
    mainLay->addWidget(new QLabel("Внешний радиусс: "), 2, 0);
    mainLay->addWidget(spbn_R, 2, 1);

    mainLay->addWidget(ok,3,1);
    mainLay->addWidget(cancel,3,0);

    window->setLayout(mainLay);

    window->show();

    mass[0]=spbn->value();
    mass[1]=spbn_r->value();
    mass[2]=spbn_R->value();

    i = 1;

    connect(ok, SIGNAL(clicked()),this,SLOT(star_button()));
    connect(ok, SIGNAL(clicked()),window,SLOT(close()));
    connect(cancel, SIGNAL(clicked()),window,SLOT(close()));

    connect(spbn, SIGNAL(valueChanged(int)),this,SLOT(spbn_value(int)));
    connect(spbn_r, SIGNAL(valueChanged(int)),this,SLOT(spbn_2_value(int)));
    connect(spbn_R, SIGNAL(valueChanged(int)), this, SLOT(spbn_3_value(int)));

}

void MainWindow::on_radioButton_2_clicked()
{
    QWidget* window = new QWidget();
    window->setWindowTitle("Настройка");
    QGridLayout* mainLay = new QGridLayout;
    QLabel* lbl = new QLabel("Длина стороны: ");
    QSpinBox* spbn = new QSpinBox;
    spbn->setRange(10, 500);

    QPushButton* ok = new QPushButton();
    ok ->setText("Ок");

    QPushButton* cancel = new QPushButton();
    cancel ->setText("Отмена");


    mainLay->addWidget(lbl, 0, 0);
    mainLay->addWidget(spbn, 0, 1);

    mainLay->addWidget(ok,3,1);
    mainLay->addWidget(cancel,3,0);

    window->setLayout(mainLay);

    window->show();

    mass[0]=spbn->value();

    i = 2;

    connect(ok, SIGNAL(clicked()),this,SLOT(star_button()));
    connect(ok, SIGNAL(clicked()),window,SLOT(close()));
    connect(cancel, SIGNAL(clicked()),window,SLOT(close()));

    connect(spbn, SIGNAL(valueChanged(int)),this,SLOT(spbn_value(int)));
}

void MainWindow::on_radioButton_3_clicked()
{
    QWidget* window = new QWidget();
    window->setWindowTitle("Настройка");
    QGridLayout* mainLay = new QGridLayout;
    QLabel* lbl = new QLabel("Длина: ");
    QSpinBox* spbn = new QSpinBox;
    spbn->setRange(100, 500);

    QSpinBox* spbn_r = new QSpinBox;
    spbn_r->setRange(50, 300);


    QPushButton* ok = new QPushButton();
    ok ->setText("Ок");

    QPushButton* cancel = new QPushButton();
    cancel ->setText("Отмена");


    mainLay->addWidget(lbl, 0, 0);
    mainLay->addWidget(spbn, 0, 1);
    mainLay->addWidget(new QLabel("Ширина: "), 1, 0);
    mainLay->addWidget(spbn_r, 1, 1);

    mainLay->addWidget(ok,3,1);
    mainLay->addWidget(cancel,3,0);

    window->setLayout(mainLay);

    window->show();

    mass[0]=spbn->value();
    mass[1]=spbn_r->value();

    i = 3;

    connect(ok, SIGNAL(clicked()),this,SLOT(star_button()));
    connect(ok, SIGNAL(clicked()),window,SLOT(close()));
    connect(cancel, SIGNAL(clicked()),window,SLOT(close()));

    connect(spbn, SIGNAL(valueChanged(int)),this,SLOT(spbn_value(int)));
    connect(spbn_r, SIGNAL(valueChanged(int)),this,SLOT(spbn_2_value(int)));
}

void MainWindow::on_radioButton_4_clicked()
{
    QWidget* window = new QWidget();
    window->setWindowTitle("Настройка");
    QGridLayout* mainLay = new QGridLayout;
    QLabel* lbl = new QLabel("1 диагональ: ");
    QSpinBox* spbn = new QSpinBox;
    spbn->setRange(100, 500);

    QSpinBox* spbn_r = new QSpinBox;
    spbn_r->setRange(100, 300);


    QPushButton* ok = new QPushButton();
    ok ->setText("Ок");

    QPushButton* cancel = new QPushButton();
    cancel ->setText("Отмена");


    mainLay->addWidget(lbl, 0, 0);
    mainLay->addWidget(spbn, 0, 1);
    mainLay->addWidget(new QLabel("2 диагональ: "), 1, 0);
    mainLay->addWidget(spbn_r, 1, 1);

    mainLay->addWidget(ok,3,1);
    mainLay->addWidget(cancel,3,0);

    window->setLayout(mainLay);

    window->show();

    mass[0]=spbn->value();
    mass[1]=spbn_r->value();

    i = 4;

    connect(ok, SIGNAL(clicked()),this,SLOT(star_button()));
    connect(ok, SIGNAL(clicked()),window,SLOT(close()));
    connect(cancel, SIGNAL(clicked()),window,SLOT(close()));

    connect(spbn, SIGNAL(valueChanged(int)),this,SLOT(spbn_value(int)));
    connect(spbn_r, SIGNAL(valueChanged(int)),this,SLOT(spbn_2_value(int)));
}

void MainWindow::on_radioButton_5_clicked()
{
    QWidget* window = new QWidget();
    window->setWindowTitle("Настройка");
    QGridLayout* mainLay = new QGridLayout;
    QLabel* lbl = new QLabel("1 сторона: ");
    QSpinBox* spbn = new QSpinBox;
    spbn->setRange(50, 500);

    QSpinBox* spbn_r = new QSpinBox;
    spbn_r->setRange(50, 500);

    QSpinBox* spbn_R = new QSpinBox;
    spbn_R->setRange(50, 500);


    QPushButton* ok = new QPushButton();
    ok ->setText("Ок");

    QPushButton* cancel = new QPushButton();
    cancel ->setText("Отмена");


    mainLay->addWidget(lbl, 0, 0);
    mainLay->addWidget(spbn, 0, 1);
    mainLay->addWidget(new QLabel("2 сторона: "), 1, 0);
    mainLay->addWidget(spbn_r, 1, 1);
    mainLay->addWidget(new QLabel("3 сторона: "), 2, 0);
    mainLay->addWidget(spbn_R, 2, 1);

    mainLay->addWidget(ok,3,1);
    mainLay->addWidget(cancel,3,0);

    window->setLayout(mainLay);

    window->show();

    mass[0]=spbn->value();
    mass[1]=spbn_r->value();
    mass[2]=spbn_R->value();

    i = 5;

    connect(ok, SIGNAL(clicked()),this,SLOT(tr_check()));
    connect(ok, SIGNAL(clicked()),window,SLOT(close()));
    connect(cancel, SIGNAL(clicked()),window,SLOT(close()));

    connect(spbn, SIGNAL(valueChanged(int)),this,SLOT(spbn_value(int)));
    connect(spbn_r, SIGNAL(valueChanged(int)),this,SLOT(spbn_2_value(int)));
    connect(spbn_R, SIGNAL(valueChanged(int)), this, SLOT(spbn_3_value(int)));
}

void MainWindow::on_radioButton_6_clicked()
{
    QWidget* window = new QWidget();
    window->setWindowTitle("Настройка");
    QGridLayout* mainLay = new QGridLayout;
    QLabel* lbl = new QLabel("Радиус: ");
    QSpinBox* spbn = new QSpinBox;
    spbn->setRange(50, 400);

    QPushButton* ok = new QPushButton();
    ok ->setText("Ок");

    QPushButton* cancel = new QPushButton();
    cancel ->setText("Отмена");


    mainLay->addWidget(lbl, 0, 0);
    mainLay->addWidget(spbn, 0, 1);

    mainLay->addWidget(ok,3,1);
    mainLay->addWidget(cancel,3,0);

    window->setLayout(mainLay);

    window->show();

    mass[0]=spbn->value();

    i = 6;

    connect(ok, SIGNAL(clicked()),this,SLOT(star_button()));
    connect(ok, SIGNAL(clicked()),window,SLOT(close()));
    connect(cancel, SIGNAL(clicked()),window,SLOT(close()));

    connect(spbn, SIGNAL(valueChanged(int)),this,SLOT(spbn_value(int)));
}

void MainWindow::on_radioButton_7_clicked()
{
    QWidget* window = new QWidget();
    window->setWindowTitle("Настройка");
    QGridLayout* mainLay = new QGridLayout;
    QLabel* lbl = new QLabel("Количество Вершин: ");
    QSpinBox* spbn = new QSpinBox;
    spbn->setRange(5, 30);

    QSpinBox* spbn_r = new QSpinBox;
    spbn_r->setRange(50, 300);


    QPushButton* ok = new QPushButton();
    ok ->setText("Ок");

    QPushButton* cancel = new QPushButton();
    cancel ->setText("Отмена");


    mainLay->addWidget(lbl, 0, 0);
    mainLay->addWidget(spbn, 0, 1);
    mainLay->addWidget(new QLabel("Радиус описанной окружности: "), 1, 0);
    mainLay->addWidget(spbn_r, 1, 1);


    mainLay->addWidget(ok,3,1);
    mainLay->addWidget(cancel,3,0);

    window->setLayout(mainLay);

    window->show();

    mass[0]=spbn->value();
    mass[1]=spbn_r->value();

    i = 7;

    connect(ok, SIGNAL(clicked()),this,SLOT(star_button()));
    connect(ok, SIGNAL(clicked()),window,SLOT(close()));
    connect(cancel, SIGNAL(clicked()),window,SLOT(close()));

    connect(spbn, SIGNAL(valueChanged(int)),this,SLOT(spbn_value(int)));
    connect(spbn_r, SIGNAL(valueChanged(int)),this,SLOT(spbn_2_value(int)));
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

void MainWindow::star_button()
{
    change_figure(i,mass);
}

void MainWindow::tr_check()
{
    if((mass[0]+mass[1]>mass[2])&&(mass[0]+mass[2]>mass[1])&&(mass[1]+mass[2]>mass[0]))
    {
        change_figure(i,mass);
    }
    else
    {
        QWidget* window = new QWidget();
        window->setWindowTitle("Ошибка!");
        QGridLayout* mainLay = new QGridLayout;
        mainLay->addWidget(new QLabel("Данного треугольника не существует! Проверьте введенные данные"), 0,0);
        window->setLayout(mainLay);
        window->show();
    }
}

void MainWindow::change_figure(int i,int* mass)
{
    switch (i) {
    case 1:
        scene->clearFocus();
        delete Item;
        Item = (new Star(mass[0],mass[1], mass[2]))->star;
        title->setText("Фигура: Звезда");
        perimeter = sqrt(pow(mass[2]-mass[1]*sqrt(3)/2,2)+pow(mass[1]/2,2))*2*mass[0];
        square =mass[1]*mass[1]*sqrt(3)*mass[0]/4+(mass[2]-mass[1]*sqrt(3)/2)*mass[1]*mass[0]/2;
        mass_center_x = 220;
        mass_center_y = 100;
        scene->addItem(Item);
        x_d=0;y_d=0;
        ui->horizontalSlider_2->setValue(0);
        ui->horizontalSlider_3->setValue(0);
        ui->horizontalSlider_2->setTickPosition(QSlider::TicksLeft);
        ui->horizontalSlider_3->setTickPosition(QSlider::TicksLeft);
        break;
    case 2:
        scene->clearFocus();
        delete Item;
        Item = new Square(mass[0]);
        title->setText("Фигура : Квадрат");
        perimeter=(mass[0]*4);
        square=(mass[0]*mass[0]);
        mass_center_x=(220+mass[0]/2);
        mass_center_y=(100+mass[0]/2);
        scene->addItem(Item);
        x_d=0;y_d=0;

        ui->horizontalSlider_2->setValue(0);
        ui->horizontalSlider_3->setValue(0);
        ui->horizontalSlider_2->setTickPosition(QSlider::TicksLeft);
        ui->horizontalSlider_3->setTickPosition(QSlider::TicksLeft);
        break;
    case 3:
        scene->clearFocus();
        delete Item;
        title->setText("Фигура : Прямоугольник");
        perimeter=((mass[0]+mass[1])*2);
        square=(mass[0]*mass[1]);
        mass_center_x=(220+mass[0]/2);
        mass_center_y=(100+mass[1]/2);
        Item = new Rect(mass[0],mass[1]);
        scene->addItem(Item);
        x_d=0;y_d=0;

        ui->horizontalSlider_2->setValue(0);
        ui->horizontalSlider_3->setValue(0);
        ui->horizontalSlider_2->setTickPosition(QSlider::TicksLeft);
        ui->horizontalSlider_3->setTickPosition(QSlider::TicksLeft);
        break;
    case 4:
        scene->clearFocus();
        delete Item;
        Item = (new Rhomb(mass[0],mass[1]))->rhomb;
        title->setText("Фигура : Ромб");
        perimeter=(sqrt(pow(mass[0]/2,2)+pow(mass[1]/2,2))*4);
        square=(mass[0]*mass[1]/2);
        mass_center_x=(220);
        mass_center_y=(100);
        scene->addItem(Item);
        x_d=0;y_d=0;

        ui->horizontalSlider_2->setValue(0);
        ui->horizontalSlider_3->setValue(0);
        ui->horizontalSlider_2->setTickPosition(QSlider::TicksLeft);
        ui->horizontalSlider_3->setTickPosition(QSlider::TicksLeft);
        break;
    case 5:
        scene->clearFocus();
        delete Item;
        Item = (new Triang(mass[0],mass[1],mass[2]))->tr;
        title->setText("Фигура: Треугольник");
        perimeter = mass[1]+mass[2]+mass[0];
        square =sqrt(perimeter/2*(perimeter/2-mass[0])*(perimeter/2-mass[2])*(perimeter/2-mass[1]));
        mass_center_x = (220+220+mass[2]+220+mass[2]+(mass[0]*mass[0]-mass[1]*mass[1]-mass[2]*mass[2])/(2*mass[2]))/3;
        mass_center_y = (300+mass[1]*(1-pow((mass[0]*mass[0]-mass[1]*mass[1]-mass[2]*mass[2])/(2*mass[2]*mass[1]),2)))/3;
        scene->addItem(Item);
        x_d=0;y_d=0;

        ui->horizontalSlider_2->setValue(0);
        ui->horizontalSlider_3->setValue(0);
        ui->horizontalSlider_2->setTickPosition(QSlider::TicksLeft);
        ui->horizontalSlider_3->setTickPosition(QSlider::TicksLeft);
        break;
    case 6:
        scene->clearFocus();
        delete Item;
        Item = new Circle(mass[0]);
        title->setText("Фигура : Круг");
        perimeter=(2*3.1415*mass[0]);
        square=(3.1415*mass[0]*mass[0]);
        mass_center_x=(220+mass[0]);
        mass_center_y=(100+mass[1]);
        scene->addItem(Item);

        ui->horizontalSlider_2->setValue(0);
        ui->horizontalSlider_3->setValue(0);
        ui->horizontalSlider_2->setTickPosition(QSlider::TicksLeft);
        ui->horizontalSlider_3->setTickPosition(QSlider::TicksLeft);
        x_d=0;y_d=0;
        break;
    case 7:
        scene->clearFocus();
        delete Item;
        Item = (new Pol(mass[0],mass[1]))->pol;
        title->setText("Фигура: Правильный многоугольник");
        perimeter = mass[0]*mass[1];
        square =mass[1]*mass[1]*sqrt(3)*mass[0]/4;
        mass_center_x = 220;
        mass_center_y = 100;
        scene->addItem(Item);
        x_d=0;y_d=0;

        ui->horizontalSlider_2->setValue(0);
        ui->horizontalSlider_3->setValue(0);
        ui->horizontalSlider_2->setTickPosition(QSlider::TicksLeft);
        ui->horizontalSlider_3->setTickPosition(QSlider::TicksLeft);
        break;
    case 8:
        scene->clear();
        QGraphicsPolygonItem* a = new QGraphicsPolygonItem;
        a->setPolygon(t);
        Item = a;
        scene->addItem(a);
        title->setText("Фигура: многоугольник");
        perimeter = -1;
        square = -1;
    }
}

void MainWindow::on_pushButton_pressed()
{
    Item->moveBy(0,-10);
    y_t+=10;
    mass_center_y-=10;
}

void MainWindow::on_pushButton_2_pressed()
{
    Item->moveBy(0,-2);
    y_t+=2;
    y_d-=2;
    mass_center_y-=2;
}

void MainWindow::on_pushButton_7_pressed()
{
    Item->moveBy(0,2);
    y_t-=2;
    y_d+=2;
    mass_center_y+=2;
}

void MainWindow::on_pushButton_8_pressed()
{
    Item->moveBy(0,10);
    y_t-=10;
    y_d+=10;
    mass_center_y+=10;
}

void MainWindow::on_pushButton_6_pressed()
{
    Item->moveBy(2,0);
    x_t-=2;
    x_d+=2;
    mass_center_x+=2;
}

void MainWindow::on_pushButton_9_pressed()
{
    Item->moveBy(10,0);
    x_t-=10;
    x_d+=10;
    mass_center_x+=10;
}

void MainWindow::on_pushButton_3_pressed()
{
    Item->moveBy(-2,0);
    x_t+=2;
    x_d-=2;
    mass_center_x-=2;
}

void MainWindow::on_pushButton_5_pressed()
{
    Item->moveBy(-10,0);
    x_t+=10;
    x_d-=10;
    mass_center_x-=10;
}

void MainWindow::on_pushButton_11_pressed()
{
    Item->moveBy(5,-5);
    x_t-=5;y_t+=5;
    x_d+=5;y_d-=5;
    mass_center_x+=5;
    mass_center_y-=5;
}

void MainWindow::on_pushButton_10_pressed()
{
    Item->moveBy(-5,-5);
    x_t+=5;y_t+=5;
    x_d-=5;y_d-=5;
    mass_center_x-=5;
    mass_center_y-=5;
}

void MainWindow::on_pushButton_12_pressed()
{
    Item->moveBy(-5,5);
    x_t+=5;y_t-=5;
    x_d-=5;y_d+=5;
    mass_center_x-=5;
    mass_center_y+=5;
}

void MainWindow::on_pushButton_13_pressed()
{
    Item->moveBy(5,5);
    x_t-=5;y_t-=5;
    x_d+=5;y_d+=5;
    mass_center_x+=5;
    mass_center_y+=5;
}

void MainWindow::on_pushButton_4_clicked()
{
    QGridLayout* info = new QGridLayout;
    QWidget* window = new QWidget();
    window->setWindowTitle("Информация");
    QLabel* sq_t = new QLabel();
    QLabel* perimeter_t = new QLabel();
    QLabel* mx_t = new QLabel();
    QLabel* my_t = new QLabel();
    sq_t->setNum(square*Item->scale()*Item->scale());
    perimeter_t->setNum(perimeter*Item->scale());
    mx_t->setNum((-sqrt(pow(x_t+x_d+mass_center_x,2)+pow(y_t+y_d+mass_center_y,2))*sin(3.1415*(Item->rotation())/180)*int(bool(Item->rotation()))+mass_center_x)*Item->scale());
    my_t->setNum((sqrt(pow(x_t+x_d+mass_center_x,2)+pow(y_t+y_d+mass_center_y,2))*sin(3.1415*(Item->rotation())/180)*int(bool(Item->rotation()))+mass_center_y)*Item->scale());


    info->addWidget(title,0,0);
    info->addWidget(new QLabel("Площадь"), 1, 0);
    info->addWidget(sq_t,1,1);
    info->addWidget(new QLabel("Периметр"), 2, 0);
    info->addWidget(perimeter_t,2,1);
    info->addWidget(new QLabel("Координаты:"), 3, 0);
    info->addWidget(mx_t,3,1);
    info->addWidget(my_t,3,2);
    window->setLayout(info);
    window->show();
}

void MainWindow::on_radioButton_8_clicked()
{
    QWidget* window = new QWidget();
    window->setWindowTitle("Внимание!!!");

    QGridLayout* mainLay = new QGridLayout;
    setMouseTracking(true);

    QPushButton* ok = new QPushButton;
    QPushButton* cancel = new QPushButton;

    ok->setText("Ок");
    cancel->setText("Отмена");

    mainLay->addWidget(new QLabel("Вы готовы очистить сцену для создания новой фигуры? Вернуть фигуру будет невозможно!"));
    mainLay->addWidget(ok,1,1);
    mainLay->addWidget(cancel,1,2);
    window->setLayout(mainLay);

    window->show();

    connect(ok, SIGNAL(clicked()),this,SLOT(figure_add()));
    connect(ok, SIGNAL(clicked()),window,SLOT(close()));

    connect(cancel, SIGNAL(clicked()),window,SLOT(close()));
}

void MainWindow::figure_add()
{
    drawing = true;
    scene->clear();
    t.clear();
}

void MainWindow::mousePressEvent(QMouseEvent* e)
{
    if(drawing)
    {
        if(start == QPoint(-0,-0))
        {
            start = e->pos();
            prev = e->pos();
        }
        t<< QPoint(e->x(),e->y());
        scene->addLine(QLine(prev,e->pos()));
        prev = e->pos();
    }
}

void MainWindow::mouseDoubleClickEvent(QMouseEvent *e)
{
    if(drawing)
    {
        t<<QPoint(e->x(),e->y());
        drawing = false;
        scene->addLine(QLine(prev, e->pos()));
        scene->addLine(QLine(e->pos(),start));
        change_figure(8,mass);
    }

}

