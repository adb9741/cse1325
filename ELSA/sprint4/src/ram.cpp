#include "ram.h"
#include <istream>


Ram::Ram(std::string name, double cost, int gb) : Options(name, cost), _gb{gb}
{

}

Ram::Ram(std::istream& ist): Options(ist)
{
    std::string __gb;
    getline(ist, __gb);

     _gb = std::stoi(__gb);
}

Ram::~Ram()
{

}

std::string Ram::to_string() const
{
    return _name + " " + std::to_string(_gb) + "GB" + " ($" + std::to_string(_cost) + ")";
}

void Ram::save(std::ostream& ost) 
{
    ost << (char)236;
    Options::save(ost);
    ost << _gb << std::endl;
}



