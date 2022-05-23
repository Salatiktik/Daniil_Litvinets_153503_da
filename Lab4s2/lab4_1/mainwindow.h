#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


template <class T1, class T2>
struct pair
{
    T1 first;
    T2 second;
    pair();

    pair(pair<T1, T2>& right)
    {
        first = right.first;
        second = right.second;
    };
    
    pair(T1& Val1, T2& Val2)
    {
        first = Val1;
        second = Val2;
    }

    pair& operator=(pair& p)
    {
        this->first = p.first;
        this->second = p.second;
    };    
    
    bool operator == (pair& p)
    {
        return(p.first==this->first&&p.second==this->second);
    }
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
