#include <string>
#include "product.h"
#include <iostream>
#include "taxfree.h"

Taxfree::Taxfree(std::string name, double cost) : Product::Product(name, cost) { }
Taxfree::~Taxfree() {}

const double Taxfree::price(){
    return (Taxfree::_quantity * Taxfree::_cost);
}