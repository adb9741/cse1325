#include "desktop.h"
#include <fstream>

Desktop::Desktop()
{

}

Desktop::Desktop(std::istream& ist)
{
    int numofoptions;
    std::string size;

    getline(ist, size);
    numofoptions = stoi(size);

    for(int i = 0; i < numofoptions; i++){
        Options* option = new Options(ist);
        options.push_back(option);
    }
    
}

void Desktop::add_option(Options& option) 
{
	options.push_back(&option);
}

double Desktop::price() 
{
    double p = 0.0;
    for(auto o : options) p+= o->cost();
    return p;
}

std::ostream& operator<<(std::ostream& ost, const Desktop& desktop) 
{
    ost << "Desktop includes";
    for(auto o : desktop.options) ost << "\n  " << *o;
    return ost;
}

void Desktop::save(std::ostream& ost)
{
    ost << options.size() << std::endl;
    for (int i = 0; i < options.size(); i++) {
        options.at(i)->save(ost);
    }
}
