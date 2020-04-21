#include "order.h"
#include <fstream>
#include <string>

Order::Order(Customer& customer) : _customer{&customer} 
{

}

Order::Order(std::istream& ist)
{
    _customer = new Customer(ist);
    
    int _size;
    std::string size;

    getline(ist, size);
    _size = stoi(size);

    for (int i = 0; i < _size; i++) {
        Desktop* d = new Desktop(ist);
        _products.push_back(d);
    }

}

Order::~Order() 
{

}

int Order::add_product(Desktop& desktop) 
{
	_products.push_back(&desktop); 
	return _products.size()-1;
}

double Order::price() const 
{
    double pr = 0;
    for(auto p : _products) pr += p->price();
    return pr;
}

std::ostream& operator<<(std::ostream& ost, const Order& order) 
{
    ost << "Customer: " << *order._customer;
    for(auto p : order._products) ost << "\n  " << *p << "\n  Price: $" << p->price() << "\n";
    ost << "\nTotal price: $" << order.price();
    return ost;
}

void Order::save(std::ostream& ost)
{
    _customer->save(ost);

    ost << _products.size() << std::endl;
    for(int i = 0; i < _products.size(); i++){
        _products.at(i)->save(ost);
    }

}

