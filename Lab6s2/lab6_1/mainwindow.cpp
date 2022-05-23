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
    tree = new AVLNode(new Unit("ad",67));
    tree ->Print();
    qDebug()<<1;
    //connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(on_pushButton_clicked()));
    AVLNode* a = new AVLNode(new Unit("Da",400));
    AVLNode* b = new AVLNode(new Unit("Pizda",223));
    tree = tree->AddNode(a);
    //DrawTree();
    tree = tree->AddNode(new AVLNode(new Unit("Da,da",3123)));
    //DrawTree();
    tree = tree->AddNode(b);
    //DrawTree();
    tree = tree ->AddNode(new AVLNode(new Unit("dadadada",1)));

    tree = tree->AddNode(new AVLNode(new Unit("NNe",3300)));

    //DrawTree();
    tree = tree->AddNode(new AVLNode(new Unit("NeN",3400)));

    tree = tree->AddNode(new AVLNode(new Unit("NeNe",33)));
    DrawTree();
    tree->UpdateDistance(tree,0);
    //DrawTree();
    tree->TraverseInorder(tree);
    //tree->UpdateDistance(tree,0);

    //DrawTree();


}

void MainWindow::DrawTree(){
    tree->UpdateDistance(tree,0);
    UpdateTreeHeight(tree);
    a.clear();
    for(int i = 0; i<=tree->getHeight();i++)
        a.append("");

    qDebug()<<tree->getHeight();
    for(int h = tree->getHeight(); h>=0;h--)
    {
        for(int i = 0; i<(4*pow(2,h)-1)/2-1;i++)
            a[tree->getHeight()-h]+="_";
    }

    drawNode(tree);
}

void MainWindow::UpdateTreeHeight(AVLNode* root)
{
    if (root->left_child)
        UpdateTreeHeight(root->left_child);

    if (root->right_child)
        UpdateTreeHeight(root->right_child);

    root->UpdateHeight();
}

void MainWindow::drawNode(AVLNode* root)
{

    if (root->left_child)
        drawNode(root->left_child);

    QComboBox* b = new QComboBox(this);
    b->addItem(QString::number(root->getData().num));
    b->addItem(root->getData().person);
    b->addItem(QString::number(root->getHeight())+" height");
    if(root->right_child)
    {
        b->addItem("Right");
        b->addItem(QString::number(root->right_child->getData().num));
    }
    if(root->left_child&&!root->right_child)
    {
        for(int i = 0; i<=(4*pow(2,a.size()-root->dist-1-2))+1;i++)
            a[root->dist+1]+="_";
    }

    if(root->left_child)
    {
        b->addItem("Left");
        b->addItem(QString::number(root->left_child->getData().num));
    }
    if(!root->left_child&&root->right_child)
    {
        for(int i = 0; i<=(4*pow(2,a.size()-root->dist-1-2))+1;i++)
            a[root->dist+1]+="_";
    }

    b->setGeometry(a[root->dist].length()*13,50*(root->dist),52,50);

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
    tree->Print();
    if(!tree->SearchNode(ui->spinBox->value()))
    {
        qDebug()<<1;
        tree = tree ->AddNode(new AVLNode(new Unit(ui->lineEdit->text(),ui->spinBox->value())));
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
    AVLNode::task(tree);

    while(!c.empty())
    {
        c.back()->deleteLater();
        c.pop_back();
    }

    DrawTree();
}

void MainWindow::on_pushButton_3_clicked()
{
    tree->DeleteNode(tree,Unit("",ui->spinBox->value()));
    while(!c.empty())
    {
        c.back()->deleteLater();
        c.pop_back();
    }

    DrawTree();
}
