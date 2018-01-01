#ifndef EXP_H
#define EXP_H

#include "atom.h"
#include "variable.h"
#include <iostream>

class Exp {
public:
  virtual bool evaluate() = 0;
  virtual string text() = 0;
};


class MatchExp : public Exp {
public:
  MatchExp(Term* left, Term* right): _left(left), _right(right), _result(true), _firstMatch(true){}

  bool evaluate(){
    if((_left->getVariable() && _left->getVariable()->symbol() == _left->getVariable()->value()) ||
     (_right->getVariable() && _right->getVariable()->symbol() == _right->getVariable()->value()))
      _firstMatch = true;
    else _firstMatch = false; 
    _result = _left->match(*_right);
    return _result;
  }

  string text(){
    if(_result){
      if((_left->getVariable() && _right->getVariable() && _left->getVariable()->value() == _right->getVariable()->value()) || !_firstMatch)
        return "true";
      else return _left->symbol() + " = " + _right->value();
    }
    else return "false";
  }

private:
  Term* _left;
  Term* _right;
  bool _result, _firstMatch;
};

class ConjExp : public Exp {
public:
  ConjExp(Exp *left, Exp *right) : _left(left), _right(right) {}

  bool evaluate() {
    _result = (_left->evaluate() && _right->evaluate());
    return _result;
  }

  string text(){
    if(_result){
      if(_right->text() == "true")
        return _left->text();
      else if(_left->text() == "true")
        return _right->text();
      else
        return _left->text() + ", " + _right->text();
    } 
    else return "false";
  }

private:
  Exp * _left;
  Exp * _right;
  bool _result;
};

class DisjExp : public Exp {
public:
  DisjExp(Exp *left, Exp *right) : _left(left), _right(right) {

  }

  bool evaluate() {
    _leftResult = _left->evaluate();
    _rightResult = _right->evaluate();
    _result = (_leftResult || _rightResult);
    return _result;
  }

  string text(){
    if(_leftResult && (!_rightResult || _right->text() == "true")) return _left->text();
    else if(!_leftResult && (_rightResult || _right->text() == "true")) return _right->text();
    return _left->text() + "; " + _right->text();
  }

private:
  Exp * _left;
  Exp * _right;
  bool _leftResult, _rightResult, _result;
};
#endif
