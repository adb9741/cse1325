#ifndef __ITEM_H
#define __ITEM_H

#include <vector>
#include <iostream>

class Item {
  public:
    Item(std::string name, double price);
    double cost();
    friend std::ostream& operator<<(std::ostream& ost, Item& Item);
    friend std::istream& operator>>(std::istream& ist, Item& Item);
  
  private:
    double _price;
    std::string _name;
};

#endif