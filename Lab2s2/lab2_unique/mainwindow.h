#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

template <typename T>

class Unique_ptr
{
public:
    Unique_ptr ()
    {
        Ptr = nullptr;
    }

    Unique_ptr (T* ptr)
    {
        Ptr = ptr;
    };
    Unique_ptr (Unique_ptr<T>& sh_pt)
    {

        Ptr = sh_pt.Ptr;
        sh_pt.Ptr = nullptr;
    };

    Unique_ptr<T>& operator= (Unique_ptr<T>& sh_pt)
    {
        if(this!=&sh_pt)
        {
            Ptr = sh_pt.Ptr;
            sh_pt.Ptr = nullptr;
        }
        return *this;
    };

    T operator[](int a)
    {
        return Ptr[a];
    }

    Unique_ptr<T>& operator*()
    {
        return *Ptr;
    };

    T* get()
    {
        return Ptr;
    }

    ~Unique_ptr()
    {
        delete Ptr;
    };

private:
    T* Ptr;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void table_rewrite();

    Unique_ptr<int>* a = new Unique_ptr<int>[10];

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_5_clicked();
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
