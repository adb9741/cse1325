#ifndef __TAXED_H
#define __TAXED_H

#include <string>
#include "product.h"

class Taxed : public Product {
    private:
        static double _tax;
    public:
        Taxed(std::string name, double cost);
        virtual ~Taxed();
        static void set_tax_rate(double _tax);
        const double price() override;
};


#endif