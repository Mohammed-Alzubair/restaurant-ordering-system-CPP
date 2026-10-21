#include "Menu.h"
#include <iostream>
#include <iomanip>

using namespace std;

// 链表节点构造函数
Node::Node(const Dish& d) : dish(d), next(nullptr) {}

// 链表类实现
LinkedList::LinkedList() : head(nullptr) {}

void LinkedList::add(const Dish& d) {
    Node* newNode = new Node(d);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
}

Node* LinkedList::findById(int id) {
    Node* temp = head;
    while (temp) {
        if (temp->dish.getId() == id) {
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}

void LinkedList::display() const {
    cout << "\n===== Restaurant Menu =====" << endl;
    cout << left << setw(8) << "ID" 
         << setw(20) << "Name" 
         << setw(10) << "Price" 
         << setw(15) << "Category" << endl;
    cout << "---------------------------------------------" << endl;
    Node* temp = head;
    while (temp) {
        cout << left << setw(8) << temp->dish.getId()
             << setw(20) << temp->dish.getName()
             << setw(10) << fixed << setprecision(2) << temp->dish.getPrice()
             << setw(15) << temp->dish.getCategory() << endl;
        temp = temp->next;
    }
}

// 栈节点构造函数
StackNode::StackNode(const Dish& d) : dish(d), next(nullptr) {}

// 栈类实现
Stack::Stack() : topNode(nullptr) {}

void Stack::push(const Dish& d) {
    StackNode* newNode = new StackNode(d);
    newNode->next = topNode;
    topNode = newNode;
}

bool Stack::pop(Dish& d) {
    if (!topNode) {
        return false;
    }
    StackNode* temp = topNode;
    d = temp->dish;
    topNode = topNode->next;
    delete temp;
    return true;
}

StackNode* Stack::getTop() const {
    return topNode;
}

bool Stack::isEmpty() const {
    return topNode == nullptr;
}

void Stack::displayStack() const {
    StackNode* temp = topNode;
    int count = 1;
    while (temp) {
        cout << count << ". " << temp->dish.getName() 
             << " - $" << fixed << setprecision(2) << temp->dish.getPrice() << endl;
        temp = temp->next;
        count++;
    }
}

int Stack::getSize() const {
    int size = 0;
    StackNode* temp = topNode;
    while (temp) {
        size++;
        temp = temp->next;
    }
    return size;
}

bool Stack::removeByPosition(int pos, Dish& removedDish) {
    if (pos < 1 || pos > getSize() || !topNode) {
        return false;
    }
    if (pos == 1) {
        return pop(removedDish);
    }
    StackNode* temp = topNode;
    for (int i = 1; i < pos - 1; i++) {
        temp = temp->next;
    }
    StackNode* toRemove = temp->next;
    removedDish = toRemove->dish;
    temp->next = toRemove->next;
    delete toRemove;
    return true;
}

// Menu类实现
void Menu::addDish(const Dish& dish) {
    dishList.add(dish);
}

void Menu::initDefaultMenu() {
    addDish(Dish(1, "kabsa meat", 50, "Main Course"));
    addDish(Dish(2, "shawarma sandwich", 29, "Appetizer"));
    addDish(Dish(3, "Margherita Pizza", 45, "Main Course"));
    addDish(Dish(4, "Iced Tea", 12, "Drink"));
    addDish(Dish(5, "Tiramisu", 28.0, "Dessert"));
}

void Menu::displayMenu() const {
    dishList.display();
}

Dish* Menu::findDishById(int id) {
    Node* node = dishList.findById(id);
    if (node) {
        return &(node->dish);
    }
    return nullptr;
}