#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <array>

using namespace std;

template <typename T>

class Shared_ptr
{
public:
    Shared_ptr ()
    {
        Ptr = nullptr;
        count = new unsigned(0);
    }

    Shared_ptr(T* ptr)
    {
        Ptr = ptr;
        count = new unsigned(1);

    };
    Shared_ptr (Shared_ptr<T>& sh_pt)
    {
        clear();
        Ptr = sh_pt.Ptr;
        count = sh_pt.count;
        (*count)++;
    };

    Shared_ptr<T>& operator= (Shared_ptr<T>& sh_pt)
    {
        if(Ptr!=sh_pt.get())
        {
            clear();

            Ptr = sh_pt.Ptr;
            count = sh_pt.count;
            (*count)++;
        }
        return *this;
    };

    T operator[](int a)
    {
        return Ptr[a];
    }

    Shared_ptr<T>& operator*()
    {
        return *Ptr;
    };

    T* get()
    {
        return Ptr;
    }

    unsigned get_count()
    {
        return *count;
    }

    void clear()
    {
        if (*count > 0)
            --(*count);
        else
        {
            delete Ptr;
            delete count;
        }
    }

    bool is_unique()
    {
        return (*count==1);
    }

    ~Shared_ptr()
    {
        clear();
    };

private:
    T* Ptr;
    unsigned* count  = nullptr;
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

    void table_rewrite();

    Shared_ptr<int>* a = new Shared_ptr<int>[10];

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H



