#ifndef CONSTANT_H
#define CONSTANT_H

#include <string>
#include "term.h"
using std::string;

class Constant : public Term
{
    public:
        string symbol() const;
        string value() const;
        bool match(Constant & constant);
        bool match(Term & term);
    protected:
        string _symbol;
};

#endif