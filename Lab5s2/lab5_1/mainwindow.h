#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


template<typename T>
class queue
{
private:
    T* qarr;
    size_t count;
    size_t capacity;
public:
    queue(){
        qarr = new T[2];
        count = 0;
        capacity = 2;
    }
    ~queue()
    {
        delete[]qarr;
    }

    T& front()
    {
        return qarr[0];
    }

    T& back()
    {
        return qarr[count-1];
    }

    void push(T a)
    {
        if(capacity<1)
            resize(count*2);
        for(int i = count; i>0;i--)
        {
            qarr[i]=qarr[i-1];
        }
        qarr[0]=a;
        count++;
        capacity--;
    }

    void resize(size_t newSize)
    {
        T* qarr_t = new T[newSize];
        for(int i = 0; i<count;i++)
        {
            qarr_t[i]=qarr[i];
        }
        capacity=newSize;
        delete qarr;
        qarr = qarr_t;
    }

    void pop()
    {
        if(count!=0)
        {
            capacity++;
            count--;
        }
        else
        {
            delete[] qarr;
            qarr = nullptr;
        }
    }

    void operator=(queue<T> a)
    {
        delete[]qarr;
        qarr = a.qarr;
        count = a.count;
        capacity = a.capacity;
    }

    void clear()
    {
        capacity += count;
        count = 0;
    }
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    queue<int> randInt = queue<int>();
    queue<int> tmp = queue<int>();
};
#endif // MAINWINDOW_H
