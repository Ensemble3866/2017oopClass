#include <string>
#include "number.h"
using std::string;

Number::Number(int n) : _value(n)
{
    _symbol = std::to_string(_value);
}

string Number::symbol()
{
    return _symbol;
}

int Number::value()
{
    return _value;
}

bool Number::match(Number num)
{
    return _value == num.value();
}

bool Number::match(Atom a)
{
    return false;
}

bool Number::match(Variable * var)
{
    return var->match(this);
}
/*
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
    return var.match(*this);
}
*/