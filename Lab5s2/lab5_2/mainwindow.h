#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QMessageBox>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

template<typename T>
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

template<typename T>
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

    T* operator+(int a)
    {
        return Ptr+a;
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

    static Shared_ptr<T>& makeShared(T* a)
    {
        Shared_ptr<T>* b = new Shared_ptr<T>(a);
        return *b;
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
template<typename T>
class deque
{
public:
    class raiterator
    {
    private:
        Shared_ptr<T>* blocks;
        size_t bcount = 0;
        size_t range = 0;

        size_t bpos = 0;
        size_t epos = 0;

        size_t bblock = 0;
        size_t eblock = 0;


        Shared_ptr<T> b;
        Shared_ptr<T> e;

    public:
        raiterator(){}

        void resize(int newSize,int k)
        {
            Shared_ptr<T>* newblocks = new Shared_ptr<T>[newSize/k];
            if(bcount!=0)
            {
                size_t block = bblock;
                bblock = 0;
                for(int i = 0; i<bcount;i++)
                {
                    qDebug()<<block << " block at " << blocks[block].get() << " i = " << i;
                    newblocks[i]=blocks[block];
                    if(block<bcount-1)
                        block++;
                    else
                        block = 0;
                }

                eblock = bcount-1;
                for(int i = bcount; i<newSize/k;i++)
                {
                    newblocks[i] = Shared_ptr<T>::makeShared(new T[k]);
                }
            }
            else
            {
                bblock = 0;
                eblock = 0;
                for(int i = bcount; i<newSize/k;i++)
                {
                    newblocks[i] = Shared_ptr<T>::makeShared(new T[k]);
                }

                e=newblocks[0];
                b=newblocks[0];

            }
            bcount = newSize/k;
            range = k;

            blocks = newblocks;

            for(int i = 0; i<bcount; i++)
            {
                 qDebug()<<i << " block at " << blocks[i].get() << " i = " << i;

            }
            qDebug()<< bblock << " " <<eblock;
        }
        void clear()
        {
            bcount = 0;
        }

        bool binc()
        {
            qDebug()<<"position " << bpos << "range" << range ;
            qDebug()<<"block " << bblock << " ad " << blocks[bblock].get() <<" " <<bcount-1;
           if(bpos==range-1)
           {
               qDebug()<<"jump";
               if(bblock!=(bcount-1))
                   bblock++;
               else
                   bblock=0;
                qDebug()<<bblock;
               b=blocks[bblock];
               bpos=0;
           }
           else
           {
               bpos++;
           }
           return 0;
        }

        bool bdec()
        {
            size_t tmpb = bblock;
            if(bpos>0)
                bpos--;
            else
            {
                if(bblock!=0)
                    bblock--;
                else
                    bblock=bcount-1;

                if(bblock!=eblock&&bpos<=epos)
                {
                    b = blocks[bblock];
                    bpos=range-1;
                    qDebug()<<"god";
                }
                else
                {
                    qDebug()<<"resize";
                    bblock = tmpb;
                    return 1;
                }
            }
            return 0;
        }

        bool edec()
        {
            if(epos==0)
            {
                if(eblock!=0)
                    eblock--;
                else
                    eblock=bcount-1;
                e=blocks[eblock];
                epos=range-1;
            }
            else
            {
                epos--;
            }
            return 0;
        }

        bool einc()
        {
            size_t tmpb = eblock;
            if(epos<range-1)
                epos++;
            else
            {
                if(eblock!=bcount-1)
                    eblock++;
                else
                    eblock=0;

                if(bblock!=eblock&&bpos<epos)
                {
                    e = blocks[eblock];
                    epos=0;
                }
                else
                {
                    eblock = tmpb;
                    return 1;
                }
            }
            return 0;
        }

        T* begin()
        {
            qDebug()<<"block ad" << b.get();
            return b+bpos;
        }

        T* end()
        {
            return e+epos;
        }

    };

    deque(int k1 = 5)
    {
        k = k1;
        count = 0;
        resize(k);
    }
    void push_back(T a)
    {
        *(iter.end()) = a;
        if(iter.einc())
        {
            resize(capacity*2);
            iter.einc();
        }
        count++;
    }

    void push_front(T a)
    {
        *(iter.begin()) = a;
        if(iter.bdec())
        {
            qDebug()<<"resize";
            resize(capacity*2);
            iter.bdec();
        }
        count++;
    }

    T pop_back()
    {
        if(count){
            iter.edec();
            count--;
        }
        return *(iter.end());
    }

    T pop_front()
    {
        if(count)
        {
            iter.binc();
            count--;
        }
        return *(iter.begin());
    }

    void resize(size_t newSize)
    {
        capacity = newSize;
        iter.resize(newSize,k);
    }

    bool empty()
    {
        return count==0;
    }

    size_t size()
    {
        return count;
    }

    void clear()
    {
        count = 0;
        iter.clear();
        resize(5);
    }

private:

    size_t capacity;
    size_t count;
    size_t k;

    raiterator iter;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::MainWindow *ui;
    deque<int> deq;
};
#endif // MAINWINDOW_H
