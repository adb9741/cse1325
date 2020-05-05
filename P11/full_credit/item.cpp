#include "item.h"
#include <iomanip>
#include <string>


Item::Item(std::string name, double price): _name{name}, _price{price} {};


std::ostream& operator<<(std::ostream& ost, Item& item) {
    
    ost << "$     " << std::setprecision(2) << std::fixed << item._price << "  " << item._name << std::endl;
    return ost;
}

std::istream& operator>>(std::istream& ist, Item& item) {
    double _cost;
    std::string inp, name, cost;
    getline(ist, inp);

    int pos = inp.find_last_of(' ');
    name = inp.substr(0, pos);
    cost = inp.substr(pos);

    try{
        _cost = stod(cost);
    }
    catch(std::invalid_argument e){
        
        std::cerr << "Invalid price: '"<< name << "' ==> '" << cost << "'" << std::endl;
    }

    item._price = _cost;
    item._name = name;

}

double Item::cost(){
    return Item::_price;
}
