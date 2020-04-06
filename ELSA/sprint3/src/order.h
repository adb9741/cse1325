#ifndef __ORDER_H
#define __ORDER_H

#include "customer.h"
#include "desktop.h"

class Order {
  public:
    Order(Customer& customer);
    Order(std::istream& ist);
    virtual ~Order();
    int add_product(Desktop& desktop);
    double price() const;
    void save(std::ostream& ost);
    friend std::ostream& operator<<(std::ostream& ost, const Order& order);
  private:
    Customer* _customer;
    std::vector<Desktop*> _products;
};

#endif
