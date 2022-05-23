#include "restaurant.h"

Food::Food(QString lable, QString category, double price)
{
    this->label=lable;
    this->category=category;
    this->price=price;
}

double Order::orderPrice()
{
    return this->dish.price*this->dishes_num;
}

Order::Order(int table, QString id, Food dish, int dishes_num)
{
    this->table = table;
    this->id = id;
    this->dish = Food(dish);
    this->dishes_num = dishes_num;
}
