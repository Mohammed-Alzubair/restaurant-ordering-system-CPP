#ifndef DISH_H
#define DISH_H

#include <string>

using namespace std;

class Dish {
private:
    int id;
    string name;
    double price;
    string category;
public:
    Dish(int id, string name, double price, string category);

    int getId() const;
    string getName() const;
    double getPrice() const;
    string getCategory() const;
};

#endif