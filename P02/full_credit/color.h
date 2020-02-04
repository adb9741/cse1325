#ifndef __COLOR_H
#define __COLOR_H

#include <string>

class Color {

    int _red;
    int _blue;
    int _green;

    public:
    Color(int r, int g, int b);
    std::string to_string();
    std::string colorize(std::string text);
};



#endif