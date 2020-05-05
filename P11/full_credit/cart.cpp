#include <vector>
#include <iostream>
#include "item.h"
#include "cart.h"

Cart::Cart(std::string customer): _customer{customer} {};

Cart::~Cart() {
    for(int i = 0; i < items.size(); i++){
        delete items[i];
    }
}

Cart::Cart(const Cart& cart) {
    
    Cart* _cart = new Cart{cart};
}

Cart& Cart::operator=(const Cart& cart) {
    if(this==&cart)
        return *this;
    Cart* _cart = new Cart{cart};
    return *this;
}

void Cart::add_item(Item& item) { 
    items.push_back(new Item{item});
}

double Cart::cost() {
    double total;
    for(int i = 0; i < items.size(); i++){
        double tempdouble;
        tempdouble = items[i]->cost();
        total = total + tempdouble;
    }
    return total;
}