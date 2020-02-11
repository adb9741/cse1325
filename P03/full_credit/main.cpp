#include "color.h"
#include <iostream>
#include <string>

int main() {
    Color purple = Color {135, 33, 237, false};
    Color darkred = Color {180, 20, 20, true};
    Color blue = Color {102, 242, 255, true};

    // std::cout << "\033[38;2;10;10;200m\033[0m";
    std::cout << purple << "Purple" << darkred << " Dark Red" << blue << " Blue\033[0m\n" << std::endl;

    std::cout << "Enter a color as (red, green,blue):";
    Color usercolor = Color {0,0,0, true};
    std::cin >> usercolor; 

    std::cout << usercolor << usercolor.to_string() << std::endl;
}