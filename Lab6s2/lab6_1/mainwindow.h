#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDebug>
#include <QMainWindow>
#include <QComboBox>

class Unit
{
public:
    long long num;
    QString person;
    Unit(QString name, long long n)
    {
        person = name;
        num = n;
    }

    void Print()
    {
        qDebug()<< person << " id:" << num;
    }

    Unit operator=(Unit a)
    {
        this->num = a.num;
        this->person = a.person;
    }

    bool operator <(Unit& a)
    {
        return this->num < a.num;
    }

    bool operator >(Unit& a)
    {
        return this->num > a.num;
    }

    bool operator ==(Unit& a)
    {
        return this->num==a.num;
    }
};


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
class AVLNode {
private:
    Unit* un;
    long long height;

public:
    long long dist;
    AVLNode* left_child = nullptr;
    AVLNode* right_child = nullptr;

    AVLNode(Unit* a){
        this->un= new Unit(a->person,a->num);
        height=0;
        dist = 0;
    };

    AVLNode(AVLNode* a)
    {
        this->un= new Unit(a->un->person,a->un->num);
        height=a->height;
        dist = a->dist;
        left_child = a->left_child;
        right_child = a->right_child;
    }

    void Print()
    {
        un->Print();
    }

    long long getHeight()
    {
        return height;
    }

    AVLNode& operator=(AVLNode& a)
    {
        this->un = a.un;
        this->left_child = a.left_child;
        this->right_child = a.right_child;
        dist = a.dist;
        height = a.height;
        return *this;
    }

    AVLNode* AddNode(AVLNode* node)
    {
        if(node->un->num < this->un->num){
            if(!this->left_child)
            {
                this->left_child = node;
            }
            else
            {
                this->left_child = this->left_child->AddNode(node);
            }
        } else {
            if (!this->right_child)
            {
                this->right_child = node;
            }
            else
            {
                this->right_child = this->right_child->AddNode(node);
            }
        }

        return this->Balance();
    }

    AVLNode* SearchNode(long long a)
    {
        if (this->un->num == a)
            return this;

        if (this->un->num > a)
            if (this->left_child)
                return this->left_child->SearchNode(a);
            else
                return nullptr;
        else
            if(this->right_child)
                return this->right_child->SearchNode(a);
            else
                return nullptr;
    }

    static AVLNode* DeleteNode(AVLNode* root, Unit unD)
    {
        if(!root)
            return root;

        if(unD < *(root->un))
            root->left_child = DeleteNode(root->left_child, unD);
        else if (unD > *(root->un))
            root->right_child = DeleteNode(root->right_child, unD);
        else if (!root->left_child && !root->right_child){
            delete root;
            root = nullptr;
        }
        else if (!root->left_child) {
            AVLNode* temp = root;
            root = root->right_child;
            delete temp;
        }
        else if (!root->right_child) {
            AVLNode* temp = root;
            root = root->left_child;
            delete temp;
        }
        else {
            AVLNode* temp = root->right_child;

            while (temp->left_child)
              temp = temp->left_child;

            root->un = temp->un;
            root->right_child = DeleteNode( root->right_child, *(temp->un));
        }

        return root;
    }

    int GetBFactor()
    {
        long long hleft = -1, hright = -1;
        if(left_child)
            hleft = left_child->height;
        if(right_child)
            hright = right_child->height;

        return hright - hleft;
    }

    void UpdateHeight()
    {
        long long hleft = -1, hright = -1;
        if(this->left_child)
            hleft = this->left_child->height;
        if(this->right_child)
            hright = this->right_child->height;

        this->height = std::max(hleft,hright)+1;
    }

    void UpdateDistance(AVLNode* root, int dist)
    {
        root->dist = dist;
        dist++;

        if(root->left_child)
            UpdateDistance(root->left_child,dist);


        if(root->right_child)
            UpdateDistance(root->right_child,dist);

    }

    AVLNode* RotateRight()
    {
        qDebug()<<"right";
        this->Print();
        AVLNode* right = this;
        AVLNode* left = right->left_child;
        right->left_child = left->right_child;
        left->right_child = right;

        right->UpdateHeight();
        left->UpdateHeight();

        this->Print();
        return left;
    }

    AVLNode* RotateLeft(){
        qDebug()<<"left";
        this->Print();
        AVLNode* left = this;
        AVLNode* right = left->right_child;
        left->right_child = right->left_child;
        right->left_child = left;

        left->UpdateHeight();
        right->UpdateHeight();

        right->Print();
        if(right->right_child)
            right->right_child->Print();


        if(right->left_child)
            right->left_child->Print();
        this->Print();
        return right;
    }

    AVLNode* Balance(){
        this->UpdateHeight();
        this->Print();
        if(GetBFactor() == 2) {
          if(this->right_child->GetBFactor() < 0)
            this->right_child = this->right_child->RotateRight();
          qDebug()<<"l1";
          return this->RotateLeft();
        }
        if(GetBFactor() == -2) {
          if(this->left_child->GetBFactor() > 0){
              qDebug()<<"l2";
            this->left_child = this->left_child->RotateLeft();
          }
          return this->RotateRight();
        }
        return this;
    }

    void TraversePreorder(AVLNode* root){
        root->Balance();

        if (root->left_child)
            TraversePreorder(root->left_child);

        if (root->right_child)
            TraversePreorder(root->right_child);
    }

    void TraverseInorder(AVLNode* root){
        if (root->left_child)
            TraverseInorder(root->left_child);

        /*qDebug()<<"===========";
        root->Print();
        qDebug()<<"\nleft\n";
        if(root->left_child)
        root->left_child->Print();
        qDebug()<<"\nright\n";
        if(root->right_child)
        root->right_child->Print();*/
        root->Print();

        if (root->right_child)
            TraverseInorder(root->right_child);
    }

    void TraversePostorder(AVLNode* root){
        if (root->left_child)
            TraversePostorder(root->left_child);

        if (root->right_child)
            TraversePostorder(root->right_child);

        root->UpdateHeight();
    }

    Unit getData()
    {
        return *un;
    }

    AVLNode* operator = (AVLNode* a)
    {
        this->right_child = a->right_child;
        this->left_child = a->left_child;
        this->un = a->un;
        this->UpdateHeight();
        return this;
    }

    void static task(AVLNode* tree)
    {
        AVLNode* min = tree;
        AVLNode* max = tree;
        while(min->left_child)
            min=min->left_child;
        while(max->right_child)
            max=max->right_child;

        QString tmp = min->un->person;
        min->un->person = max->un->person;
        max->un->person = tmp;
    }
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    static void addNodeChr(Unit un,int x, int y);

private slots:
    void DrawTree();
    void drawNode(AVLNode* root);
    void UpdateTreeHeight(AVLNode* a);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    AVLNode* tree;
    //node* tree2;
};
#endif // MAINWINDOW_H
