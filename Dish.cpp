#include "Dish.h"

Dish::Dish(int id, string name, double price, string category)
    : id(id), name(name), price(price), category(category) {}

int Dish::getId() const { return id; }
string Dish::getName() const { return name; }
double Dish::getPrice() const { return price; }
string Dish::getCategory() const { return category; }