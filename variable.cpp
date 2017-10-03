#include <string>
#include "variable.h"
#include "number.h"
#include "atom.h"
#include <iostream>
using std::string;

Variable::Variable(string s):_symbol(s){}

string Variable::value()
{ 
    return _value;
}

string Variable::symbol()
{ 
    return _symbol;
}

bool Variable::match(Atom * atom)
{
    bool ret = _assignable;
    if(_assignable)
    {
        _value = atom->symbol();
        _assignable = false;
    }
    return ret;
}

bool Variable::match(Number * num)
{
    bool ret = _assignable;
    if(_assignable)
    {
        _value = num->value();
        _assignable = false;
    }
    return ret; 
}