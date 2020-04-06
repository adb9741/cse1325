#include "customer.h"
#include <fstream>

Customer::Customer(std::string name, std::string phone, std::string email)
    : _name{name}, _phone{phone}, _email{email} {}


Customer::Customer(std::istream& ist) 
{
    getline(ist, _name);
    getline(ist, _phone);
    getline(ist, _email);
}
    
std::ostream& operator<<(std::ostream& ost, const Customer& customer) {
    ost << customer._name << " (" << customer._phone << "," << customer._email << ")";
    return ost;
}

void Customer::save(std::ostream& ost){
    ost << _name << std::endl << _phone << std::endl << _email << std::endl;
}
