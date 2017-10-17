#ifndef NUMBER_H
#define NUMBER_H

#include <string>
#include "constant.h"
using std::string;

class Number : public Constant
{
    public:
        Number (int n);
        Number (double n);
};

#endif
