#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <memory>
#include <QString>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class bitset
{
    size_t size_;
    size_t bsize;
    size_t* bits;

public:

    bitset(unsigned long long s, unsigned long long a = 0)
    {
        size_ = s;
        if(double(size_)/(sizeof(size_t)*8)==size_/(sizeof(size_t)*8))
        {
            bits = new size_t[size_/(sizeof(size_t)*8)];
            bsize = size_/(sizeof(size_t)*8);
        }
        else
        {
            bsize = size_/(sizeof(size_t)*8)+1;
            bits = new size_t[size_/(sizeof(size_t)*8)+1];
        }

        reset();
        size_t tmp = 0;

        qDebug()<<bsize;
        for(int i = 0; i<bsize;i++)
        {
            tmp =a>>(sizeof(size_t)*8)*(bsize-i-1);
            qDebug()<<tmp;
            bits[i]=tmp;
            qDebug()<<"tmp" << tmp;
            a-=tmp<<(sizeof(size_t)*8)*(bsize-i-1);
        }
    }

    bool all()
    {
        bool ch = true;
        for(int i = 0; i<size_-((bsize-1)*sizeof(size_t)*8);i++)
        {
            ch*=(bits[0]>>i)%2;
            qDebug()<<ch << i;
        }

        for(size_t i = 1; i<bsize;i++)
        {
            ch*=bool(SIZE_MAX==bits[i]);
        }

        return ch;
    }

    bool any()
    {
        for(size_t i = 0; i<bsize;i++)
        {
            if(bits[i]!=0)
                return 1;
        }
        return 0;
    }

    void flip()
    {
        for(size_t i = 0; i<bsize;i++)
        {
            bits[i]^=SIZE_MAX;
        }
    }

    bool none()
    {
        return !any();
    }

    void reset()
    {
        qDebug()<<bsize;
        for(size_t i = 0; i<bsize;i++)
        {
            bits[i]=0;
        }
    }

    void reset(size_t pos)
    {
        if(test(pos))
        {
            bits[bsize-int(pos/(sizeof(size_t)*8))-1]-=pow(2,pos%(sizeof(size_t)*8)-1);
        }
    }

    void set()
    {
        for(size_t i = 0; i<bsize;i++)
        {
            bits[i]=SIZE_MAX;
        }
    }

    void set(size_t pos)
    {
        qDebug()<<pos;
        if(!test(pos))
        {
            qDebug()<<pow(2,(pos-1)%(sizeof(size_t)*8)) << "lll";
            bits[bsize-int(pos/(sizeof(size_t)*8))-1]+=pow(2,(pos-1)%(sizeof(size_t)*8));
        }
    }

    size_t size()
    {
        return size_;
    }

    bool test(size_t pos)
    {
        qDebug()<<pos;
        qDebug()<<bsize-pos/(sizeof(size_t)*8) << "asd";
        size_t tmp = bits[bsize-pos/(sizeof(size_t)*8)-1];
        qDebug()<<tmp;
        return (tmp>>(pos%(sizeof(size_t)*8)-1))%2;
    }

    QString to_string()
    {
        QString tmp = "";

        for(int g = size_-(bsize-1)*(sizeof(size_t)*8); g>0;g--)
        {

            tmp+=char((bits[0]>>(g-1))%2+48);
        }

        for(int i = 1; i<bsize;i++)
        {
            for(int g = sizeof(size_t)*8; g>0;g--)
            {
                tmp+=char((bits[i]>>(g-1))%2+48);
            }
        }
        return tmp;
    }

    bitset operator &=(bitset a)
    {
        for(int i = 0; i<bsize;i++)
        {
            bits[i]&=a.bits[i];
        }
    }

    bitset operator |=(bitset a)
    {
        for(int i = 0; i<bsize;i++)
        {
            bits[i]|=a.bits[i];
        }
    }

    bitset operator ^=(bitset a)
    {
        for(int i = 0; i<bsize;i++)
        {
            bits[i]^=a.bits[i];
        }
    }

    unsigned long to_ulong()
    {
        unsigned long tmp = 0;
        for(int g = size_-(bsize-1)*(sizeof(size_t)*8); g>0;g--)
        {
            qDebug()<<g<<(bits[bsize-1]>>g)%2<<tmp;
            if((bits[0]>>(g-1))%2)
                tmp+=pow(2,g-1);
            qDebug()<<"t" << tmp;
        }
        qDebug()<<tmp;
        for(int i = 1; i<bsize;i++)
        {
            for(int g = sizeof(size_t)*8; g>0;g--)
            {
                if((bits[i]>>(g-1))%2)
                    tmp+=pow(2,g-1);
            }
        }

        qDebug()<<tmp;
        return tmp;
    }

    unsigned long long ullong()
    {
        unsigned long long tmp = 0;
        for(int g = size_-(bsize-1)*(sizeof(size_t)*8); g>0;g--)
        {
            if((bits[0]>>g)%2)
                tmp+=pow(2,g-1);
        }
        for(int i = 0; i<bsize-1;i++)
        {
            for(int g = sizeof(size_t)*8; g>0;g--)
            {
                if((bits[i]>>g)%2)
                    tmp+=pow(2,g-1);
            }
        }

        return tmp;
    }

    bool checkOverflowUl()
    {
        if(size_>32)
        {
            qDebug()<<"over" << bsize;
            for(int i = 0;i<bsize-1;i++)
            {
                qDebug()<<i << bits[i];
                if(bits[i]!=0)
                    return 1;
            }
        }
        return 0;
    }

    bool checkOverflowUll()
    {
        if(size_>64)
        {
            for(int i = bsize;i>=5;i++)
            {
                if(bits[i]!=0)
                    return 1;
            }
        }
        return 0;
    }

    bool count()
    {
        size_t ch = 0;
        for(int i = 0; i<bsize;i++)
        {
            for(int g = (sizeof(size_t)*8); g>0;g--)
            {
                ch+=(bits[i]>>g)%2;
            }
        }
        return ch;
    }

};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

    void rewrite();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
