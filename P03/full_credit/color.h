#ifndef __COLOR_H
#define __COLOR_H

#include <string>

class Color {
  public:
    Color(int red, int green, int blue, bool reset);
    Color();
    std::string to_string();
    friend std::ostream& operator<<(std::ostream& ost, Color& color);
    friend std::istream& operator>>(std::istream& ist, Color& color);
   
  private:
    int _red;
    int _green;
    int _blue;
    bool _reset;
};

#endif
