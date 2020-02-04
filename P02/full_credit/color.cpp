#include "color.h"
#include <iostream>
#include <string>

Color::Color(int r, int g, int b) {
    Color::_red = r;
    Color::_green = g;
    Color::_blue = b;
}

std::string Color::to_string() {
    
    std::string ret = "(" + std::to_string(Color::_red) + "," + std::to_string(Color::_green) + "," + std::to_string(Color::_blue) + ")";
    return ret;
}      

std::string Color::colorize(std::string text){
    text = "\033[38;2;" + std::to_string(Color::_red) + ";" + std::to_string(Color::_green) + ";" + std::to_string(Color::_blue) +"m" + text + "\033[0m"; // Sets color to 0 red, 100 green, 177 blue
             
    return text;
}