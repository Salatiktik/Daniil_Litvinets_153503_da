#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QGridLayout>
#include <QLabel>
#include <QFile>
#include <QFileDialog>

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
    int lastId()
    {
        node* tmp = head;
        for(int i = 0; i<count-1;i++)
        {
            tmp = tmp->prev;
        }
        return tmp->value;

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
    void error(int var,int y, int i);
    void checkFile();
    void loadtext();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    List<int>* symbols = new List<int>();
    List<int>* id = new List<int>();
    List<int>* str = new List<int>();
    QString text;
};
#endif // MAINWINDOW_H
