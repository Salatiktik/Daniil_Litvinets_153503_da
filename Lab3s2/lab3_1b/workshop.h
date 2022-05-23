#ifndef WORKSHOP_H
#define WORKSHOP_H

#include <QDialog>

namespace Ui {
class workshop;
}

class workshop : public QDialog
{
    Q_OBJECT

public:
    explicit workshop(QWidget *parent = nullptr);
    ~workshop();

    QString returnWs();

    Ui::workshop *ui;
};

#endif // WORKSHOP_H
