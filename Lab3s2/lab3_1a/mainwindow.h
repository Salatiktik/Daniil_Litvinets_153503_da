
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <iostream>
#include <fstream>
#include <Windows.h>
#include <io.h>
#include <stdio.h>
#include <input.h>
#include <choose.h>
#include <number.h>
#include <city.h>

#include <QMainWindow>
#include <string>

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
    node* tail;
    int count;
public:
    List(){
        head = nullptr;
        tail = nullptr;
        count = 0;
    }
    List(List& list){
        head = nullptr;
        tail = nullptr;
        count = 0;

        node* tmp =list.head;

        while(tmp!=0)
        {
            addTail(tmp->value);
            tmp = tmp->next;
        }
    }
    ~List(){
        delAll();
    }

    int getCount()
    {
        return count;
    }
    node* getNode(int pos)
    {
        node* tmp =head;
        for(int i = 0; i< pos; i++)
        {
            tmp = tmp->next;
        }
        return tmp;
    }
    void delAll()
    {
        while(count!=0)
            del(1);
    }
    void del(int pos)
    {
        node* Del = head;

        for(int i = 1; i< pos;i++)
        {
           Del = Del->next;
        }

        node * PrevDel = Del->prev;
        node * AfterDel = Del->next;

        if(PrevDel != 0 && count != 1)
           PrevDel->next = AfterDel;
         if(AfterDel != 0 && count != 1)
           AfterDel->prev = PrevDel;

        if(pos == 1)
            head = AfterDel;
        if(pos == count)
            tail = PrevDel;

        delete Del;

        count--;
    }

    void insert(int pos, T* data)
    {
        if(pos == count + 1)
        {
           addTail(data);
           return;
        }
        else if(pos == 1)
        {
           addHead(data);
           return;
        }

        node * Ins = head;

        for(int i = 1; i< pos;i++)
        {
           Ins = Ins->next;
        }

        node * PrevIns = Ins->prev;
        node * temp = new node;

        temp->value = data;

        if(PrevIns != 0 && count != 1)
           PrevIns->next = temp;

        temp->next = Ins;
        temp->prev = PrevIns;
        Ins->prev = temp;

        count++;
    }
    void addTail(T* data)
    {
        node * temp = new node;
        temp->next = 0;
        temp->value = data;

        temp->prev = tail;

        if(tail != 0)
           tail->next = temp;

        if(count == 0)
           head = tail = temp;
        else
            tail = temp;

        count++;
    }
    void addHead(T* data)
    {
        node * temp = new node;

        temp->prev = 0;
        temp->value = data;
        temp->next = head;

        if(head != 0)
           head->prev = temp;

        if(count == 0)
           head = tail = temp;
        else
           head = temp;

        count++;
    }
    void sort(int start, int end)
    {
        int s = start, e = end;
        double med = this->getNode((s+e)/2)->value->call_u->rate;
        do
        {
            while(this->getNode(s)->value->call_u->rate<med)s++;
            while(this->getNode(e)->value->call_u->rate>med)e--;
            if(s<=e)
            {
                qDebug()<<this->getNode(e)->value->call_u->city.name<<" "<<this->getNode(s)->value->call_u->city.name;
                swap(this->getNode(e),this->getNode(s));
                e--;s++;
            }
        }while(s<=e);
        if(s<end)this->sort(s,end);
        if(e>start)this->sort(start,e);
    }

    void swap(node* a, node* b)
    {
            T* tmp = a->value;
            a->value = b->value;
            b->value = tmp;
    }
};

template<typename T>
struct List<T>::node
{
    T* value;
    node *prev = nullptr;
    node *next = nullptr;
};

class Unit{
public:
    struct city_str{
        QString code;
        QString name;
    };
    struct call{
        QString date;
        QString time;
        city_str city;
        double rate;
        QString person1;
        QString person2;
    };
    Unit();
    Unit(QString code, QString name, QString date, QString time, double rate, QString person1, QString person2)
    {
        call_u->date = date;
        call_u->time = time;
        call_u->person1 = person1;
        call_u->person2 = person2;
        call_u->rate=rate;
        call_u->city.code = code;
        call_u->city.name = name;
    }

    call* call_u = new call;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool date_in(std::string h);
    bool time_in(std::string h);
    void error();
    void tableLoad();
    void tableRewtire();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_10_clicked();

    bool checkFile(QString a);

    void on_pushButton_6_clicked();

    void on_pushButton_8_clicked();

private:
    Ui::MainWindow *ui;
    List<Unit>* calls = new List<Unit>();
};
#endif // MAINWINDOW_H
