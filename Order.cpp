#include "Order.h"
#include <iostream>
#include <iomanip>
#include <ctime>
#include <limits>

using namespace std;

string Order::generateOrderId() {
    time_t now = time(0);
    tm* ltm = localtime(&now);
    return to_string(1900 + ltm->tm_year) +
           to_string(1 + ltm->tm_mon) +
           to_string(ltm->tm_mday) +
           to_string(ltm->tm_hour) +
           to_string(ltm->tm_min) +
           to_string(ltm->tm_sec);
}

Order::Order() : totalPrice(0.0) {
    orderId = generateOrderId();
}

void Order::addDish(Menu& menu, int dishId) {
    Dish* dish = menu.findDishById(dishId);
    if (dish != nullptr) {
        orderStack.push(*dish);
        totalPrice += dish->getPrice();
        cout << "Successfully added: " << dish->getName() << endl;
    } else {
        cout << "Invalid dish ID! Please try again." << endl;
    }
}

void Order::removeDish() {
    if (orderStack.isEmpty()) {
        cout << "\nYour order is empty! Nothing to remove." << endl;
        return;
    }

    cout << "\n===== Your Selected Dishes =====" << endl;
    orderStack.displayStack();

    int choice;
    cout << "Enter the number of the dish you want to remove: ";
    while (!(cin >> choice)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input! Please enter a number: ";
    }

    Dish removedDish(0, "", 0.0, "");
    if (orderStack.removeByPosition(choice, removedDish)) {
        totalPrice -= removedDish.getPrice();
        cout << "Removed: " << removedDish.getName() << endl;
    } else {
        cout << "Invalid selection! Please try again." << endl;
    }
}

void Order::displayOrder() const {
    if (orderStack.isEmpty()) {
        cout << "\nYour order is empty." << endl;
        return;
    }

    cout << "\n===== Order Details =====" << endl;
    cout << "Order ID: " << orderId << endl;
    cout << "Selected Dishes: " << endl;
    StackNode* temp = orderStack.getTop();
    while (temp) {
        cout << "- " << temp->dish.getName() << " - $" << fixed << setprecision(2) << temp->dish.getPrice() << endl;
        temp = temp->next;
    }
    cout << "---------------------------------" << endl;
    cout << "Total Price: $" << fixed << setprecision(2) << totalPrice << endl;
    cout << resetiosflags(ios::fixed) << setprecision(6);
}

bool Order::isEmpty() const {
    return orderStack.isEmpty();
}