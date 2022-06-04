#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDebug>
#include<QPair>
#include <QMainWindow>
#include <QComboBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

template <typename T1>
class SETNode {
private:
    T1 un;
    long long height;

public:
    long long dist;
    SETNode* left_child = nullptr;
    SETNode* right_child = nullptr;
    SETNode* parent = nullptr;

    SETNode(T1* a){
        this->un= *a;
        height=0;
        dist = 0;
    };

    SETNode(){}

    SETNode(SETNode* a)
    {
        this->un= a->un;
        height=a->height;
        dist = a->dist;
        left_child = a->left_child;
        right_child = a->right_child;
        parent = a->parent;
    }

    void Print()
    {
        qDebug()<<un;
    }

    long long getHeight()
    {
        return height;
    }

    SETNode& operator=(SETNode& a)
    {
        parent = a.parent;
        this->un = a.un;
        this->left_child = a.left_child;
        this->right_child = a.right_child;
        dist = a.dist;
        height = a.height;
        return *this;
    }

    SETNode* AddNode(SETNode* node)
    {
        if(node->un < this->un){
            if(!this->left_child)
            {
                this->left_child = node;
                this->left_child->parent = this;
            }
            else
            {
                this->left_child = this->left_child->AddNode(node);
            }
        } else {
            if (!this->right_child)
            {
                this->right_child = node;
                this->right_child->parent = this;
            }
            else
            {
                this->right_child = this->right_child->AddNode(node);
            }
        }

        return this->Balance();
    }

    SETNode* SearchNode(T1 a)
    {
        if (this->un == a)
            return this;

        if (this->un > a)
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

    static SETNode* DeleteNode(SETNode* root, T1 unD)
    {
        if(!root)
            return root;

        if(unD < root->un)
            root->left_child = DeleteNode(root->left_child, unD);
        else if (unD > root->un)
            root->right_child = DeleteNode(root->right_child, unD);
        else if (!root->left_child && !root->right_child){
            delete root;
            root = nullptr;
        }
        else if (!root->left_child) {
            SETNode* temp = root;
            root = root->right_child;
            delete temp;
        }
        else if (!root->right_child) {
            SETNode* temp = root;
            root = root->left_child;
            delete temp;
        }
        else {
            SETNode* temp = root->right_child;

            while (temp->left_child)
              temp = temp->left_child;

            root->un = temp->un;
            root->right_child = DeleteNode( root->right_child, temp->un);
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

    void UpdateDistance(SETNode* root, int dist)
    {
        root->dist = dist;
        dist++;

        if(root->left_child)
            UpdateDistance(root->left_child,dist);


        if(root->right_child)
            UpdateDistance(root->right_child,dist);

    }

    SETNode* RotateRight()
    {
        qDebug()<<"right";
        this->Print();
        SETNode* right = this;
        SETNode* left = right->left_child;
        right->left_child = left->right_child;
        if(right->left_child)
        {
            right->left_child->parent=right;
        }
        left->right_child = right;

        left->parent = right->parent;
        right->parent = left;

        right->UpdateHeight();
        left->UpdateHeight();

        this->Print();
        return left;
    }

    SETNode* RotateLeft(){
        qDebug()<<"left";
        this->Print();
        SETNode* left = this;
        SETNode* right = left->right_child;

        right->parent = left->parent;
        left->parent = right;

        left->right_child = right->left_child;
        if(left->right_child)
        {
            left->right_child->parent = left;
        }
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

    SETNode* Balance(){
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

    void TraversePreorder(SETNode* root, SETNode* parent){

        qDebug()<<1;
        if(parent)
            parent->Print();
        root->parent = parent;

        if (root->left_child)
            TraversePreorder(root->left_child,root);

        if (root->right_child)
            TraversePreorder(root->right_child,root);
    }

    void TraverseInorder(SETNode* root){
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

    void TraversePostorder(SETNode* root){
        if (root->left_child)
            TraversePostorder(root->left_child);

        if (root->right_child)
            TraversePostorder(root->right_child);

        root->UpdateHeight();
    }

    T1 getData()
    {
        return un;
    }

    SETNode* operator = (SETNode* a)
    {
        if(a->parent)
            this->parent = a->parent;
        this->right_child = a->right_child;
        this->left_child = a->left_child;
        this->un = a->un;
        this->UpdateHeight();
        return this;
    }

    void static task(SETNode* tree)
    {
        SETNode* min = tree;
        SETNode* max = tree;
        while(min->left_child)
            min=min->left_child;
        while(max->right_child)
            max=max->right_child;

        QString tmp = min->un->person;
        min->un->person = max->un->person;
        max->un->person = tmp;
    }
};

template <typename T1>
class Set{
public:
    class iterator{
        SETNode<T1> t;
        T1 prevKey;
    public:
        iterator(SETNode<T1> t1)
        {
            t = t1;
        }

        bool operator!=(iterator b)
        {
            return t.getData()!=b.t.getData();
        }


        bool operator==(iterator b)
        {
            return t.getData()==b->t.getData();
        }

        void next()
        {
            if(t.right_child&&t.right_child->getData()!=prevKey)
            {
                prevKey=t.getData();
                t=t.right_child;
                while(t.left_child)
                {
                    t=t.left_child;
                }
            }
            else
            {
                prevKey=t.getData();
                t=t.parent;
                if(t.right_child)
                {
                    if(t.getData()<prevKey)
                    {
                        t=t.parent;
                    }
                }
            }
        }

        void prev()
        {
            if(t.left_child&&t.left_child->getData()!=prevKey)
            {
                prevKey=t.getData();
                t=t.left_child;
                while(t.right_child)
                {
                    t=t.right_child;
                }
            }
            else
            {
                prevKey=t.getData();
                t=t.parent;
                if(t.left_child)
                {
                    if(t.getData()>prevKey)
                    {
                        prevKey=t.getData();
                        t=t.parent;
                    }
                }
            }
        }

        void operator=(SETNode<T1>& a)
        {
            t = a;
        }

        SETNode<T1> get()
        {
            return t;
        }
    };

    SETNode<T1>* root;

    void add(SETNode<T1>* a)
    {
        root = root->AddNode(a);
    }

    void pop(T1 a)
    {
        root = root->DeleteNode(root, a);
    }

    iterator begin()
    {
        SETNode<T1> a = root;
        while(a.left_child)
        {

            a = a.left_child;
        }
        qDebug()<<a.left_child;
        iterator b(a);
        return b;
    }


    iterator end()
    {
        SETNode<T1> a = root;
        while(a.right_child)
        {
            a = a.right_child;
        }

        iterator b(a);
        return b;
    }


};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void DrawTree();
    void drawNode(SETNode<QString>* root);
    void UpdateTreeHeight(SETNode<QString>* a);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    Set<QString>* mset;
    //node* tree2;
};
#endif // MAINWINDOW_H
