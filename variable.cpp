#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
#include "variable.h"
using std::string;
using std::vector;

Variable::Variable(string s)
{
    _symbol = s;
    _value = this;
}

string Variable::value() const
{ 
    if(_assignable) return _value->symbol();
    else return _value->value();
}

string Variable::symbol() const
{ 
    return _symbol;
}

bool Variable::match(Term & term)
{
    bool ret = _assignable;

    if(_value->symbol() == term.symbol()) ret = true;
    else if(_assignable)
    {
        _value = &term;
        _assignable = false;
        if(dynamic_cast<Variable *>(&term) && term.value() == term.symbol())
        {
            _valueIsEmptyVariable = true;
        } 
    }
    else if(_valueIsEmptyVariable)
    {
        ret = _value->match(term);
        _valueIsEmptyVariable = false;
    }
    
    
    return ret;
}