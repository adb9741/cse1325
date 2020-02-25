#include <string>
#include "product.h"
#include <iostream>
#include "taxed.h"

double Taxed::_tax = .0825;

Taxed::Taxed(std::string name, double cost) : Product::Product(name, cost) { }
Taxed::~Taxed() {}
void Taxed::set_tax_rate(double _tax){
    Taxed::_tax = _tax;
}

const double Taxed::price(){
    return (Taxed::_quantity * Taxed::_cost) * (1 + Taxed::_tax);
}

