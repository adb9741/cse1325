#ifndef __CART_H
#define __CART_H

#include <vector>
#include <iostream>
#include "item.h"

class Cart {
  public:
    Cart(std::string customer);
    ~Cart();
    Cart(const Cart& cart);
    Cart& operator=(const Cart& cart);
    void add_item(Item& item);
    double cost();
    std::vector<Item*>::iterator begin(){return items.begin();}
    std::vector<Item*>::iterator end(){return items.end();}
  private:
    std::string _customer;
    std::vector<Item*> items;

};

#endif