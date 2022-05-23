#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

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
        qDebug()<<" A " <<bool(sh_pt.get_count());
        Ptr = sh_pt.get();

        count = sh_pt.get_count();
        (*count)++;

    };

    T operator[](int a)
    {
        return Ptr[a];
    }

    Shared_ptr<T>& operator= (Shared_ptr<T>& sh_pt)
    {
        if(this->Ptr!=sh_pt.get())
        {
            clear();

            Ptr = sh_pt.get();
            count = sh_pt.get_count();
            (*count)++;
        }
        return *this;
    };

    Shared_ptr<T> operator*()
    {
        return *Ptr;
    };

    T* get()
    {
        return Ptr;
    }

    unsigned* get_count()
    {
        return count;
    }

    void clear()
    {
        if (*count > 0)
            --(*count);
        else if (*count == 0)
        {
            delete Ptr;
            delete count;
        }

    }

    bool is_unique()
    {
        return (*count==1);
    }

    void set_count(unsigned* a)
    {
        delete[] count;
        count = a;
    }

    ~Shared_ptr()
    {
        clear();
    };

private:
    T* Ptr = nullptr;
    unsigned* count = nullptr;
};


template <typename T>

class Weak_ptr
{
public:
    Weak_ptr ()
    {
        Ptr = nullptr;
        count_w = new unsigned(0);
        count_s = new unsigned(0);
    }

    Weak_ptr (Weak_ptr<T>& sh_pt)
    {
        Ptr = sh_pt.Ptr;
        count_w = sh_pt.count_w;
        count_s = sh_pt.count_s;
        (*count_w)++;
    };

    Weak_ptr (Shared_ptr<T>& sh_pt)
    {
        Ptr = sh_pt.get();
        count_s = sh_pt.get_count();
        qDebug()<<bool(count_s);
        count_w = new unsigned(1);
    };


    Weak_ptr<T>& operator= (Weak_ptr<T>& sh_pt)
    {
        if(this!=&sh_pt)
        {
            clear();
            Ptr = sh_pt.Ptr;
            count_w = sh_pt.get_wcount();
            count_s = sh_pt.get_scount();
            ++(*count_w);
        }
        return *this;
    };

    T* operator->() const noexcept;

    unsigned* get_scount()
    {
        return count_s;
    }

    unsigned* get_wcount()
    {
        return count_w;
    }

    void clear()
    {
        if (*count_w > 0)
            --(*count_w);
        else if (*count_w == 0)
        {
            delete Ptr;
            delete count_w;
            if(*count_s == 0)
            {
                delete count_s;
            }
        }

    }

    Shared_ptr<T>& lock()
    {
        Shared_ptr<T>* ptr = new Shared_ptr<T>(Ptr);
        ptr->set_count(count_s);
        return *ptr;
    }

    ~Weak_ptr()
    {
        clear();
    };

private:
    T* Ptr;
    unsigned* count_w;
    unsigned* count_s;
};


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void table_rewrite();

    Shared_ptr<int>* a = new Shared_ptr<int>[10];
    Weak_ptr<int>* b = new Weak_ptr<int>[10];

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
