#include <string>
#include <algorithm>
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
        Variable* var = dynamic_cast<Variable *>(&term);
        if(var && (term.value() == term.symbol() || var->isValueEmptyVariable()))
        {
            _valueIsEmptyVariable = true;
        } 
    }
    else if(_valueIsEmptyVariable)
    {
        ret = _value->match(term);
        if(term.value() == term.symbol())
            _valueIsEmptyVariable = true;
        else
            _valueIsEmptyVariable = false;
    }
    return ret;
}

bool Variable::match(List & list)
{
    bool ret = true;
    if(!list.match(*this)) ret = false;
    else
    {
        _value = &list;
        _assignable = false;
    }
    return ret;

}

bool Variable::isValueEmptyVariable()
{
    return _valueIsEmptyVariable;
}