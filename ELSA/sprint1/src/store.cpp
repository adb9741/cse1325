#include <string>
#include <vector>
#include "store.h"

void Store::add_customer(Customer& customer){

    customers.push_back(customer);

}

int Store::num_customers(){
    return customers.size();
}

Customer& Store::customer(int index){
    return customers.at(index);
}

void Store::add_option(Options& option){
    options.push_back(&option);
}

int Store::num_options(){
    int size = options.size();
    return size;
}

Options& Store::option(int index){
    return *options.at(index);
}

int Store::new_desktop(){
    
    desktops.push_back(Desktop{});
    return desktops.size() - 1;

}

void Store::add_option(int option, int desktop)
{
  Options opt = Store::option(option);
  Desktop desk = Store::desktop(desktop);
  desk.add_option(opt);
}

int Store::num_desktops(){
    return desktops.size();

}

Desktop& Store::desktop(int index){
    return desktops.at(index);
}

int Store::new_order(int customer){
    Order ord = Order{Store::customer(customer)};
    orders.push_back(ord);
    return orders.size() - 1;
}

void Store::add_desktop(int desktop, int order){
    Desktop desk = Desktop{desktops.at(desktop)};
    Order ord = Order{Store::order(order)};
    ord.add_product(desk);
}

int Store::num_orders(){
    return orders.size();
}

Order& Store::order(int index){
    return orders.at(index);
}



