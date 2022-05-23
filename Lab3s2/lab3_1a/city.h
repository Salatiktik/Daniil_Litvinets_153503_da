#ifndef CITY_H
#define CITY_H

#include <QDialog>

namespace Ui {
class city;
}

class city : public QDialog
{
    Q_OBJECT

public:
    explicit city(QWidget *parent = nullptr);
    ~city();
    QString returnCity();

private:
    Ui::city *ui;
};

#endif // CITY_H
