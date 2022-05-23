#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{

    QApplication c(argc, argv);
    MainWindow w;
    w.show();
    return c.exec();
}

