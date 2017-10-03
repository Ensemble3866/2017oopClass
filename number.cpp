#include <string>
#include "number.h"
using std::string;

Number::Number(string s) : _value(s)
{
    _symbol = "_" + _value;
}

string Number::symbol()
{
    return _symbol;
}

string Number::value()
{
    return _value;
}

bool Number::operator =(Number num)
{
    return _value == num.value();
}

bool Number::operator =(Atom a)
{
    return false;
}

bool Number::operator =(Variable var)
{
    return var.match(this);
}
 