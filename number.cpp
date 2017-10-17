#include <string>
#include <sstream>
#include "number.h"
using std::string;

Number::Number(int n)
{
    std::stringstream ss;
    ss << n;
    _symbol = ss.str();
}

Number::Number(double n)
{
    std::stringstream ss;
    ss << n;
    _symbol = ss.str();
}