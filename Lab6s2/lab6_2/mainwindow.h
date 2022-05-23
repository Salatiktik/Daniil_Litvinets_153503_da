#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qstack.h"
#include "cmath"
#include <QDebug>
#include "qstring.h"
#include <QTextStream>

class hash
{
    int capacity;
    int randq;
    QStack<int> *table;
public:

    hash(int size)
    {
        randq = rand() % 10+1;
        int _size = getPrime(size + randq);
        this->capacity = _size;
        table = new QStack<int>[capacity];
    }

    void insertItem(long long key, int data)
    {
        qDebug()<< key << " " << data;
        int index = hashFunction(data,key);
        table[index].push(data);
    }

    QString findMaxKey()
    {
        QString str;
        int max_i = 0;
        int max_j = 0;
        for(int i = capacity - 1; i >= 0; --i){
            if(!table[i].isEmpty()){
                for(int j = 0; j < table[i].size(); ++j){
                    if(table[max_i][max_j]<table[i][j])
                    {
                        max_i = i;
                        max_j = j;
                    }
                }
            }
        }
        str = "max key ="+QString::number(max_i);

        return str;
    }

    bool checkPrime(int n) {
        if (n == 1 || n == 0) {
            return 0;
        }
        for (int i = 2; i < sqrt(n) + 1; i++) {
            if (n % i == 0) {
                return 0;
            }
        }
        return true;
    }

    int getPrime(int n) {
        if (n % 2 == 0) {
            n++;
        }
        while (!checkPrime(n)) {
            n += 2;
        }
        return n;
    }

    int hashFunction(int data, int key) {
        qDebug()<<"a" << (key) << data;
        int def = abs(key)%abs(data);

        return (abs(def)%capacity);
    }

    QString displayHash()
    {
        QString text;
        QTextStream ans(&text);
        for (int i = 0; i < capacity; i++) {
            ans <<"table[" << i << "]";
            if (!table[i].isEmpty()) {
                ans << " -->";
                for(int j = 0; j < table[i].size(); ++j){
                    ans << ' ' << table[i][j];
                }
            }
            ans << '\n';
        }
        return text;
    }

    ~hash(){
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

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
