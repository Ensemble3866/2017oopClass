#include <string>
#include "constant.h"
using std::string;

string Constant::symbol() const
{
    return _symbol;
}

string Constant::value() const
{
    return symbol();
}

bool Constant::match(Term & term)
{
    if(dynamic_cast<Constant *>(&term))  return symbol() == term.symbol();
    else return term.match(*this);
}