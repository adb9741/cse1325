#ifndef __ORDER_H
#define __ORDER_H

#include <string>
#include <vector>
#include "desktop.h"
#include "customer.h"

class Order {
  
  public:
    Order(Customer& customer);
    ~Order();
    int add_product(Desktop& desktop);
    double price();
    friend std::ostream& operator<<(std::ostream& ost, const Order& order);

  private:
    Customer& _customer;
    std::vector<Desktop*> _products; 
  
};

#endif
