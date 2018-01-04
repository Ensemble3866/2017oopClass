#ifndef LIST_H
#define LIST_H

#include "struct.h"
#include <vector>
#include <typeinfo>
#include <iostream>
using std::vector;
class Variable ;

class List : public Struct {
public:
  string symbol() const ;
  string value() const ;

public:

  List(): Struct(Atom("."), vector<Term *>()) { _init = true; }

  List (vector<Term *> const & elements): Struct(Atom("."), {elements[0], createTail(elements)}){
  }

  List(Term * head, Term* tail):Struct(Atom("."), { head, tail }) {

  }

  Term * head() const;
  Term * tail() const;

  Term * args(int index) {
    return _args[index];
  }

  int arity() const {
    return _args.size();
  }

  Iterator * createIterator();
private:
  Term* createTail(std::vector<Term*> const &args){
    Term* tail = new Atom("[]");
    for (int i = args.size() - 1; i > 0; i--) {
      tail = new List(args[i], tail);
    }
    return tail;
  }

  bool _init = false;
};

#endif
