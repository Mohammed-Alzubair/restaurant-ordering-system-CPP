#ifndef ORDER_H
#define ORDER_H

#include "Menu.h"
#include <string>
#include <ctime>
#include <limits>

using namespace std;

class Order {
private:
    string orderId;
    Stack orderStack;
    double totalPrice;

    string generateOrderId();

public:
    Order();
    void addDish(Menu& menu, int dishId);
    void removeDish();
    void displayOrder() const;
    bool isEmpty() const;
};

#endif