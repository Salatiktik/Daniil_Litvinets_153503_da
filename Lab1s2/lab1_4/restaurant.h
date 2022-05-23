#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <QString>
class Food
{
public:
    Food(QString lable = "name", QString category = "category", double price = 0.01);
    QString label;
    QString category;
    double price;
};


class Order
{
public:
    Order(int table = 1, QString id = 0, Food dish = Food(), int dishes_num = 0);
    int table;
    QString id;
    Food dish;
    int dishes_num;
    double orderPrice();
};
#endif // RESTAURANT_H
