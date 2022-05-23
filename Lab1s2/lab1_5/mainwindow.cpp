#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <string>

struct Expression
{
    virtual double evaluate() const = 0;
    virtual ~Expression(){};
};

struct Number : Expression
{
    Number(double value):value(value){};
    double evaluate() const override{return value;};
private:
    double value;
};

struct BinaryOperation : Expression
{
    BinaryOperation(Expression const * left, char op, Expression const * right){
        this->left = left;
        this->right=right;
        this->op = op;
    };
    double evaluate() const override{
        switch(this->op)
        {
        case '+':
            return this->left->evaluate()+this->right->evaluate();
            break;
        case'-':
            return this->left->evaluate()-this->right->evaluate();
            break;
        case '*':
            return this->left->evaluate()*this->right->evaluate();
            break;
        case '/':
            return this->left->evaluate()/this->right->evaluate();
            break;
        default:
            return 0;
            break;
        }
    };
    ~BinaryOperation(){
        delete left;
        delete right;
    };
private:
    Expression const* left;
    Expression const* right;
    char op;
};

bool check(Expression* f, Expression* i)
{
    std::string kk("1324350");

    size_t* a = nullptr;
    size_t* b = nullptr;

    memcpy(&a,&kk,sizeof(size_t**));
    memcpy(&b,i,sizeof(size_t**));

    return a==b;

}

class base{
public:
    void method(){qDebug()<<"b";};
};

class child : public base
{
public:
    void method(){qDebug()<<"a";};
};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Expression* sub = new BinaryOperation(new Number(4),'+',new Number(5));
    Expression* dor = new BinaryOperation(new Number(2),'*',sub);
    Expression* re = new Number(2);
    Expression* tu = new Number(0);
    Expression* rw = new BinaryOperation(new Number(7),'*',new Number(6));
    Expression* tuk = new BinaryOperation(new BinaryOperation(new Number(7),'*',new Number(6)),'*',new BinaryOperation(new Number(7),'*',new Number(6)));




    qDebug()<<check(rw,tuk);

    base* a = new child;
    a->method();
    delete dor;
}

MainWindow::~MainWindow()
{
    delete ui;
}

