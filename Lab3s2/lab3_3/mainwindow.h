#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

template<typename T>
class List
{
private:
    struct node;
    node* head;
    int count;
public:
    List<T>(){
        head = nullptr;
        count = 0;
    }

    int getCount()
    {
        return count;
    }

    void pop()
    {
        node* tmp = head->prev;
        delete head;
        head = tmp;
        count--;
    }

    void add(T value)
    {
        if(count == 0)
        {
            node* tmp = new node;
            tmp->value = value;
            head = tmp;
        }
        else
        {
            node* tmp = new node;
            tmp->value = value;
            tmp->prev = head;
            head = tmp;
        }
        count++;
    }
    T headValue()
    {
        return head->value;
    }

    bool checkBrack()
    {
        node* tmp = head;
        for(int i = 0; i<count;i++)
        {
            if(tmp->value=='(')
                return true;
        }
    }
};

template<typename T>
struct List<T>::node
{
    T value;
    node *prev;
};


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void inToPost();
    void solution(QStringList mass);

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    List<char>* signs = new List<char>();
    List<double>* num = new List<double>();
    QString post;
    QString in;
};
#endif // MAINWINDOW_H
