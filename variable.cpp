#include <string>
#include "variable.h"
#include "number.h"
#include "atom.h"
using std::string;

Variable::Variable(string s):_symbol(s), _value("") {}

string Variable::value()
{ 
    return _value;
}

string Variable::symbol()
{ 
    return _symbol;
}

bool Variable::match(Number & num)
{
    bool ret = _assignable;
    if(_assignable)
    {
        _value = num.symbol();
        _assignable = false;
    }
    if(_value == num.symbol()) ret = true;
    return ret; 
}

bool Variable::match(Atom & atom)
{
    bool ret = _assignable;
    if(_assignable)
    {
        _value = atom.symbol();
        _assignable = false;
    }
    if(_value == atom.symbol()) ret = true;
    return ret;
}