#ifndef MENU_H
#define MENU_H

#include "Dish.h"
#include <iostream>
#include <iomanip>

using namespace std;

// 链表节点结构
struct Node {
    Dish dish;
    Node* next;
    Node(const Dish& d);
};

// 链表类
class LinkedList {
public:
    Node* head;
    LinkedList();
    void add(const Dish& d);
    Node* findById(int id);
    void display() const;
};

// 栈节点结构
struct StackNode {
    Dish dish;
    StackNode* next;
    StackNode(const Dish& d);
};

// 栈类
class Stack {
private:
    StackNode* topNode;
public:
    Stack();
    void push(const Dish& d);
    bool pop(Dish& d);
    StackNode* getTop() const;
    bool isEmpty() const;
    void displayStack() const;
    int getSize() const;
    bool removeByPosition(int pos, Dish& removedDish);
};

// Menu类
class Menu {
private:
    LinkedList dishList;
public:
    void addDish(const Dish& dish);
    void initDefaultMenu();
    void displayMenu() const;
    Dish* findDishById(int id);
};

#endif