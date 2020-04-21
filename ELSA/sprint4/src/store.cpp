#include "store.h"
#include <fstream>
#include <iostream>

Store::Store()
{
}

Store::Store(std::istream &ist)
{
    int _size;
    std::string size;

    getline(ist, size);
    _size = stoi(size);
    for (int i = 0; i < _size; i++)
    {
        Customer _c = Customer(ist);
        add_customer(_c);
    }

    getline(ist, size);
    _size = stoi(size);
    for (int i = 0; i < _size; i++)
    {
        int check = ist.peek();
        
        if(check != 236){
            Options _o = Options(ist);
            add_option(_o);
        }
        else{
            ist.get();
            Ram ram = Ram(ist);
            add_option(ram);
        }     
    }

    getline(ist, size);
    _size = stoi(size);

    for (int i = 0; i < _size; i++)
    {
        Desktop _d = Desktop(ist);
        desktops.push_back(_d);
    }

    getline(ist, size);
    _size = stoi(size);

    for (int i = 0; i < _size; i++)
    {
        orders.push_back(Order(ist));
    }
}

void Store::save(std::ostream &ost)
{
    ost << customers.size() << std::endl;
    for (int i = 0; i < customers.size(); i++)
    {
        customers.at(i).save(ost);
    }

    ost << options.size() << std::endl;
    for (int i = 0; i < options.size(); i++)
    {
        options.at(i)->save(ost);
    }

    ost << desktops.size() << std::endl;
    for (int i = 0; i < desktops.size(); i++)
    {
        desktops.at(i).save(ost);
    }

    ost << orders.size() << std::endl;
    for(int i = 0 ; i < orders.size(); i++){
        orders.at(i).save(ost);
    }
}


void Store::add_customer(Customer &customer) { customers.push_back(customer); }
int Store::num_customers() { return customers.size(); }
Customer &Store::customer(int index) { return customers.at(index); }

void Store::add_option(Options &option) { options.push_back(new Options{option}); }
void Store::add_option(Ram &option) { options.push_back(new Ram{option}); }
int Store::num_options() { return options.size(); }
Options &Store::option(int index) { return *options.at(index); }

int Store::new_desktop()
{
    desktops.push_back(Desktop{});
    return desktops.size() - 1;
}
void Store::add_option(int option, int desktop)
{ 
    desktops.at(desktop).add_option(*options.at(option));
}
int Store::num_desktops() { return desktops.size(); }
Desktop &Store::desktop(int index) { return desktops.at(index); }


int Store::new_order(int customer)
{
    orders.push_back(Order{customers.at(customer)});
    return orders.size() - 1;
}

void Store::add_desktop(int desktop, int order)
{ 
    orders.at(order).add_product(desktops.at(desktop));
}
int Store::num_orders() { return orders.size(); }
Order &Store::order(int index) { return orders.at(index); }
