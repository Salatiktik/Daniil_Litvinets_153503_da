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
    QString ws();
    QString title();
    int num();
    void wsSet(QString a);
    void titleSet(QString a);
    void numSet(int a);
private:
    Ui::input *ui;
};

#endif // INPUT_H
