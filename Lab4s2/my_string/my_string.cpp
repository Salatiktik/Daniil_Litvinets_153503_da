#include "my_string.h"

#include <iostream>
#include <QDebug>

int main()
{
    mstring s1("hoh");
    char* sis = strtok("hoh","o");
    qDebug()<<sis;
}
