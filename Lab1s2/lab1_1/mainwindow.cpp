#include "mainwindow.h"
#include "ui_mainwindow.h"

bool da = true;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(200,0,600,600, this);
    ui->graphicsView->setScene(scene);


    timer = new QTimer(this);
    createWheel();
    connect(timer, SIGNAL(timeout()), scene, SLOT(advance()));
    timer -> start(1000/60);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createWheel()
{
    scene->addItem(new wheel());
    scene->addItem(new spokes(1));
    scene->addItem(new spokes(2));
}

void spokes::advance(int phase /*, int time=QDateTime::currentMSecsSinceEpoch()*/)
{
    if (phase&&da) {
        QGraphicsItem::setTransformOriginPoint(500,300);
        setRotation(QDateTime::currentMSecsSinceEpoch()/10);

    }
}

wheel::wheel():QGraphicsEllipseItem()
{
    setRect(350,150,300,300);
}

spokes::spokes(int i):QGraphicsLineItem(){
    if(i == 1)
    {
        setLine(500,150,500,450);
    }
    else
    {
        setLine(350,300,650,300);
    }

}
void MainWindow::on_pushButton_clicked()
{
    da= !da;
}
