#include "Menu.h"
#include "Order.h"
#include <iostream>
#include <limits>

using namespace std;

int main() {
    Menu restaurantMenu;
    restaurantMenu.initDefaultMenu();
    Order customerOrder;

    int option;
    do {
        cout << "\n===== abdulwahid restaurant ordering sys =====" << endl;
        cout << "1. Browse Menu" << endl;
        cout << "2. Add Dish to Order" << endl;
        cout << "3. Remove Dish from Order" << endl;
        cout << "4. View Order" << endl;
        cout << "5. Place Order & Exit" << endl;
        cout << "Enter your option: ";
        
        while (!(cin >> option)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a number between 1-5: ";
        }
        switch (option) {
            case 1:
                restaurantMenu.displayMenu();
                break;
                
            case 2: {
                int dishId;
                cout << "\nEnter the ID of the dish you want to add: ";
                while (!(cin >> dishId)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input! Please enter a valid dish ID (number): ";
                }
                customerOrder.addDish(restaurantMenu, dishId);
                break;
            }
            case 3:
                customerOrder.removeDish();
                break;
            case 4:
                customerOrder.displayOrder();
                break;
            case 5:
                if (customerOrder.isEmpty()) {
                    cout << "\nCannot place empty order! Exiting..." << endl;
                } else {
                    customerOrder.displayOrder();
                    cout << "\nOrder placed successfully! Thank you for your purchase." << endl;
                }
                system("cls");
                break;
                
            default:
                cout << "Invalid option! Please enter a number between 1-5." << endl;
        }
        
    } while (option != 5);

    return 0;
}