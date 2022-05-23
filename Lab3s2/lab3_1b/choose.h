#ifndef CHOOSE_H
#define CHOOSE_H

#include <QDialog>

namespace Ui {
class choose;
}

class choose : public QDialog
{
    Q_OBJECT

public:
    explicit choose(QWidget *parent = nullptr);
    ~choose();
    void setRange(int x);
    int returnValue();
    void setTitle(QString a);

    Ui::choose *ui;
};

#endif // CHOOSE_H
