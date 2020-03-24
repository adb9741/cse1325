#include "options.h"
#include <iostream>
#include <string>


Options::Options(std::string name, double cost) : _name{name}, _cost{cost} { }

std::ostream& operator<<(std::ostream& ost, const Options& options){

    ost << options._name << ' ' << options._cost;
    return ost;
}

double Options::cost() {
    return Options::_cost;
}

Options::~Options() {

}