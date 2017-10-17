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

bool Constant::match(Constant & constant)
{
    return symbol() == constant.symbol();
}

bool Constant::match(Term & term)
{
    return term.match(*this);
}