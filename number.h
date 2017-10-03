#ifndef NUMBER_H
#define NUMBER_H

#include <string>
#include "atom.h"
#include "variable.h"
using std::string;

class Number
{
    public:
        Number (string s);
        string symbol();
        string value();
        bool operator =(Number num);
        bool operator =(Atom a);
        bool operator =(Variable var);

    private:
        string _symbol;
        string _value;
};

#endif
