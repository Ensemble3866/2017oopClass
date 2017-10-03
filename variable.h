#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>
using std::string;

class Number;
class Atom;

class Variable
{
  public:
    Variable(string s);
    string value();
    string symbol();
    bool match(Atom atom);
    bool match(Number num);

private:
    string _value;
    string _symbol;
    bool _assignable = true;
};

#endif
