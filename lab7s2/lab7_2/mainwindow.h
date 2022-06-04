#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qstack.h"
#include "cmath"
#include <QDebug>
#include <QList>
#include <QString>
#include <QMessageBox>


template<typename Key, typename Value>
class unordered_map
{
    int capacity;
    QList<QPair<Key,Value>> *table;
public:
    unordered_map(int size)
    {
        this->capacity = size;
        table = new QList<QPair<Key,Value>>[capacity];
    }

    QString to_string()
    {
        QString text = "";
        for(int i = 0; i<capacity;i++)
        {
            text+=QString::number(i)+"-ый элемент:\n";
            if(!table[i].empty())
            {
                for(int g = 0; g<table[i].size();g++)
                {
                    text+="\t"+table[i][g].first+":"+table[i][g].second+"\n";
                }
            }
            else
            {
                text+="\t...\n";
            }
        }
        return text;
    }

    void insertItem(Key key, Value data)
    {
        qDebug()<< key << " " << data;
        int index = hshFunc(trFunc(key));

        qDebug()<<trFunc(key) << " " << capacity << " " << table;
        table[index].append(QPair<Key,Value>(key,data));
        if(table[index].size()>6)
            rehash(capacity+5);
    }

    long long hshFunc(long long key)
    {
        return key%capacity;
    }

    void clearItem(Key key)
    {
        if(contain(key))
        {
            for(int i = 0; i<table[hshFunc(trFunc(key))].size();i++)
            {
                if(key==table[hshFunc(trFunc(key))][i].first)
                    table[hshFunc(trFunc(key))].erase(table[hshFunc(trFunc(key))].begin()+i);
            }
        }
    }

    void rehash(size_t newsize)
    {
        QList<QPair<Key,Value>> *ntable = new QList<QPair<Key,Value>>[newsize];
        size_t oldcap = capacity;
        capacity = newsize;

        for(int i = 0; i<oldcap;i++)
        {
            for(int g = 0; g<table[i].size();g++)
            {
                ntable[hshFunc(trFunc(table[i][g].first))].append(table[i][g]);
                if(ntable[hshFunc(trFunc(table[i][g].first))].size()>6)
                {
                    capacity = oldcap;
                    delete[]ntable;
                    rehash(newsize+5);
                }
            }
        }
        delete table;
        table = ntable;
    }

    long long trFunc(Key key){
        long long tmp = 0;
        for(int i = 0; i<key.length();i++)
        {
            tmp+=abs(key[i].digitValue())*i;
        }
        return tmp;
    }

    bool contain(Key key)
    {
        for(int i = 0; i<table[hshFunc(trFunc(key))].size();i++)
        {
            qDebug()<<key<<" " << table[hshFunc(trFunc(key))][i].first;
            if(key==table[hshFunc(trFunc(key))][i].first)
                return true;
        }
        return false;
    }

    QPair<Key,Value> operator[](Key key)
    {
        if(contain(key))
        {
            for(int i = 0; i<table[hshFunc(trFunc(key))].size();i++)
            {
                qDebug()<<key<<" " << table[hshFunc(trFunc(key))][i].first;
                if(key==table[hshFunc(trFunc(key))][i].first)
                    return table[hshFunc(trFunc(key))][i];
            }
        }
        else
        {
            Value val();
            insert(key,val);
            return QPair<Key,Value>(key,val);
        }
    }

    ~unordered_map(){
        delete[] table;
    }
};

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_do_2_clicked();

    void on_do_4_clicked();

    void on_do_3_clicked();

    void rewrite();

    void on_do_5_clicked();

private:
    Ui::MainWindow *ui;
    unordered_map<QString,QString>* map;

};
#endif // MAINWINDOW_H
