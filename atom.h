#ifndef ATOM_H
#define ATOM_H

#include <string>
using std::string;

class Number;
class Variable;

class Atom {
    public:
        Atom (string s);
        string symbol();
        bool match(Variable var);
        bool operator =(Atom a);
        bool operator =(Number num);
        bool operator =(Variable var);
    private:
      string _symbol;
};

#endif