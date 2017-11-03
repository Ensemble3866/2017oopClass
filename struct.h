#ifndef STRUCT_H
#define STRUCT_H

#include "atom.h"
#include <vector>
#include <string>

using std::string;

class Struct: public Term {
public:
  Struct(Atom name, std::vector<Term *> args): _name(name) {
    _args = args;
  }

  Atom & name() {
    return _name;
  }
  string symbol() const
  {
    string ret = _name.symbol() + "(";
    if(_args.size() > 0)
    {
        for(int i = 0; i < _args.size() - 1 ; i++) ret += _args[i]-> symbol() + ", ";
        ret += _args[_args.size()-1]-> symbol() + ")";
    }
    else ret += ")";
    return ret;
  }
  string value() const {

    string ret = _name.symbol() + "(";
    if(_args.size() > 0)
    {
        for(int i = 0; i < _args.size() - 1 ; i++) ret += _args[i]->value() + ", ";
        ret += _args[_args.size()-1]->value() + ")";
    }
    else ret += ")";
    return ret;
  }

  int arity() // return the number of args (terms)
  {
    return _args.size();
  }

  Term * args(int index) // according to index return the term
  {
    return _args[index];
  }

private:
  Atom _name;
  std::vector<Term *> _args;
};

#endif
