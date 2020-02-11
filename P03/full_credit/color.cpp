#include "color.h"
#include <iostream>
#include <string>
#include <sstream>

Color::Color(int red, int green, int blue, bool _reset) : _red{red}, _green{green}, _blue{blue} { }
Color::Color() : _reset{true} { }
std::string Color::to_string() {
    return "(" + std::to_string(_red)   + ","
               + std::to_string(_green) + ","
               + std::to_string(_blue)  + ")";
}

std::ostream& operator<<(std::ostream& ost, Color& color) {
    if (color._reset) {
        ost << "\033[0m";
    }
    ost << "\033[38;2;" << std::to_string(color._red) << ";" << std::to_string(color._green) << ";" << std::to_string(color._blue) << "m";
    
    return ost;
}

std::istream& operator>>(std::istream& ist, Color& color) {
    std::string _clr;
    std::stringstream ss;
    ist >> _clr;
    _clr.replace(_clr.find("("), 1, "");
    _clr.replace(_clr.find(")"), 1, "");
   
    std::stringstream s_stream(_clr); //create string stream from the string
    std::string _temp;
    getline(s_stream, _temp, ',');
    color._red = stoi(_temp);    
    getline(s_stream, _temp, ',');
    color._green = stoi(_temp);    
    getline(s_stream, _temp, ',');
    color._blue = stoi(_temp);

    return ist;

}
