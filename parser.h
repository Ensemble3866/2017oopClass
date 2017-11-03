#ifndef PARSER_H
#define PARSER_H
#include <string>

using std::string;

#include "atom.h"
#include "variable.h"
#include "global.h"
#include "scanner.h"
#include "struct.h"

class Parser{
public:
  Parser(Scanner scanner) : _scanner(scanner){}
  Term* createTerm()
  {
    int token = _scanner.nextToken();
    if(token == VAR)
    {
      return new Variable(symtable[_scanner.tokenValue()].first);
    }
    else if(token == NUMBER)
    {
      return new Number(_scanner.tokenValue());
    }
    else if(token == ATOM || token == ATOMSC)
    {
        Atom* atom = new Atom(symtable[_scanner.tokenValue()].first);
        if(_scanner.currentChar() == '(' ) 
        {
          _scanner.nextToken();
          vector<Term*> terms = getArgs();
          if(_currentToken == ')')
            return new Struct(*atom, terms);
        }
        else
          return atom;
    }
    else if(token == 91) //token == '['
    {
      vector<Term*> terms = getArgs();
      if(_currentToken == ')')
        throw string("unexpected token");
      return new List(terms);
    }
    return nullptr;
  }

  vector<Term*> getArgs()
  {
    vector<Term*> args;
    if((_currentToken = _scanner.currentChar()) == ']')
    {
      while((_currentToken = _scanner.nextToken()) == ',') 
      {
        args.push_back(createTerm());
      }
      return args;
    }
    Term* term = createTerm();
    if(term)
    {
      args.push_back(term);
      while((_currentToken = _scanner.nextToken()) == ',') 
      {
        args.push_back(createTerm());
      }
    }
    return args;
  }

private:
  Scanner _scanner;
  int _currentToken;
};
#endif