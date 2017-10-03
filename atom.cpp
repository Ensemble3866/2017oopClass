#include <string>
#include "atom.h"
#include "number.h"
#include "variable.h"
using std::string;

Atom::Atom (string s):_symbol(s) {}

string Atom::symbol()
{
    return _symbol;
}

bool Atom::match(Variable var)
{
    return true;
}

bool Atom::operator =(Atom a)
{
    return _symbol == a.symbol();
}

bool Atom::operator =(Number num)
{
    return false;
}

bool Atom::operator =(Variable var)
{
    return var.match(*this);
}