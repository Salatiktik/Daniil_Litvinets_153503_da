#ifndef NUMBER_H
#define NUMBER_H

#include <QDialog>

namespace Ui {
class number;
}

class number : public QDialog
{
    Q_OBJECT

public:
    explicit number(QWidget *parent = nullptr);
    ~number();
    QString getNum();

private:
    Ui::number *ui;
};

#endif // NUMBER_H
