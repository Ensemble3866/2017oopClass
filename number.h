#ifndef NUMBER_H
#define NUMBER_H

#include <string>
#include "atom.h"
#include "variable.h"
using std::string;

class Number
{
    public:
        Number (int n);
        string symbol();
        int value();
        bool match(Number num);
        bool match(Atom a);
        bool match(Variable * var);

    private:
        string _symbol;
        int _value;
};

#endif
