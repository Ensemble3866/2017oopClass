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

bool Atom::match(Atom a)
{
    return _symbol == a.symbol();
}

bool Atom::match(Number num)
{
    return false;
}

bool Atom::match(Variable & var)
{
    return var.match(*this);
}