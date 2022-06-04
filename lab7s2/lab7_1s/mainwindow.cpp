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
    mset->root = new SETNode<QString>(new QString("ad"));
    mset->root ->Print();
    qDebug()<<1;
    //connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(on_pushButton_clicked()));
    SETNode<QString>* a = new SETNode<QString>(new QString("Da"));
    SETNode<QString>* b = new SETNode<QString>(new QString("Gagry"));
    mset->add(a);
    //DrawTree();
    mset->add(new SETNode<QString>(new QString("Da,da")));
    //DrawTree();
    mset->add(b);
    //DrawTree();
    mset->add(new SETNode<QString>(new QString("dadadada")));

    mset->add(new SETNode<QString>(new QString("NNe")));

    //DrawTree();
    mset->add(new SETNode<QString>(new QString("NeN")));

    mset->add(new SETNode<QString>(new QString("NeNe")));
    DrawTree();
    mset->root->UpdateDistance(mset->root,0);
    //DrawTree();
    mset->root->TraverseInorder(mset->root);
    //tree->UpdateDistance(tree,0);

    //DrawTree();

    mset->root->TraversePreorder(mset->root,0);

    int y = 10;
    Set<QString>::iterator e(mset->end());
    qDebug()<<"run";
    while(e!=mset->begin()&&y)
    {
        e.get().Print();
        e.prev();
        y--;
    }
    e.get().Print();

}

void MainWindow::DrawTree(){
    mset->root->UpdateDistance(mset->root,0);
    UpdateTreeHeight(mset->root);
    a.clear();
    for(int i = 0; i<=mset->root->getHeight();i++)
        a.append("");

    qDebug()<<mset->root->getHeight();
    for(int h = mset->root->getHeight(); h>=0;h--)
    {
        for(int i = 0; i<(4*pow(2,h)-1)/2-1;i++)
            a[mset->root->getHeight()-h]+="_";
    }

    drawNode(mset->root);
}

void MainWindow::UpdateTreeHeight(SETNode<QString>* root)
{
    if (root->left_child)
        UpdateTreeHeight(root->left_child);

    if (root->right_child)
        UpdateTreeHeight(root->right_child);

    root->UpdateHeight();
}

void MainWindow::drawNode(SETNode<QString>* root)
{

    if (root->left_child)
        drawNode(root->left_child);

    QComboBox* b = new QComboBox(this);
    b->addItem(root->getData());
    if(root->parent)
    {
        b->addItem(root->parent->getData() + "par");
    }

    b->addItem(QString::number(root->getHeight())+" height");
    b->addItem(QString::number(root->dist)+" dist");
    if(root->right_child)
    {
        b->addItem("Right");
        b->addItem(root->right_child->getData());
    }
    if(!root->left_child||!root->right_child)
    {
        for(int i = 0; i<(4*pow(2,a.size()-root->dist-1-2))-2;i++)
            a[root->dist+1]+="_";
    }

    if(root->left_child)
    {
        b->addItem("Left");
        b->addItem(root->left_child->getData());
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
    mset->root->Print();
    if(!mset->root->SearchNode(ui->lineEdit->text()))
    {
        mset->add(new SETNode<QString>(new QString(ui->lineEdit->text())));
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
    mset->pop(ui->lineEdit->text());
    while(!c.empty())
    {
        c.back()->deleteLater();
        c.pop_back();
    }

    DrawTree();
}
