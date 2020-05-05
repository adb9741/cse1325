#include "item.h"
#include "cart.h"
#include <vector>

int main() {
    Item i = Item{"", 0};
    
    Cart cart = Cart{"Test"};

    while(!std::cin.eof()) {
        std::cin >> i;
        cart.add_item(i);
    }
    
    std::cout << "Register Receipt\n";
    for(std::vector<Item*>::iterator items = cart.begin(); items!=cart.end(); ++items){
        std::cout << **items;
    }

    double total = cart.cost();
    std::cout << "Total cost: $" << total << std::endl;
}