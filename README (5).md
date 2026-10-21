# Restaurant Ordering System in C++

![C++](https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)
![Linked List](https://img.shields.io/badge/Singly_Linked_List-1F6FEB?style=for-the-badge)
![Stack](https://img.shields.io/badge/Stack-8250DF?style=for-the-badge)
![OOP](https://img.shields.io/badge/Object_Oriented-2EA44F?style=for-the-badge)

A console application for browsing a restaurant menu and building a customer order, written for a Data Structures course. Both the menu and the order are built on data structures implemented by hand with pointers, without STL containers.

## Features

- **Browse the menu** in a formatted table with ID, name, price, and category
- **Add a dish** to the order by its ID
- **Remove a dish** from the order by its position in the list
- **View the order** with every selected dish, the total price, and an order ID generated from the current date and time
- **Place the order** and exit, with a message when the order is empty
- **Input validation:** non-numeric input is rejected and asked again instead of crashing the program

## Data Structures

- **Singly linked list** stores the menu. Dishes are added at the tail, searched by ID, and printed by walking the list from the head.
- **Stack** (a linked list with push, pop, and removal by position) stores the order, so the most recently added dish is shown first (LIFO).

## Design

Three classes cooperate:

- **`Dish`:** one menu item with an ID, name, price, and category
- **`Menu`:** owns the linked list of dishes, loads the default menu, and finds a dish by ID
- **`Order`:** owns the stack of selected dishes, keeps the running total, and generates the order ID

## Example Session

Browsing the menu, adding two dishes, and viewing the order:

```
===== Restaurant Menu =====
ID      Name                Price     Category       
---------------------------------------------
1       kabsa meat          50.00     Main Course    
2       shawarma sandwich   29.00     Appetizer      
3       Margherita Pizza    45.00     Main Course    
4       Iced Tea            12.00     Drink          
5       Tiramisu            28.00     Dessert        

===== Order Details =====
Order ID: 2026102183956
Selected Dishes: 
- Iced Tea - $12.00
- kabsa meat - $50.00
---------------------------------
Total Price: $62.00
```

## Build and Run

```bash
g++ -std=c++11 -o restaurant main.cpp Dish.cpp Menu.cpp Order.cpp
./restaurant
```

On Windows the executable is `restaurant.exe`. The final screen clear uses the Windows `cls` command.

## Repository Structure

```
.
├── Dish.h / Dish.cpp     # Menu item
├── Menu.h / Menu.cpp     # Linked list, stack, and the Menu class
├── Order.h / Order.cpp   # Customer order
├── main.cpp              # Console menu and program loop
└── README.md
```

## Team Project

This was a team project of five students. My part was the menu module: the singly linked list and the `Menu` class that manages the dishes.

## Skills Demonstrated

C++ · Singly linked lists · Stacks · Pointers and dynamic memory · Object-oriented design · Input validation · Team collaboration

## Contributor

**Mohammed Al-Zubair**
[github.com/Mohammed-Alzubair](https://github.com/Mohammed-Alzubair)
