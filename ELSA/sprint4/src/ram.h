#ifndef __RAM_H
#define __RAM_H

#include <string>
#include <ostream>
#include "options.h"

class Ram: public Options {
  public:
    Ram(std::string name, double cost, int gb);
    Ram(std::istream& ist);
    ~Ram();
    std::string to_string() const override;
    void save(std::ostream& ost) override;
  protected:
    int _gb;
};

#endif