#include "desktop.h"
#include <vector>
#include <string>


std::ostream& operator<<(std::ostream& ost, const Desktop& desktop){

    for (int i = 0; i < desktop.options.size(); i++) {
        ost << *desktop.options.at(i);
    }
    return ost;
}

void Desktop::add_option(Options& option){

    options.push_back(&option);

}

double Desktop::price(){

    double price = 0;

    for(int i = 0; i < options.size(); i++){
        price += options.at(i)->cost();
    }

    return price;
}