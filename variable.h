#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>
#include <vector>
#include "term.h"
using std::string;
using std::vector;

class Variable : public Term
{
  public:
    Variable(string s);
    string value() const;
    string symbol() const;
    bool match(Term & term);
    bool match(Variable & var);
    bool matched(Variable & var);

private:
    string _value;
    string _symbol;
    vector<Variable *> _vars;
    bool _assignable = true;
};

#endif
