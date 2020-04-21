#include "options.h"
#include <fstream>

Options::Options(std::string name, double cost) : _name{name}, _cost{cost} 
{

}

Options::Options(std::istream& ist)
{
    std::string __cost;
    getline(ist, _name);
    getline(ist, __cost);
    _cost = std::stod(__cost);
    
}

Options::~Options() 
{

}

double Options::cost() 
{
	return _cost;
}

std::string Options::to_string() const 
{
    return _name + " ($" + std::to_string(_cost) + ")";
}


std::ostream& operator<<(std::ostream& ost, const Options& options) 
{
    ost << options.to_string();
    return ost;
}

void Options::save(std::ostream& ost)
{
    ost << _name << std::endl << _cost << std::endl; 
}

