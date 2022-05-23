#ifndef INPUT_H
#define INPUT_H

#include <QDialog>
#include <mainwindow.h>

namespace Ui {
class input;
}

class input : public QDialog
{
    Q_OBJECT

public:
    explicit input(QWidget *parent = nullptr);
    ~input();

public slots:
    QString code();
    QString city();
    QString person1();
    QString person2();
    QString date();
    QString time();
    double rate();
    void codeSet(QString a);
    void citySet(QString a);
    void person1Set(QString a);
    void person2Set(QString a);
    void dateSet(QString a);
    void timeSet(QString a);
    void rateSet(double a);
private:
    Ui::input *ui;
};

#endif // INPUT_H
