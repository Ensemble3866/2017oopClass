#ifndef ITERATOR_H
#define ITERATOR_H

#include "term.h"
#include "struct.h"
#include "list.h"
#include <typeinfo>
#include <stack>
using std::stack;
#include <iostream>
using namespace std;

template <class T> 
class Iterator {
  public:
    virtual void first() = 0;
    virtual void next() = 0;
    virtual Term* currentItem() const = 0;
    virtual bool isDone() const = 0;
};

template <class T>
class DFSIterator : public Iterator<T> {
public:
    friend class Struct;
    friend class List;
    void first() {
      _index = 0;
    }

    void next() {
        _index++;
    }

    Term* currentItem() const {
      return _dfsIterator[_index];
    }

    bool isDone() const {
      return _index >= _dfsIterator.size();
    }

private:
    DFSIterator(T t): _index(0) {
      if(dynamic_cast<Struct *>(t)){
        Struct * s = dynamic_cast<Struct *>(t);
        for(int i = 0; i < s->arity(); i++){
          if(dynamic_cast<Struct *>(s->args(i))){
            Struct * sc = dynamic_cast<Struct *>(s->args(i));
            vector<Term *> r = GetStructElementsByDFS(sc);
            for(int j = 0; j < r.size(); j++)
              _dfsIterator.push_back(r[j]);
          }
          else if(dynamic_cast<List *>(s->args(i))){
            List * tc = dynamic_cast<List *>(s->args(i));
            vector<Term *> r = GetListElementsByDFS(tc);
            for(int j = 0; j < r.size(); j++)
              _dfsIterator.push_back(r[j]);
          }
          else _dfsIterator.push_back(s->args(i));
        }
      }
      else if(dynamic_cast<List *>(t)){
        List * l = dynamic_cast<List *>(t);
        for(int i = 0; i < l->arity(); i++){
          if(dynamic_cast<Struct *>(l->args(i))){
            Struct * lc = dynamic_cast<Struct *>(l->args(i));
            vector<Term *> r = GetStructElementsByDFS(lc);
            for(int j = 0; j < r.size(); j++)
              _dfsIterator.push_back(r[j]);
          }
          else if(dynamic_cast<List *>(l->args(i))){
            List * lc = dynamic_cast<List *>(l->args(i));
            vector<Term *> r = GetListElementsByDFS(lc);
            for(int j = 0; j < r.size(); j++)
              _dfsIterator.push_back(r[j]);
          }
          else _dfsIterator.push_back(l->args(i));
        }
      }
    }

    vector<Term *> GetStructElementsByDFS(Struct * s){
      vector<Term *> result;
      result.push_back(&s->name());
      for(int i = 0; i < s->arity(); i++)
      {
        if(dynamic_cast<Struct *>(s->args(i))){
          Struct * sc = dynamic_cast<Struct *>(s->args(i));
          vector<Term *> r = GetStructElementsByDFS(sc); 
          for(int j = 0; j < r.size(); j++)
            result.push_back(r[j]);
        }
        else if(dynamic_cast<List *>(s->args(i))){
          List * tc = dynamic_cast<List *>(s->args(i));
          vector<Term *> r = GetListElementsByDFS(tc); 
          for(int j = 0; j < r.size(); j++)
            result.push_back(r[j]);
        }
        else result.push_back(s->args(i));
      }
      return result;
    }

     vector<Term *> GetListElementsByDFS(List * t){
      vector<Term *> result;
      result.push_back(new Atom("[]"));
      for(int i = 0; i < t->arity(); i++)
      {
        if(dynamic_cast<List *>(t->args(i))){
          List * tc = dynamic_cast<List *>(t->args(i));
          vector<Term *> r = GetListElementsByDFS(tc); 
          for(int j = 0; j < r.size(); j++)
            result.push_back(r[j]);
        }
        else if(dynamic_cast<Struct *>(t->args(i))){
          Struct * tc = dynamic_cast<Struct *>(t->args(i));
          vector<Term *> r = GetStructElementsByDFS(tc); 
          for(int j = 0; j < r.size(); j++)
            result.push_back(r[j]);
        }
        else result.push_back(t->args(i));
      }
      return result;
    }
        
    int _index;
    vector<Term *> _dfsIterator;
};

template <class T>
class BFSIterator : public Iterator<T> {
public:
   friend class Struct;
   friend class List;
    void first() {
      _index = 0;
    }

    void next() {
      _index++;
    }

    Term* currentItem() const {
      return _bfsIterator[_index];
    }

    bool isDone() const {
      return _index >= _bfsIterator.size();
    }

private:
     BFSIterator(T t): _index(0) {
      vector<Term *> bfsQueue;
      if(dynamic_cast<Struct *>(t)){
        Struct * s = dynamic_cast<Struct *>(t);
        for(int i = 0; i < s->arity(); i++){
          if(dynamic_cast<Struct *>(s->args(i))){
            Struct * sc = dynamic_cast<Struct *>(s->args(i));
            bfsQueue.push_back(s->args(i));
            _bfsIterator.push_back(&sc->name());
          }
          else if(dynamic_cast<List *>(s->args(i))){
             bfsQueue.push_back(s->args(i));
             _bfsIterator.push_back(new Atom("[]"));
          }
          else _bfsIterator.push_back(s->args(i));
        }
      }
      else if(dynamic_cast<List *>(t)){
        List * l = dynamic_cast<List *>(t);
        for(int i = 0; i < l->arity(); i++){
          if(dynamic_cast<Struct *>(l->args(i))){
            Struct * sc = dynamic_cast<Struct *>(l->args(i));
            bfsQueue.push_back(l->args(i));
            _bfsIterator.push_back(&sc->name());
          }
          else if(dynamic_cast<List *>(l->args(i))){
             bfsQueue.push_back(l->args(i));
             _bfsIterator.push_back(new Atom("[]"));
          }
          else _bfsIterator.push_back(l->args(i));
        }
      }
      while(!bfsQueue.empty()){
        if(dynamic_cast<Struct *>(bfsQueue[0])){
          Struct * sc = dynamic_cast<Struct *>(bfsQueue[0]);
          for(int i = 0; i < sc->arity(); i++){
            if(dynamic_cast<Struct *>(sc->args(i))){
              Struct * scc = dynamic_cast<Struct *>(sc->args(i));
              bfsQueue.push_back(sc->args(i));
              _bfsIterator.push_back(&scc->name());
            }
            else if(dynamic_cast<List *>(sc->args(i))){
              bfsQueue.push_back(sc->args(i));
              _bfsIterator.push_back(new Atom("[]"));
            }
            else _bfsIterator.push_back(sc->args(i));
          }
        }
        else if(dynamic_cast<List *>(bfsQueue[0])){
            List * lc = dynamic_cast<List *>(bfsQueue[0]);
            for(int i = 0; i < lc->arity(); i++){
            if(dynamic_cast<Struct *>(lc->args(i))){
              Struct * sc = dynamic_cast<Struct *>(lc->args(i));
              bfsQueue.push_back(lc->args(i));
              _bfsIterator.push_back(&sc->name());
            }
            else if(dynamic_cast<List *>(lc->args(i))){
              bfsQueue.push_back(lc->args(i));
              _bfsIterator.push_back(new Atom("[]"));
            }
            else _bfsIterator.push_back(lc->args(i));
          }
        }
        bfsQueue.erase(bfsQueue.begin());
      }
    }
        
    int _index;
    vector<Term *> _bfsIterator;
};

template <class T> 
class NullIterator : public Iterator<T> {
  public:
    NullIterator(){}
    void first(){}
    void next(){}
    Term * currentItem() const{
        return nullptr;
    }
    bool isDone() const{
      return true;
    }
};

#endif
