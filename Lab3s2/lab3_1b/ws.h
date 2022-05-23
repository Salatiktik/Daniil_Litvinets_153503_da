#ifndef WS_H
#define WS_H

#include <QDialog>

namespace Ui {
class ws;
}

class ws : public QDialog
{
    Q_OBJECT

public:
    explicit ws(QWidget *parent = nullptr);
    ~ws();

    QString wsR();
    Ui::ws *ui;
};

#endif // WS_H
