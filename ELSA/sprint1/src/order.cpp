#include "order.h"
#include <vector>
#include <string>


Order::Order(Customer& customer) : _customer{customer} { }

std::ostream& operator<<(std::ostream& ost, const Order& order){

    ost << order._customer;
    return ost;
}

int Order::add_product(Desktop& desktop){

    _products.push_back(&desktop);
    int location = ((_products.size()) - 1);
    
    return location;
}

double Order::price(){

    int price = 0;
    for(int i = 0; i <  _products.size(); i++){
       price += _products.at(i)->price();
    }

    return price;
}

Order::~Order() {
    
}