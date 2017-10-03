#include <string>
#include "number.h"
using std::string;

Number::Number(string s) : _symbol(s)
{
    _value = std::stoi(_symbol);
}

string Number::symbol()
{
    return _symbol;
}

int Number::value()
{
    return _value;
}

bool Number::operator =(Number num)
{
    return _value == num.value();
}

bool Number::operator =(Atom a)
{
    return _symbol == a.symbol();
}

bool Number::operator =(Variable var)
{
    return var.match(this);
}
 