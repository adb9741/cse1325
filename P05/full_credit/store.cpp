#include <string>
#include "product.h"
#include <iostream>
#include "taxfree.h"
#include "taxed.h"

int main(){
    Taxfree Milk = Taxfree{"Milk", 2.00};
    Taxfree Grapes = Taxfree{"Grapes", 1.00};
    Taxfree Eggs = Taxfree{"Eggs", 2.50};
    Taxed Candy = Taxed{"Candy", 2.00};
    Taxed Beer = Taxed{"Beer", 4.00};
    Taxed Ice = Taxed{"Ice", 3.00};

    int index;
    int quantity;
    double total = 0;

    while(true){
        try {
            std::cout << "====================" << std::endl;
            std::cout << "Welcome to the Store" << std::endl;
            std::cout << "====================" << std::endl << std::endl;

            std::cout << Milk; 
            std::cout << Grapes; 
            std::cout << Eggs; 
            std::cout << Candy; 
            std::cout << Beer; 
            std::cout << Ice << std::endl; 

            std::cout << "Enter the quantity and the item index: ";
            std::cin >> index; 

            if (index == 0) {
                break;
            }

            std::cin >> quantity;

            if (index < 0 || index >= 7 || quantity < 0) {
                throw 1;
            }

            std::cout << std::endl << "Current Order" << std::endl << "----------" << std::endl;


            if (index > 0) {
                switch(index) {
                    case 1: {
                        Milk.set_quantity(quantity);
                        break;
                    }
                    case 2: {
                        Grapes.set_quantity(quantity);
                        break;
                    }
                    case 3: {
                        Eggs.set_quantity(quantity);
                        break;
                    }
                    case 4: {
                        Candy.set_quantity(quantity);
                        break;
                    }
                    case 5: {
                        Beer.set_quantity(quantity);
                        break;
                    }
                    case 6: {
                        Ice.set_quantity(quantity);
                        break;
                    }
                }
            }

            if (Milk.price() != 0) {
                std::cout << Milk;
            }
            
            if (Grapes.price() != 0) {
                std::cout << Grapes;
            }
            if (Eggs.price() != 0) {
                std::cout << Eggs;
            }
            if (Candy.price() != 0) {
                std::cout << Candy;
            }
            if (Beer.price() != 0) {
                std::cout << Beer;
            }
            if (Ice.price() != 0) {
                std::cout << Ice;
            }
            total = Milk.price() + Grapes.price() + Eggs.price() + Candy.price() + Beer.price() + Ice.price();
            std::cout << std::endl << "Total: $" << total << std::endl << std::endl;
        }
        catch(...) {
            std::cout << "Invalid input" << std::endl;
        }
        
    } 
        
}