#include <string>
#include <algorithm>
#include "variable.h"
using std::string;
using std::vector;

Variable::Variable(string s)
{
    _symbol = s;
    _value = s;
}

string Variable::value() const
{ 
    return _value;
}

string Variable::symbol() const
{ 
    return _symbol;
}

bool Variable::match(Term & term)
{
    bool ret = _assignable;
    if(_assignable)
    {
        _value = term.value();
        _assignable = false;
        for(int i = 0; i < _vars.size(); i++)
        {
            _vars[i]->match(term);
        }
    }
    if(_value == term.symbol()) ret = true;
    return ret;
}

bool Variable::match(Variable & var)
{
    bool ret = false;
    vector<Variable *>::iterator it; 
    it = find(_vars.begin(), _vars.end(), &var);

    if (it == _vars.end())
    {
        _vars.push_back(&var);
        _value = var.symbol();
        var.matched(*this);
        ret = true;
    }
    return ret;
}

bool Variable::matched(Variable & var)
{
    bool ret = false;
    vector<Variable *>::iterator it; 
    it = find(_vars.begin(), _vars.end(), &var);

    if (it == _vars.end())
    {
        _vars.push_back(&var);
        ret = true;
    }
    return ret;
}