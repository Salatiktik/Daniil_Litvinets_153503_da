#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <iostream>
#include <fstream>
#include <Windows.h>
#include <io.h>
#include <stdio.h>
#include <input.h>
#include <choose.h>
#include <workshop.h>

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
    int head;
    int tail;
    int count;
    node** mass = new node* [1];
public:
    List(){
        head = 0;
        tail = 0;
        count = 0;
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
        node* tmp = mass[head];
        for(int i = 0; i< pos; i++)
        {
            tmp = mass[tmp->next];
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
        pos-=1;
        node * Del = mass[head];

        for(int i = 0; i< pos;i++)
        {
           Del = mass[Del->next];
        }


        node* PrevDel = nullptr;
        node* AfterDel = nullptr;
        if(Del->id!=head)
        {
            qDebug()<<"not head";
            PrevDel = mass[Del->prev];
        }

        if(Del->id!=tail)
        {
            qDebug()<<"not tail";
            AfterDel = mass[Del->next];
        }

        qDebug()<<Del->id<<"d" <<tail << " " <<head << " " << count << " " << pos;
        if(count != 1&& PrevDel&&pos!=count-1)
            PrevDel->next = AfterDel->id;
        if(count != 1&&AfterDel&&pos!=0)
            AfterDel->prev = PrevDel->id;

        if(pos == 0)
        {
            head = Del->next;
            mass[head]=AfterDel;
        }
        if(pos == count-1)
        {
            tail = PrevDel->id;
            mass[tail]=PrevDel;
        }

        delete Del;
        count--;
        node** mass_t = new node* [count];
        mass_t[0]=mass[head];
        mass_t[0]->id=0;
        mass_t[0]->next = 1;
        node* tmp = mass[mass[head]->next];
        qDebug()<<mass_t[0]->next;
        for(int i = 1; i<count-1;i++)
        {
            qDebug()<<999;
            mass_t[i]=new node();
            mass_t[i]->value=mass[tmp->id]->value;
            mass_t[i]->prev = i-1;
            mass_t[i]->id=i;
            mass_t[i]->next=i+1;
            qDebug()<<mass_t[i]->prev << " a " << mass_t[i]->next;
            tmp=mass[tmp->next];
        }
        qDebug()<<" a " << count-1;
        head = 0;
        tail = count;
        mass_t[count-1]=new node();
        mass_t[count-1]->value=tmp->value;
        mass_t[count-1]->id=count-1;
        mass_t[count-1]->prev=count-2;
        delete[] mass;
        mass = mass_t;
    }

    void addTail(T* data)
    {
        node * temp = new node;
        temp->value = data;
        temp->prev = tail;

        if(count==0)
        {
            temp->id=0;
            head=tail=0;
            mass[0]=temp;
            count++;
            return;
        }
        node** mass_t = new node* [count+1];
        node* tmp = mass[head];
        for(int i = 0; i<count-1;i++)
        {
            qDebug()<<tmp->id << "id" << 666;
            mass_t[tmp->id]=mass[tmp->id];
            tmp=mass[tmp->next];
            qDebug()<<tmp->id;
        }

        tmp->next=count;
        mass_t[tmp->id]=mass[tmp->id];
        delete[] mass;
        mass = mass_t;

        mass[count]=temp;
        temp->value = data;
        temp->id = count;
        tail=count;
        count++;

    }
    void addHead(T* data)
    {
        node * temp = new node;
        temp->value = data;
        temp->next = head;
        temp->prev = 0;
        if(count==0)
        {
            temp->id=0;
            head=tail=0;
            mass[0]=temp;
            count++;
            return;
        }

        node** mass_t = new node* [count+1];
        node* tmp = mass[head];
        tmp->prev=count;
        for(int i = 0; i<count;i++)
        {
            mass_t[tmp->id]=mass[tmp->id];
            tmp=mass[tmp->next];
        }
        delete[] mass;
        mass = mass_t;
        count++;
        mass[count-1]=temp;
        temp->value = data;
        temp->id = count;
    }
};

template<typename T>
struct List<T>::node
{
    T* value;
    int id;
    int prev;
    int next;
};

class Unit{
public:
    struct prod{
        QString wsCode;
        QString prTitle;
        int num;
    };
    Unit();
    Unit(QString wsCode, QString title, int num)
    {
        prod_u->wsCode = wsCode;
        prod_u->prTitle = title;
        prod_u->num = num;
    }

    prod* prod_u = new prod;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void error(QString a = "Проверьте данные и попробуйте снова!");
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

private:
    Ui::MainWindow *ui;
    List<Unit>* products = new List<Unit>();
};
#endif // MAINWINDOW_H
