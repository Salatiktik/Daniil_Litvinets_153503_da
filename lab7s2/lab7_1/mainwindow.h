#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDebug>
#include<QPair>
#include <QMainWindow>
#include <QComboBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

template <typename T1, typename T2>
class MAPNode {
private:
    QPair<T1, T2>* un;
    long long height;

public:
    long long dist;
    MAPNode* left_child = nullptr;
    MAPNode* right_child = nullptr;
    MAPNode* parent = nullptr;

    MAPNode(QPair<T1, T2>* a){
        this->un= a;
        height=0;
        dist = 0;
    };

    MAPNode(){}

    MAPNode(MAPNode* a)
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
        qDebug()<<un->first<<" " << un->second;
    }

    long long getHeight()
    {
        return height;
    }

    MAPNode& operator=(MAPNode& a)
    {
        parent = a.parent;
        this->un = a.un;
        this->left_child = a.left_child;
        this->right_child = a.right_child;
        dist = a.dist;
        height = a.height;
        return *this;
    }

    MAPNode* AddNode(MAPNode* node)
    {
        if(node->un->first < this->un->first){
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

    MAPNode* SearchNode(T1 a)
    {
        if (this->un->first == a)
            return this;

        if (this->un->first > a)
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

    static MAPNode* DeleteNode(MAPNode* root, T1 unD)
    {
        if(!root)
            return root;

        if(unD < root->un->first)
            root->left_child = DeleteNode(root->left_child, unD);
        else if (unD > root->un->first)
            root->right_child = DeleteNode(root->right_child, unD);
        else if (!root->left_child && !root->right_child){
            delete root;
            root = nullptr;
        }
        else if (!root->left_child) {
            MAPNode* temp = root;
            root = root->right_child;
            delete temp;
        }
        else if (!root->right_child) {
            MAPNode* temp = root;
            root = root->left_child;
            delete temp;
        }
        else {
            MAPNode* temp = root->right_child;

            while (temp->left_child)
              temp = temp->left_child;

            root->un = temp->un;
            root->right_child = DeleteNode( root->right_child, temp->un->first);
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

    void UpdateDistance(MAPNode* root, int dist)
    {
        root->dist = dist;
        dist++;

        if(root->left_child)
            UpdateDistance(root->left_child,dist);


        if(root->right_child)
            UpdateDistance(root->right_child,dist);

    }

    MAPNode* RotateRight()
    {
        qDebug()<<"right";
        this->Print();
        MAPNode* right = this;
        MAPNode* left = right->left_child;
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

    MAPNode* RotateLeft(){
        qDebug()<<"left";
        this->Print();
        MAPNode* left = this;
        MAPNode* right = left->right_child;

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

    MAPNode* Balance(){
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

    void TraversePreorder(MAPNode* root, MAPNode* parent){

        qDebug()<<1;
        if(parent)
            parent->Print();
        root->parent = parent;

        if (root->left_child)
            TraversePreorder(root->left_child,root);

        if (root->right_child)
            TraversePreorder(root->right_child,root);
    }

    void TraverseInorder(MAPNode* root){
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

    void TraversePostorder(MAPNode* root){
        if (root->left_child)
            TraversePostorder(root->left_child);

        if (root->right_child)
            TraversePostorder(root->right_child);

        root->UpdateHeight();
    }

    QPair<T1, T2>* getData()
    {
        return un;
    }

    MAPNode* operator = (MAPNode* a)
    {
        parent = a->parent;
        this->right_child = a->right_child;
        this->left_child = a->left_child;
        this->un = a->un;
        this->UpdateHeight();
        return this;
    }

    void static task(MAPNode* tree)
    {
        MAPNode* min = tree;
        MAPNode* max = tree;
        while(min->left_child)
            min=min->left_child;
        while(max->right_child)
            max=max->right_child;

        QString tmp = min->un->person;
        min->un->person = max->un->person;
        max->un->person = tmp;
    }
};

template <typename T1, typename T2>
class Map{
public:
    class iterator{
        MAPNode<T1,T2> t;
        T1 prevKey;
    public:
        iterator(MAPNode<T1,T2> t1)
        {
            t = t1;
        }

        bool operator!=(iterator b)
        {
            return t.getData()->first!=b.t.getData()->first;
        }


        bool operator==(iterator b)
        {
            return t.getData()->first==b->t.getData()->first;
        }

        void next()
        {
            if(t.right_child&&t.right_child->getData()->first!=prevKey)
            {
                prevKey=t.getData()->first;
                t=t.right_child;
                while(t.left_child)
                {
                    t=t.left_child;
                }
            }
            else
            {
                prevKey=t.getData()->first;
                t=t.parent;
                if(t.right_child)
                {
                    if(t.getData()->first<prevKey)
                    {
                        t=t.parent;
                    }
                }
            }
        }

        void prev()
        {
            if(t.left_child&&t.left_child->getData()->first!=prevKey)
            {
                prevKey=t.getData()->first;
                t=t.left_child;
                while(t.right_child)
                {
                    t=t.right_child;
                }
            }
            else
            {
                prevKey=t.getData()->first;
                t=t.parent;
                if(t.left_child)
                {
                    if(t.getData()->first>prevKey)
                    {
                        prevKey=t.getData()->first;
                        t=t.parent;
                    }
                }
            }
        }

        void operator=(MAPNode<T1,T2>& a)
        {
            t = a;
        }

        MAPNode<T1,T2> get()
        {
            return t;
        }
    };

    MAPNode<T1,T2>* root;

    void add(MAPNode<T1,T2>* a)
    {
        root = root->AddNode(a);
    }

    void pop(T1 a)
    {
        root = root->DeleteNode(root, a);
    }

    iterator begin()
    {
        MAPNode<T1,T2> a = root;
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
        MAPNode<T1,T2> a = root;
        while(a.right_child)
        {
            a = a.right_child;
        }

        iterator b(a);
        return b;
    }

    QPair<T1,T2>* operator[](T1 key)
    {
        if(root->search(key))
        {
            return search(key);
        }
        else
        {
            root->AddNode(key,T2());
            return search(key);
        }
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
    void drawNode(MAPNode<QString,QString>* root);
    void UpdateTreeHeight(MAPNode<QString,QString>* a);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    Map<QString,QString>* mmap;
    //node* tree2;
};
#endif // MAINWINDOW_H
