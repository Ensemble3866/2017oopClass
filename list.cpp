#include <string>
#include "list.h"
#include "constant.h"
#include "variable.h"
using std::string;

string List::symbol() const
{
    string ret = "[";
    if(_elements.size() > 0)
    {
        for(int i = 0; i < _elements.size() - 1 ; i++) ret += _elements[i]-> symbol() + ", ";
        ret += _elements[_elements.size()-1]-> symbol() + "]";
    }
    else ret += "]";
    return  ret;
}

string List::value() const
{
    string ret = "[";
    if(_elements.size() > 0)
    {
        for(int i = 0; i < _elements.size() - 1 ; i++) ret += _elements[i]->value() + ", ";
        ret += _elements[_elements.size()-1]->value() + "]";
    }
    else ret += "]";
    return  ret;
}

bool List::match(Term & term)
{
    bool ret = true;

    if(dynamic_cast<Constant *>(&term))
        ret = false;
    else if(dynamic_cast<Variable *>(&term))
    {
        for(int i = 0; i < _elements.size(); i++)
        {
            if(term.symbol() == _elements[i]->symbol())
                ret = false;
        }
    }
    else if(dynamic_cast<List *>(&term))
    {
        List * l = dynamic_cast<List *>(&term);
        if(_elements.size() != l->length()) ret = false;
        else
        {
            for(int i = 0; i < _elements.size(); i++)
            {
                if(!_elements[i]->match(*(l->element(i))))
                {
                    ret = false;
                    break;
                }
            }
        }
    }
    return ret;
}

Term * List::head() const
{
    if(_elements.size() < 1)
    {
        string message = "Accessing head in an empty list";
        throw message;
    }
    return _elements[0];
}

List * List::tail() const
{
    if(_elements.size() < 1)
    {
        string message = "Accessing head in an empty list";
        throw message;
        
    }
    vector<Term *> terms = _elements;
    terms.erase(terms.begin());
    List * tails = new List(terms);
    return tails;
}

Term * List::element(int i)
{
    return _elements[i];
}

int List::length() const
{
    return _elements.size();
}