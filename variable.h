#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>
#include <vector>
#include "term.h"
#include "list.h"
using std::string;
using std::vector;

class Variable : public Term
{
  public:
    Variable(string s);
    string value() const;
    string symbol() const;
    bool match(Term & term);
    bool match(List & list);
    bool isValueEmptyVariable();

private:
    Term * _value;
    string _symbol;
    bool _valueIsEmptyVariable = false;
    bool _assignable = true;
};

#endif
