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

string Number::value()
{
    return std::to_string(_value);
}

bool Number::match(Number num)
{
    return _value == std::stoi(num.value());
}

bool Number::match(Atom a)
{
    return false;
}

bool Number::match(Variable & var)
{
    return var.match(*this);
}