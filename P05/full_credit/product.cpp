#include "product.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

std::ostream& operator<<(std::ostream& ost, const Product& product) {

    if(product._quantity == 0){
        ost << product._name << " ($" << std::setprecision(2) << std::fixed << product._cost << ")" << std::endl;
    }
    else if(product._quantity > 0){
    
        ost << product._name << " (" << product._quantity << " @ $" << std::setprecision(2) << std::fixed << product._cost << ")" << std::endl;
    }
    return ost;
}

Product::Product(std::string name, double cost) : _name{name}, _cost{cost}, _quantity{0} { }
Product::~Product() {}
void Product::set_quantity(int quantity){
    Product::_quantity = quantity;
}

const double Product::price() {
    return Product::_quantity * Product::_cost;
}

/*Overload operator<< for Product, streaming out e.g., "Cheese ($0.99)" if _quantity is 0 or e.g.,
"Cheese (2 @ $0.99)" if quantity is positive. Always show 2 digits to the right of the decimal point for
money. Note that since Taxed and Taxfree are derived from this class, they will take advantage of this
overload as well! */

