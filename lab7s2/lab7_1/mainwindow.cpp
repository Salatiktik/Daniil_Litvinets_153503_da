#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTreeView>
#include <QObject>
#include <QPushButton>
QStringList a;
QList<QComboBox*> c;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mmap->root = new MAPNode<QString,QString>(new QPair<QString,QString>("ad","67"));
    mmap->root ->Print();
    qDebug()<<1;
    //connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(on_pushButton_clicked()));
    MAPNode<QString,QString>* a = new MAPNode<QString,QString>(new QPair<QString,QString>("Da","400"));
    MAPNode<QString,QString>* b = new MAPNode<QString,QString>(new QPair<QString,QString>("Gagry","223"));
    mmap->add(a);
    //DrawTree();
    mmap->add(new MAPNode<QString,QString>(new QPair<QString,QString>("Da,da","3123")));
    //DrawTree();
    mmap->add(b);
    //DrawTree();
    mmap->add(new MAPNode<QString,QString>(new QPair<QString,QString>("dadadada","1")));

    mmap->add(new MAPNode<QString,QString>(new QPair<QString,QString>("NNe","3300")));

    //DrawTree();
    mmap->add(new MAPNode<QString,QString>(new QPair<QString,QString>("NeN","3400")));

    mmap->add(new MAPNode<QString,QString>(new QPair<QString,QString>("NeNe","33")));
    qDebug()<<"poiufdvbjkloiuytf";
    DrawTree();
    mmap->root->UpdateDistance(mmap->root,0);
    //DrawTree();

    //tree->UpdateDistance(tree,0);

    //DrawTree();
}

void MainWindow::DrawTree(){
    mmap->root->UpdateDistance(mmap->root,0);
    UpdateTreeHeight(mmap->root);
    a.clear();
    for(int i = 0; i<=mmap->root->getHeight();i++)
        a.append("");

    qDebug()<<mmap->root->getHeight();
    for(int h = mmap->root->getHeight(); h>=0;h--)
    {
        for(int i = 0; i<(4*pow(2,h)-1)/2-1;i++)
            a[mmap->root->getHeight()-h]+="_";
    }

    drawNode(mmap->root);
}

void MainWindow::UpdateTreeHeight(MAPNode<QString,QString>* root)
{
    if (root->left_child)
        UpdateTreeHeight(root->left_child);

    if (root->right_child)
        UpdateTreeHeight(root->right_child);

    root->UpdateHeight();
}

void MainWindow::drawNode(MAPNode<QString,QString>* root)
{

    if (root->left_child)
        drawNode(root->left_child);

    QComboBox* b = new QComboBox(this);
    b->addItem(root->getData()->first);
    b->addItem(root->getData()->second);
    if(root->parent)
    {
        b->addItem(root->parent->getData()->first + "par");
    }

    b->addItem(QString::number(root->getHeight())+" height");
    b->addItem(QString::number(root->dist)+" dist");
    if(root->right_child)
    {
        b->addItem("Right");
        b->addItem(root->right_child->getData()->first);
    }
    if(!root->left_child)
    {
        qDebug()<<"no left";
        for(int g = 0; g<a.size()-root->dist-1;g++)
        {

            for(int i = 0; i<(4*pow(2,a.size()-root->dist+g-1-2))-2;i++)
                a[root->dist+1+g]+="_";
        }
    }

    if(!root->right_child)
    {
        qDebug()<<"no right";
        for(int g = 0; g<a.size()-root->dist-1;g++)
        {
            qDebug()<<g;
            for(int i = 0; i<(4*pow(2,a.size()-root->dist+g-1-2))-2;i++)
                a[root->dist+1+g]+="_";
        }
    }

    if(root->left_child)
    {
        b->addItem("Left");
        b->addItem(root->left_child->getData()->first);
    }

    b->setGeometry(a[root->dist].length()*15,50*(root->dist),60,50);

    for(int i = 0; i<=(4*pow(2,a.size()-root->dist-1)-1);i++)
        a[root->dist]+="_";

    b->show();
    c.append(b);


    if (root->right_child)
        drawNode(root->right_child);
    if(!root->right_child&&root->left_child)
    {
        for(int i = 0; i<=(4*pow(2,a.size()-root->dist-1-2))+1;i++)
            a[root->dist+1]+="_";
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    qDebug()<<"lol";
    mmap->root->Print();
    if(!mmap->root->SearchNode(ui->lineEdit->text()))
    {
        mmap->add(new MAPNode<QString,QString>(new QPair<QString,QString>(ui->lineEdit->text(),ui->lineEdit_2->text())));
    }
    while(!c.empty())
    {
        c.back()->deleteLater();
        c.pop_back();
    }

    DrawTree();

}

void MainWindow::on_pushButton_2_clicked()
{
    mmap->pop(ui->lineEdit->text());
    while(!c.empty())
    {
        c.back()->deleteLater();
        c.pop_back();
    }

    DrawTree();
}
