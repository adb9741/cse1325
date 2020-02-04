#include "color.h"
#include <iostream>

int main(){
    Color purple = Color {135, 33, 237};
    Color darkred = Color {180, 20, 20};
    Color blue = Color {102, 242, 255};

    std::cout << purple.colorize("Purple") << std::endl;
    std::cout << darkred.colorize("Dark Red") << std::endl;
    std::cout << blue.colorize("Blue") << std::endl;

    int r,g,b;

    std::cout << "Enter your red value: ";
    std::cin >> r;

    std::cout << "Enter your green value: ";
    std::cin >> g;

    std::cout << "Enter your blue value: ";
    std::cin >> b;

    Color color = Color{r,g,b};
    std::cout << color.colorize(color.to_string()) << std::endl;
}